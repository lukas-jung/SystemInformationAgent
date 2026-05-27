#ifndef STORAGEINFOREADER_H
#define STORAGEINFOREADER_H

#include "systeminfo.h"
#include "systeminforeader.h"

namespace sysinfoagent {

class StorageInfoReader : public SystemInfoReader
{
public:
    StorageInfoReader() = default;
    std::unique_ptr<SystemInfo> readInfo() override;
};

} // namespace sysinfoagent

#endif // STORAGEINFOREADER_H
