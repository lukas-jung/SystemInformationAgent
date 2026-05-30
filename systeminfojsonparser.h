#ifndef SYSTEMINFOJSONPARSER_H
#define SYSTEMINFOJSONPARSER_H

#include "systeminfo.h"
#include <memory>
#include <QJsonValue>

namespace sysinfoagent {

class SystemInfoJsonParser
{
public:
    virtual const std::u16string_view identifier() const = 0;
    virtual std::unique_ptr<SystemInfo> parseJson(const QJsonValue &json) const = 0;

    virtual ~SystemInfoJsonParser() = default;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOJSONPARSER_H
