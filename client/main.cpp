#include "message.h"
#include "messagejsonparser.h"
#include "rep_systeminformationservice_replica.h"
#include "storageinfojsonparser.h"
#include <iostream>
#include <QCoreApplication>
#include <QJsonObject>
#include <QRemoteObjectHost>
#include <QRemoteObjectNode>
#include <QTimezone>

using namespace std::chrono_literals;

// void playground()
// {
//     QDateTime dt = QDateTime::fromString(QString(""), Qt::ISODateWithMs);
//     std::cout << dt.isValid() << dt.toString(Qt::ISODateWithMs).toStdString() << std::endl;
//     if (!dt.isValid()) {
//         dt = QDateTime::fromMSecsSinceEpoch(0, QTimeZone::UTC);
//     }

//     std::cout << dt.isValid() << dt.toString(Qt::ISODateWithMs).toStdString() << std::endl;

//     {
//         sysinfoagent::StorageInfoReader reader{};
//         auto info1 = reader.readInfo();

//         auto jv1 = info1->asJson();
//         auto js1 = jv1.toJson().toStdString();
//         std::cout << js1 << std::endl;

//         auto jvp = QJsonValue::fromJson(js1);
//         sysinfoagent::StorageInfoJsonParser p;
//         auto info2 = p.parseJson(jvp);

//         auto jv2 = info2->asJson();
//         auto js2 = jv2.toJson().toStdString();
//         std::cout << js2 << std::endl;

//         std::cout << (js1 == js2);
//     }

//     auto reader = std::make_unique<sysinfoagent::StorageInfoReader>();

//     sysinfoagent::Poller poller(nullptr);
//     poller.registerInfoReader(std::move(reader));

//     QObject::connect(&poller,
//                      &sysinfoagent::Poller::messageGenerated,
//                      [](std::shared_ptr<sysinfoagent::Message> msg) {
//                          std::string s1 = msg->asJson().toJson().toStdString();
//                          std::cout << s1 << std::endl;
//                          QJsonValue jv = QJsonValue::fromJson(s1);
//                          sysinfoagent::MessageJsonParser parser;
//                          parser.registerInfoParser(
//                              std::make_unique<sysinfoagent::StorageInfoJsonParser>());
//                          auto msg2 = parser.parseJson(jv);
//                          std::string s2 = msg2->asJson().toJson().toStdString();
//                          std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
//                      });
//     poller.startPollingEveryNSeconds(1s);
// }

int client()
{
    std::cout << "client started" << std::endl;

    QRemoteObjectNode node;

    node.connectToNode(QUrl("local:sysinfos"));

    std::unique_ptr<SystemInformationServiceReplica> replica(
        node.acquire<SystemInformationServiceReplica>());

    if (!replica->waitForSource()) {
        std::cout << "Connection Timeout" << std::endl;
        return -1;
    }

    QObject::connect(replica.get(),
                     &SystemInformationServiceReplica::messageJsonGenerated,
                     [](QJsonValue json) {
                         std::cout << "Received: " << json.toJson().toStdString() << std::endl;
                         sysinfoagent::MessageJsonParser parser;
                         parser.registerInfoParser(
                             std::make_unique<sysinfoagent::StorageInfoJsonParser>());
                         auto msg = parser.parseJson(json);
                         std::cout << msg->timestamp().toString().toStdString() << std::endl;

                         std::cout << msg->asJson().toJson().toStdString() << std::endl;
                     });

    return QCoreApplication::exec();
}

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

    // playground();

    return client();
}
