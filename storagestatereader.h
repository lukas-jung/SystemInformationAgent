#ifndef STORAGESTATEREADER_H
#define STORAGESTATEREADER_H

#include "systeminfostatereader.h"
#include <QStorageInfo>

namespace sysinfoagent {

class StorageStateReader : public SystemInfoStateReader
{
public:
    StorageStateReader() = default;
    std::unique_ptr<core::JsonSerializable> readState() override;
};

} // namespace sysinfoagent

#endif // STORAGESTATEREADER_H
