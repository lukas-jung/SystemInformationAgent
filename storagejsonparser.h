#ifndef STORAGEINFOJSONPARSER_H
#define STORAGEINFOJSONPARSER_H

#include "storageinfo.h"
#include "systeminfojsonparser.h"
#include <memory>
#include <QJsonObject>
#include <QJsonValue>

namespace sysinfoagent {

class StorageInfoJsonParser : public sysinfoagent::SystemInfoJsonParser
{
public:
    const std::string_view identifier() override { return StorageInfo::identifier; };
    std::unique_ptr<SystemInfo> parseJson(const QJsonValue &json) override
    {
        return std::make_unique<StorageInfo>(json.toObject());
    };
};

} // namespace sysinfoagent

#endif // STORAGEINFOJSONPARSER_H
