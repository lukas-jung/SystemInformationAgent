#ifndef MESSAGE_H
#define MESSAGE_H

#include "core/jsonserializable.h"
#include "systeminfo.h"
#include <map>
#include <memory>
#include <QDateTime>
#include <QString>

namespace sysinfoagent {

class Message : core::JsonSerializable
{
public:
    Message();
    Message(std::map<const QString, std::unique_ptr<SystemInfo>> &&sysInfos);
    void addSysInfo(const QString &identifier, std::unique_ptr<SystemInfo> sysInfo);

    QJsonValue asJson() const override;

    void setTimeStamp(QDateTime timestamp) { timestamp_ = timestamp; }
    QDateTime timestamp() { return timestamp_; }

private:
    QDateTime timestamp_;
    std::map<const QString, std::unique_ptr<SystemInfo>> sysInfos_;
};

} // namespace sysinfoagent

#endif // MESSAGE_H
