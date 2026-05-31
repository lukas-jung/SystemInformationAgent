#include "storageinfo.h"

#include <utility>
#include <QJsonObject>

namespace sysinfoagent {

QJsonValue DriveState::asJson() const
{
    // bytesTotal and bytesAvailable are strings because json only has 64-bit floats which can't safely store sizes over ~8000TiB

    return QJsonValue(QJsonObject{
        std::make_pair("deviceName", deviceName_),
        std::make_pair("path", path_),
        std::make_pair("label", label_),
        std::make_pair("bytesTotal", QString::number(bytesTotal_)),
        std::make_pair("bytesAvailable", QString::number(bytesAvailable_)),
    });
}

void StorageInfo::addDriveState(const QString &driveId, const DriveState &driveState)
{
    drives_.emplace(driveId, driveState);
}

QJsonValue StorageInfo::asJson() const
{
    QJsonObject jo;
    for (auto &p : drives_) {
        jo.insert(p.first, p.second.asJson());
    }

    return jo;
}
} // namespace sysinfoagent
