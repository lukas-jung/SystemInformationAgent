#include "storagestatereader.h"
#include "storagestate.h"

#include <QStorageInfo>
#include <QtSystemDetection>

namespace {

#if defined(Q_OS_WIN)
constexpr bool isUnixoid = false;
#elif defined(Q_OS_LINUX) || defined(Q_OS_MACOS)
constexpr bool isUnixoid = true;
#endif

QString getDeviceName(const QStorageInfo &sInfo)
{
    if (isUnixoid) {
        return QString(sInfo.device());
    } else {
        return sInfo.rootPath();
    }
}

} // namespace

namespace sysinfoagent {

std::unique_ptr<Readout> StorageStateReader::readState()
{
    const QList<QStorageInfo> storageInfos = QStorageInfo::mountedVolumes();
    std::map<QString, DriveState> drives;
    for (const QStorageInfo &sInfo : storageInfos) {
        const QString deviceIdString = sInfo.device().toBase64();

        drives.emplace(std::make_pair(deviceIdString,
                                      DriveState(getDeviceName(sInfo),
                                                 sInfo.rootPath(),
                                                 sInfo.name(),
                                                 sInfo.bytesTotal(),
                                                 sInfo.bytesAvailable())));
    }

    return std::make_unique<StorageState>(std::move(drives));
}

} // namespace sysinfoagent
