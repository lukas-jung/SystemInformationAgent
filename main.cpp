#include "message.h"
#include "poller.h"
#include "storageinfo.h"
#include "storageinforeader.h"
#include <iostream>
#include <QCoreApplication>
#include <QJsonObject>

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call QCoreApplication::quit() or QCoreApplication::exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to QCoreApplication::exec() or use the Non-Qt Plain C++ Application template.

    {
        sysinfoagent::StorageInfoReader reader{};
        auto info1 = reader.readInfo();

        auto jv1 = info1->asJson();
        auto js1 = jv1.toJson().toStdString();
        std::cout << js1 << std::endl;

        auto jvp = QJsonValue::fromJson(js1);
        sysinfoagent::StorageInfo info2(jvp.toObject());

        auto jv2 = info2.asJson();
        auto js2 = jv2.toJson().toStdString();
        std::cout << js2 << std::endl;

        std::cout << (js1 == js2);
    }

    auto reader = std::make_unique<sysinfoagent::StorageInfoReader>();

    sysinfoagent::Poller poller(nullptr);
    poller.registerInfoReader(std::move(reader));

    QObject::connect(&poller,
                     &sysinfoagent::Poller::messageGenerated,
                     [](std::shared_ptr<sysinfoagent::Message> msg) {
                         std::cout << msg->asJson().toJson().toStdString() << std::endl;
                     });
    poller.startPollingEveryNSeconds(1s);

    return QCoreApplication::exec();
    // return 0;
}
