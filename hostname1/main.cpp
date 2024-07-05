#include <sysexits.h>

#include <QCoreApplication>
#include <QtDBus>
#include <iostream>

#include "hostname1.h"
#include "hostname1adaptor.h"
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QDBusConnection sessionBus = QDBusConnection::sessionBus();
    if (!sessionBus.registerService("org.freedesktop.hostname1")) {
        qCritical() << "Could not register hostname1 service";
        return EX_UNAVAILABLE;
    }
    Hostname1 hostname1;
    new Hostname1Adaptor(&hostname1);
    if (!sessionBus.registerObject("/org/freedesktop/hostname1", &hostname1)) {
        qCritical() << "Could not register hostname1 object";
        sessionBus.unregisterService("org.freedesktop.hostname1");
        return EX_UNAVAILABLE;
    }
    std::cout << "Hostname1 service running" << std::endl;

    return app.exec();
}
