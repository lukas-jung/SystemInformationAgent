#ifndef STORAGESTATEREADER_H
#define STORAGESTATEREADER_H

#include "readout.h"
#include "systeminfostatereader.h"

namespace sysinfoagent {

class StorageInfoReader : public SystemInfoReader
{
public:
    StorageInfoReader() = default;
    std::unique_ptr<SystemInfo> readInfo() override;
};

} // namespace sysinfoagent

#endif // STORAGESTATEREADER_H
