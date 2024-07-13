#pragma once

#include <QObject>
class Hostname1 : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString Hostname READ Hostname WRITE SetHostname);
    Q_PROPERTY(QString StaticHostname READ StaticHostname WRITE SetStaticHostname);
    Q_PROPERTY(QString PrettyHostname READ PrettyHostname WRITE SetPrettyHostname);
    Q_PROPERTY(QString IconName READ IconName WRITE SetIconName);
    Q_PROPERTY(QString Chassis READ Chassis WRITE SetChassis);
    Q_PROPERTY(QString Location READ Location WRITE SetLocation);
    Q_PROPERTY(QString Deployment READ Deployment WRITE SetDeployment);

   private:
    QString GetValueFromMachineInfo(const QString& key) const;
    void SetValueInMachineInfo(const QString& key, const QString& value);
    QString GetChassisDefaultFromDmidecode() const;

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
    QString IconName();
    void SetIconName(const QString& icon);
    void SetIconName(const QString& icon, bool interactive);
    QString Chassis();
    void SetChassis(const QString& chassis);
    void SetChassis(const QString& chassis, bool interactive);
    QString Deployment() const;
    void SetDeployment(const QString& deployment);
    void SetDeployment(const QString& deployment, bool interactive);
    QString Location() const;
    void SetLocation(const QString& location);
    void SetLocation(const QString& location, bool interactive);
    QByteArray GetProductUUID(bool interactive) const;
};
