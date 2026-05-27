#ifndef SYSTEMINFOREADER_H
#define SYSTEMINFOREADER_H

#include "systeminfo.h"
#include <memory>

namespace sysinfoagent {

class SystemInfoReader
{
public:
    virtual std::unique_ptr<SystemInfo> readInfo() = 0;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOREADER_H
