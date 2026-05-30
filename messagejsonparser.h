#ifndef MESSAGEJSONPARSER_H
#define MESSAGEJSONPARSER_H

#include "message.h"
#include "systeminfojsonparser.h"
#include <memory>
#include <string_view>
#include <QJsonValue>

namespace sysinfoagent {

class MessageJsonParser
{
public:
    MessageJsonParser();

    std::unique_ptr<Message> parseJson(const QJsonValue &json);

    void registerInfoParser(std::unique_ptr<SystemInfoJsonParser> parser);

private:
    std::map<std::u16string_view, std::unique_ptr<const SystemInfoJsonParser>> infoParsers_;
};

} // namespace sysinfoagent

#endif // MESSAGEJSONPARSER_H
