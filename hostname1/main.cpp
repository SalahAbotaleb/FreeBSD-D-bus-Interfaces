#include <sysexits.h>

#include <QCoreApplication>
#include <QtDBus>
#include <iostream>

#include "hostname1.h"
#include "hostname1adaptor.h"
#include "logger.h"
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QDBusConnection systemBus = QDBusConnection::systemBus();
    Hostname1 hostname1;
    logger &log = logger::getInstance();
    log.setFilepath("/home/salah/FreeBSD-D-bus-Interfaces/hostname1.log");
    log.log("Hostname1 service started ");
    if (!systemBus.registerService("org.freedesktop.hostname1")) {
        qCritical() << "Could not register hostname1 service";
        return EX_UNAVAILABLE;
    }
    new Hostname1Adaptor(&hostname1);
    if (!systemBus.registerObject("/org/freedesktop/hostname1", &hostname1)) {
        qCritical() << "Could not register hostname1 object";
        systemBus.unregisterService("org.freedesktop.hostname1");
        return EX_UNAVAILABLE;
    }
    std::cout << "Hostname1 service running" << std::endl;

    return app.exec();
}
