#ifndef SYSTEMINFOSTATEREADER_H
#define SYSTEMINFOSTATEREADER_H

#include "readout.h"
#include <memory>

namespace sysinfoagent {

class SystemInfoReader
{
public:
    virtual std::unique_ptr<SystemInfo> readInfo() = 0;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOSTATEREADER_H
