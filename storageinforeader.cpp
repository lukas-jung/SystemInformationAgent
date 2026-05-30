#include "storageinforeader.h"
#include "storageinfo.h"

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

const std::u16string_view StorageInfoReader::identifier()
{
    return StorageInfo::identifier;
}

std::unique_ptr<SystemInfo> StorageInfoReader::readInfo()
{
    // QStorageInfo contains information about one drive. StorageInfo contains information about all drives!

    const QList<QStorageInfo> qStorageInfos = QStorageInfo::mountedVolumes();

    auto storageInfo = std::make_unique<StorageInfo>();
    for (const QStorageInfo &qSInfo : qStorageInfos) {
        const QString deviceIdString = qSInfo.device().toBase64();

        storageInfo->addDriveState(deviceIdString,
                                   DriveState(getDeviceName(qSInfo),
                                              qSInfo.rootPath(),
                                              qSInfo.name(),
                                              qSInfo.bytesTotal(),
                                              qSInfo.bytesAvailable()));
    }

    return storageInfo;
}

} // namespace sysinfoagent
