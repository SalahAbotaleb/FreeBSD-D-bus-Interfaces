#pragma once

#include <QObject>

class Hostname1 : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString hostname READ Hostname WRITE SetHostname);

   private:
    QString m_hostname;

   public:
    Hostname1();
    QString Hostname() const;
    void SetHostname(const QString& hostname);
};
