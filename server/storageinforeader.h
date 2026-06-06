#ifndef STORAGEINFOREADER_H
#define STORAGEINFOREADER_H

#include "systeminfo.h"
#include "systeminforeader.h"

namespace sysinfoagent {

class StorageInfoReader : public SystemInfoReader
{
public:
    StorageInfoReader() = default;
    const std::u16string_view identifier() override;
    std::unique_ptr<SystemInfo> readInfo() override;
};

} // namespace sysinfoagent

#endif // STORAGEINFOREADER_H
