#include "systeminformationservice.h"

namespace sysinfoagent {

SystemInformationService::SystemInformationService(Poller &poller, QObject *parent)
    : poller_(poller)
{
    connect(&poller_, &Poller::messageGenerated, this, &SystemInformationService::sendMessageAsJson);
}

void SystemInformationService::sendMessageAsJson(std::shared_ptr<Message> msg)
{
    emit messageJsonGenerated(msg->asJson());
}

} // namespace sysinfoagent
