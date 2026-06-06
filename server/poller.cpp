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
    infoReaders_.push_back(std::move(infoReader));
}

void Poller::startPollingEveryNSeconds(std::chrono::seconds n)
{
    timer_->start(n);
}

void Poller::pollInfoReaders()
{
    std::shared_ptr<Message> msg = std::make_unique<Message>();

    for (auto it = infoReaders_.cbegin(); it != infoReaders_.cend(); ++it) {
        const std::unique_ptr<SystemInfoReader> &r = *it;
        msg->addSysInfo(r->identifier(), r->readInfo());
    }

    msg->setTimeStamp(QDateTime::currentDateTime());

    emit messageGenerated(std::move(msg));
}

} // namespace sysinfoagent
