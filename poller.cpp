#include "poller.h"

namespace sysinfoagent {

Poller::Poller(QObject *parent)
    : QObject{parent}
    , timer_(new QTimer(this))
{
    connect(timer_, &QTimer::timeout, this, &Poller::pollInfoReaders);
}

void Poller::registerInfoReader(std::unique_ptr<SystemInfoReader> infoReader)
{
    auto identifier = infoReader->identifier();
    infoReaders_.emplace(QString(identifier), std::move(infoReader));
}

void Poller::startPollingEveryNSeconds(std::chrono::seconds n)
{
    timer_->start(n);
}

void Poller::pollInfoReaders()
{
    std::shared_ptr<Message> msg = std::make_unique<Message>();

    for (auto it = infoReaders_.cbegin(); it != infoReaders_.cend(); ++it) {
        const std::pair<const QString, std::unique_ptr<SystemInfoReader>> &e = *it;
        msg->addSysInfo(e.first, e.second->readInfo());
    }

    msg->setTimeStamp(QDateTime::currentDateTime());

    emit messageGenerated(std::move(msg));
}

} // namespace sysinfoagent
