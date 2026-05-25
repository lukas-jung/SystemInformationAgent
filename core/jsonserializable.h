#ifndef JSONSERIALIZABLE_H
#define JSONSERIALIZABLE_H

#include <QJsonValue>

namespace core {

class JsonSerializable
{
public:
    virtual QJsonValue as_json() = 0;
    virtual ~JsonSerializable() = 0;
};

} // namespace core

#endif // JSONSERIALIZABLE_H
