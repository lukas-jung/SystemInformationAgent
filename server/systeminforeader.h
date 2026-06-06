#ifndef SYSTEMINFOREADER_H
#define SYSTEMINFOREADER_H

#include "systeminfo.h"
#include <memory>
#include <string_view>

namespace sysinfoagent {

class SystemInfoReader
{
public:
    virtual const std::u16string_view identifier() = 0;
    virtual std::unique_ptr<SystemInfo> readInfo() = 0;
    virtual ~SystemInfoReader() = default;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOREADER_H
