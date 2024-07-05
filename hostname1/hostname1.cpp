#include "hostname1.h"

#include <QDebug>

Hostname1::Hostname1() {
    this->m_hostname = "localhostSalah";
}

QString Hostname1::Hostname() const {
    return m_hostname;
}

void Hostname1::SetHostname(const QString& hostname) {
    this->m_hostname = hostname;
    qDebug() << "Hostname set to:" << m_hostname;
}
