#include "message.h"
#include <QJsonObject>

namespace sysinfoagent {

Message::Message() {}

void Message::addSysInfo(const QString &identifier, std::unique_ptr<SystemInfo> sysInfo)
{
    sysInfos_.emplace(identifier, std::move(sysInfo));
}

QJsonValue Message::asJson() const
{
    QJsonObject sysInfosJo;
    for (auto it = sysInfos_.cbegin(); it != sysInfos_.cend(); ++it) {
        sysInfosJo[it->first] = it->second->asJson();
    }

    QJsonObject msgJo;
    msgJo["timestamp"] = timestamp_.toString(Qt::ISODateWithMs);
    msgJo["systemInfos"] = sysInfosJo;

    return msgJo;
}

} // namespace sysinfoagent
