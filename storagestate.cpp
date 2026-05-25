#include "storagestate.h"

#include <utility>
#include <QJsonObject>

namespace sysinfoagent {

DriveState::DriveState(
    QString deviceName, QString path, QString label, qint64 bytesTotal, qint64 bytesAvailable)
    : deviceName_(deviceName)
    , path_(path)
    , label_(label)
    , bytesTotal_(bytesTotal)
    , bytesAvailable_(bytesAvailable)
{}

QJsonValue DriveState::asJson()
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

StorageState::StorageState(const std::map<QByteArray, DriveState> &drives)
    : drives_(drives)
{}

StorageState::StorageState(std::map<QByteArray, DriveState> &&drives)
    : drives_(std::move(drives))
{}

QJsonValue StorageState::asJson()
{
    QJsonObject jo;
    for (auto &p : drives_) {
        jo.insert(p.first, p.second.asJson());
    }

    return jo;
}
} // namespace sysinfoagent
