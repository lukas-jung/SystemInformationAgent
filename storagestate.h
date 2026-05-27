#ifndef STORAGESTATE_H
#define STORAGESTATE_H

#include "core/jsonserializable.h"
#include "readout.h"

namespace sysinfoagent {

class DriveState : public core::JsonSerializable
{
public:
    DriveState(QString deviceName, QString path, QString label, qint64 bytesTotal, qint64 bytesAvailable);
    explicit DriveState(const QJsonObject &jo);

    ~DriveState() override = default;
    QJsonValue asJson() override;

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
    explicit StorageInfo(const std::map<QString, DriveState> &drives);
    explicit StorageInfo(std::map<QString, DriveState> &&drives);
    explicit StorageInfo(const QJsonObject &jo);
    ~StorageInfo() override = default;
    QJsonValue asJson() override;

private:
    std::map<QString, DriveState> drives_;
};

} // namespace sysinfoagent

#endif // STORAGESTATE_H
