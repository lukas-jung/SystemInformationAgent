#ifndef SYSTEMINFORMATIONSERVICE_H
#define SYSTEMINFORMATIONSERVICE_H

#include "message.h"
#include "poller.h"
#include "rep_systeminformationservice_source.h"
#include <memory>
#include <QJsonValue>
#include <QObject>

namespace sysinfoagent {

class SystemInformationService : public SystemInformationServiceSource
{
    Q_OBJECT
public:
    explicit SystemInformationService(Poller &poller, QObject *parent = nullptr);

private:
    Poller &poller_;

private slots:
    void sendMessageAsJson(std::shared_ptr<sysinfoagent::Message> msg);
};

} // namespace sysinfoagent

#endif // SYSTEMINFORMATIONSERVICE_H
