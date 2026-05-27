#ifndef STORAGESTATEREADER_H
#define STORAGESTATEREADER_H

#include "readout.h"
#include "systeminfostatereader.h"

namespace sysinfoagent {

class StorageStateReader : public SystemInfoStateReader
{
public:
    StorageStateReader() = default;
    std::unique_ptr<Readout> readState() override;
};

} // namespace sysinfoagent

#endif // STORAGESTATEREADER_H
