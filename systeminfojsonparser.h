#ifndef SYSTEMINFOJSONPARSER_H
#define SYSTEMINFOJSONPARSER_H

#include "systeminfo.h"
#include <memory>
#include <QJsonValue>

namespace sysinfoagent {

class SystemInfoJsonParser
{
public:
    virtual const std::string_view identifier() = 0;
    virtual std::unique_ptr<SystemInfo> parseJson(const QJsonValue &json) = 0;

    ~SystemInfoJsonParser() = default;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOJSONPARSER_H
