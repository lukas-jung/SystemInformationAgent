#include "storageinfo.h"

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

DriveState::DriveState(const QJsonObject &jo)
    : deviceName_(jo["deviceName"].toString(""))
    , path_(jo["path"].toString(""))
    , label_(jo["label"].toString(""))
    , bytesTotal_(jo["bytesTotal"].toString("-1").toLongLong())
    , bytesAvailable_(jo["bytesAvailable"].toString("-1").toLongLong())
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

StorageInfo::StorageInfo(const std::map<QString, DriveState> &drives)
    : drives_(drives)
{}

StorageInfo::StorageInfo(std::map<QString, DriveState> &&drives)
    : drives_(std::move(drives))
{}

StorageInfo::StorageInfo(const QJsonObject &jo)
{
    for (QJsonObject::const_iterator it = jo.begin(); it != jo.end(); ++it) {
        drives_.emplace(std::make_pair(it.key(), DriveState(it.value().toObject())));
    }
}

QJsonValue StorageInfo::asJson()
{
    QJsonObject jo;
    for (auto &p : drives_) {
        jo.insert(p.first, p.second.asJson());
    }

    return jo;
}
} // namespace sysinfoagent
