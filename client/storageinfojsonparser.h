#ifndef STORAGEINFOJSONPARSER_H
#define STORAGEINFOJSONPARSER_H

#include "systeminfojsonparser.h"
#include <memory>
#include <QJsonValue>

namespace sysinfoagent {

class StorageInfoJsonParser : public sysinfoagent::SystemInfoJsonParser
{
public:
    const std::u16string_view identifier() const override;
    std::unique_ptr<SystemInfo> parseJson(const QJsonValue &json) const override;
};

} // namespace sysinfoagent

#endif // STORAGEINFOJSONPARSER_H
