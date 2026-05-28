#ifndef JSONSERIALIZABLE_H
#define JSONSERIALIZABLE_H

#include <QJsonValue>

namespace core {

class JsonSerializable
{
public:
    virtual QJsonValue asJson() const = 0;
    virtual ~JsonSerializable() = default;
};

} // namespace core

#endif // JSONSERIALIZABLE_H
