#ifndef POLLER_H
#define POLLER_H

#include "message.h"
#include "systeminforeader.h"
#include <chrono>
#include <map>
#include <memory>
#include <QObject>
#include <QTimer>

namespace sysinfoagent {

class Poller : public QObject
{
    Q_OBJECT
public:
    explicit Poller(QObject *parent = nullptr);

    void registerInfoReader(std::unique_ptr<SystemInfoReader> infoReader);
    void startPollingEveryNSeconds(std::chrono::seconds n);

signals:
    void messageGenerated(std::shared_ptr<sysinfoagent::Message> msg);

private:
    std::map<const QString, std::unique_ptr<SystemInfoReader>> infoReaders_;
    QTimer *timer_;
private slots:
    void pollInfoReaders();
};

} // namespace sysinfoagent

#endif // POLLER_H
