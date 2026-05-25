#ifndef SYSTEMINFOSTATEREADER_H
#define SYSTEMINFOSTATEREADER_H

#include "core/jsonserializable.h"
#include <memory>

namespace sysinfoagent {

class SystemInfoStateReader
{
public:
    virtual std::unique_ptr<core::JsonSerializable> readState() = 0;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOSTATEREADER_H
