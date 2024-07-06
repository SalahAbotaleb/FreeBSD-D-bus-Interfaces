#include "hostname1.h"

#include <limits.h>
#include <unistd.h>

#include <QDebug>
#include <QProcess>

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
    return m_pretty_hostname;
}

void Hostname1::SetPrettyHostname(const QString& hostname) {
    m_pretty_hostname = hostname;
    qDebug() << "PrettyHostname set to:" << m_pretty_hostname;
}

void Hostname1::SetPrettyHostname(const QString& hostname, bool user_interaction) {
    SetPrettyHostname(hostname);
}

QString Hostname1::IconName() const {
    return m_icon_name;
}

void Hostname1::SetIconName(const QString& icon_name) {
    m_icon_name = icon_name;
    qDebug() << "IconName set to:" << m_icon_name;
}

void Hostname1::SetIconName(const QString& icon, bool user_interaction) {
    SetIconName(icon);
}
