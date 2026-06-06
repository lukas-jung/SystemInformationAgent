#include "storageinfojsonparser.h"

#include "storageinfo.h"
#include <QJsonObject>

std::unique_ptr<sysinfoagent::SystemInfo> sysinfoagent::StorageInfoJsonParser::parseJson(
    const QJsonValue &json) const
{
    QJsonObject sJo = json.toObject();

    auto storageInfo = std::make_unique<StorageInfo>();
    for (QJsonObject::const_iterator it = sJo.begin(); it != sJo.end(); ++it) {
        QJsonObject dJo = it.value().toObject();

        storageInfo->addDriveState(it.key(),
                                   DriveState(dJo["deviceName"].toString(""),
                                              dJo["path"].toString(""),
                                              dJo["label"].toString(""),
                                              dJo["bytesTotal"].toString("-1").toLongLong(),
                                              dJo["bytesAvailable"].toString("-1").toLongLong()));
    }
    return storageInfo;
}

const std::u16string_view sysinfoagent::StorageInfoJsonParser::identifier() const
{
    return StorageInfo::identifier;
}
