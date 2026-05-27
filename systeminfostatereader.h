#ifndef SYSTEMINFOSTATEREADER_H
#define SYSTEMINFOSTATEREADER_H

#include "readout.h"
#include <memory>

namespace sysinfoagent {

class SystemInfoStateReader
{
public:
    virtual std::unique_ptr<Readout> readState() = 0;
};

} // namespace sysinfoagent

#endif // SYSTEMINFOSTATEREADER_H
