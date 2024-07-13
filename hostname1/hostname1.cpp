#include "hostname1.h"

#include <limits.h>
#include <unistd.h>

#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QSettings>

#include "logger.h"

Hostname1::Hostname1() {
}

QString Hostname1::Hostname() const {
    char hostname[_POSIX_HOST_NAME_MAX];
    gethostname(hostname, sizeof(hostname));
    return hostname;
}

void Hostname1::SetHostname(const QString& hostname) {
    char hostname_cstr[_POSIX_HOST_NAME_MAX];
    strncpy(hostname_cstr, hostname.toUtf8().constData(), sizeof(hostname_cstr));
    sethostname(hostname_cstr, strlen(hostname_cstr));
}

void Hostname1::SetHostname(const QString& hostname, bool user_interaction) {
    SetHostname(hostname);
}

QString Hostname1::StaticHostname() const {
    QProcess process;
    const QString command = "sysrc";
    const QStringList arguments = {"-n", "hostname"};
    process.start(command, arguments);
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    if (result.startsWith("sysrc: unknown variable \'hostname\'")) {
        return QString();
    }
    result.replace("\n", "");
    return result;
}

void Hostname1::SetStaticHostname(const QString& hostname) {
    QProcess process;
    const QString command = "sysrc";
    const QStringList arguments = {"hostname=" + hostname};
    process.start(command, arguments);
    process.waitForFinished();
}

void Hostname1::SetStaticHostname(const QString& hostname, bool user_interaction) {
    SetStaticHostname(hostname);
}

QString Hostname1::PrettyHostname() const {
    return GetValueFromMachineInfo("PRETTY_HOSTNAME");
}

QString Hostname1::GetValueFromMachineInfo(const QString& key) const {
    QString file_path = "/etc/machine-info";
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString();
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith(key + "=")) {
            file.close();
            return line.split("=").at(1);
        }
    }
    file.close();
    return QString();
}

void Hostname1::SetValueInMachineInfo(const QString& key, const QString& value) {
    QString file_path = "/etc/machine-info";
    QFile file(file_path);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    bool is_key_present = false;
    QString file_content;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith(key + "=")) {
            line = key + "=" + value;
            is_key_present = true;
        }
        file_content += line + "\n";
    }
    if (!is_key_present) {
        file_content += key + "=" + value + "\n";
    }
    file.resize(0);
    in << file_content;
    file.close();
}

void Hostname1::SetPrettyHostname(const QString& hostname) {
    SetValueInMachineInfo("PRETTY_HOSTNAME", hostname);
}

void Hostname1::SetPrettyHostname(const QString& hostname, bool user_interaction) {
    SetPrettyHostname(hostname);
}

QString Hostname1::IconName() {
    QString res = GetValueFromMachineInfo("ICON_NAME");
    if (res.isEmpty()) {
        res = "computer-" + GetChassisDefaultFromDmidecode();
        SetValueInMachineInfo("ICON_NAME", res);
    }
    return res;
}

void Hostname1::SetIconName(const QString& icon) {
    SetValueInMachineInfo("ICON_NAME", icon);
}

void Hostname1::SetIconName(const QString& icon, bool user_interaction) {
    SetIconName(icon);
}

QString Hostname1::Chassis() {
    QString res = GetValueFromMachineInfo("CHASSIS");
    if (res.isEmpty()) {
        res = GetChassisDefaultFromDmidecode();
        SetValueInMachineInfo("CHASSIS", res);
    }
    return res;
}

void Hostname1::SetChassis(const QString& chassis) {
    SetValueInMachineInfo("CHASSIS", chassis);
}

void Hostname1::SetChassis(const QString& chassis, bool user_interaction) {
    SetChassis(chassis);
}

QString Hostname1::Deployment() const {
    return GetValueFromMachineInfo("DEPLOYMENT");
}

void Hostname1::SetDeployment(const QString& deployment) {
    SetValueInMachineInfo("DEPLOYMENT", deployment);
}

void Hostname1::SetDeployment(const QString& deployment, bool user_interaction) {
    SetDeployment(deployment);
}

QString Hostname1::Location() const {
    return GetValueFromMachineInfo("LOCATION");
}

void Hostname1::SetLocation(const QString& location) {
    SetValueInMachineInfo("LOCATION", location);
}

void Hostname1::SetLocation(const QString& location, bool user_interaction) {
    SetLocation(location);
}

QString Hostname1::GetChassisDefaultFromDmidecode() const {
    QProcess process;
    const QString command = "dmidecode";
    const QStringList arguments = {"-s", "chassis-type"};
    process.start(command, arguments);
    process.waitForFinished();
    QString result = process.readAllStandardOutput();
    result.replace("\n", "");
    return result;
}

QByteArray Hostname1::GetProductUUID(bool interactive) const {
    QProcess process;
    const QString command = "dmidecode";
    const QStringList arguments = {"-s", "system-uuid"};
    process.start(command, arguments);
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    result = result.trimmed();
    return result;
}
