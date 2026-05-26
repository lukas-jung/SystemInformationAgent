#ifndef STORAGESTATE_H
#define STORAGESTATE_H

#include "core/jsonserializable.h"

namespace sysinfoagent {

class DriveState : public core::JsonSerializable
{
public:
    DriveState(
        QString deviceName, QString path, QString label, qint64 bytesTotal, qint64 bytesAvailable);

    ~DriveState() override = default;
    QJsonValue asJson() override;

private:
    QString deviceName_;
    QString path_;
    QString label_;
    qint64 bytesTotal_;
    qint64 bytesAvailable_;
};

class StorageState : public core::JsonSerializable
{
public:
    explicit StorageState(const std::map<QString, DriveState> &drives);
    explicit StorageState(std::map<QString, DriveState> &&drives);
    ~StorageState() override = default;
    QJsonValue asJson() override;

private:
    std::map<QString, DriveState> drives_;
};

} // namespace sysinfoagent

#endif // STORAGESTATE_H
