#ifndef STORAGEINFO_H
#define STORAGEINFO_H

#include "core/jsonserializable.h"
#include "systeminfo.h"
#include <map>

namespace sysinfoagent {

class DriveState : public core::JsonSerializable
{
public:
    DriveState(const QString &deviceName,
               const QString &path,
               const QString &label,
               qint64 bytesTotal,
               qint64 bytesAvailable)
        : deviceName_(deviceName)
        , path_(path)
        , label_(label)
        , bytesTotal_(bytesTotal)
        , bytesAvailable_(bytesAvailable)
    {}

    ~DriveState() override = default;
    QJsonValue asJson() const override;

private:
    QString deviceName_;
    QString path_;
    QString label_;
    qint64 bytesTotal_;
    qint64 bytesAvailable_;
};

class StorageInfo : public SystemInfo
{
public:
    StorageInfo() {}
    ~StorageInfo() override = default;

    void addDriveState(const QString &driveId, const DriveState &driveState);

    QJsonValue asJson() const override;

    static constexpr std::u16string_view identifier = u"storage";

private:
    std::map<QString, DriveState> drives_;
};

} // namespace sysinfoagent

#endif // STORAGEINFO_H
