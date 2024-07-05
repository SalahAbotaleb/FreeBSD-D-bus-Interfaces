#include "hostname1.h"

#include <iostream>

Hostname1::Hostname1() {
    std::cout << "Hostname1 created" << std::endl;
    this->m_hostname = "localhostSalah";
}

QString Hostname1::Hostname() const {
    std::cout << "Hostname accessed" << std::endl;
    return m_hostname;
}

void Hostname1::SetHostname(const QString& hostname) {
    std::cout << "SetHostname accessed" << std::endl;
    this->m_hostname = hostname;
}
