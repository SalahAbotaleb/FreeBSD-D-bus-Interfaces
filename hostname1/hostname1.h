#pragma once

#include <QObject>
class Hostname1 : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString Hostname READ Hostname WRITE SetHostname);
    Q_PROPERTY(QString StaticHostname READ StaticHostname WRITE SetStaticHostname);
    Q_PROPERTY(QString PrettyHostname READ PrettyHostname WRITE SetPrettyHostname);
    Q_PROPERTY(QString IconName READ IconName WRITE SetIconName);

   private:
    QString m_hostname;
    QString m_static_hostname;
    QString m_pretty_hostname;
    QString m_icon_name;

   public:
    Hostname1();
    QString Hostname() const;
    void SetHostname(const QString& hostname);
    void SetHostname(const QString& hostname, bool interactive);
    QString StaticHostname() const;
    void SetStaticHostname(const QString& hostname);
    void SetStaticHostname(const QString& hostname, bool interactive);
    QString PrettyHostname() const;
    void SetPrettyHostname(const QString& hostname);
    void SetPrettyHostname(const QString& hostname, bool interactive);
    QString IconName() const;
    void SetIconName(const QString& icon);
    void SetIconName(const QString& icon, bool interactive);
};
