#ifndef MESSAGE_H
#define MESSAGE_H

#include "jsonserializable.h"
#include "systeminfo.h"
#include <map>
#include <memory>
#include <string_view>
#include <QDateTime>

namespace sysinfoagent {

class Message : core::JsonSerializable
{
public:
    Message();
    void addSysInfo(const std::u16string_view &identifier, std::unique_ptr<SystemInfo> sysInfo);

    void setTimeStamp(QDateTime timestamp) { timestamp_ = timestamp; }
    QDateTime timestamp() const { return timestamp_; }

    QJsonValue asJson() const override;

private:
    QDateTime timestamp_;
    std::map<const std::u16string_view, std::unique_ptr<SystemInfo>> sysInfos_;
};

} // namespace sysinfoagent

#endif // MESSAGE_H
