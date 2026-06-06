#include "messagejsonparser.h"

#include <QJsonObject>
#include <QTimeZone>

namespace sysinfoagent {

MessageJsonParser::MessageJsonParser() {}

std::unique_ptr<Message> MessageJsonParser::parseJson(const QJsonValue &json)
{
    auto msgJo = json.toObject();
    auto msg = std::make_unique<Message>();

    QString tsString = msgJo["timestamp"].toString("");
    QDateTime ts = QDateTime::fromString(tsString, Qt::ISODateWithMs);
    if (!ts.isValid()) {
        ts = QDateTime::fromMSecsSinceEpoch(0, QTimeZone::UTC);
    }
    msg->setTimeStamp(ts);

    const QJsonObject infosJo = msgJo["systemInfos"].toObject();
    for (auto it = infosJo.constBegin(); it != infosJo.constEnd(); ++it) {
        try {
            auto &parser = infoParsers_.at(it.key());
            msg->addSysInfo(parser->identifier(), parser->parseJson(it.value()));
        } catch (const std::out_of_range &_) {
            continue;
        }
    }

    return std::move(msg);
}

void MessageJsonParser::registerInfoParser(std::unique_ptr<SystemInfoJsonParser> parser)
{
    infoParsers_.emplace(parser->identifier(), std::move(parser));
}

} // namespace sysinfoagent
