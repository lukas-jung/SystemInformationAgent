#ifndef JSONSERIALIZABLE_H
#define JSONSERIALIZABLE_H

#include <variant>
#include <QJsonArray>
#include <QJsonObject>

namespace core {

class JsonSerializable
{
public:
    virtual std::variant<QJsonObject, QJsonArray> as_json() = 0;
    virtual ~JsonSerializable() = 0;
};

} // namespace core

#endif // JSONSERIALIZABLE_H
