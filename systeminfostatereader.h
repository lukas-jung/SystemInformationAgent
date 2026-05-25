#ifndef SYSTEMINFOSTATEREADER_H
#define SYSTEMINFOSTATEREADER_H

#include "core/jsonserializable.h"

namespace sysinfoagent {

class SystemInfoStateReader
{
public:
    virtual core::JsonSerializable readState() = 0;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOSTATEREADER_H
