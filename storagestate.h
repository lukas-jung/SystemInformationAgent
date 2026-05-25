#ifndef STORAGESTATE_H
#define STORAGESTATE_H

#include "core/jsonserializable.h"

namespace sysinfoagent {

class StorageState : public core::JsonSerializable
{
public:
    StorageState();
};

} // namespace sysinfoagent

#endif // STORAGESTATE_H
