#pragma once

#include <QDateTime>
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
    Q_PROPERTY(QString KernelName READ KernelName);
    Q_PROPERTY(QString KernelRelease READ KernelRelease);
    Q_PROPERTY(QString KernelVersion READ KernelVersion);
    Q_PROPERTY(QString OperatingSystemPrettyName READ OperatingSystemPrettyName);
    Q_PROPERTY(QString OperatingSystemCPEName READ OperatingSystemCPEName);
    Q_PROPERTY(QString OperatingSystemPrettyCPEName READ OperatingSystemPrettyCPEName);
    // Q_PROPERTY(QDateTime OperatingSystemSupportEnd READ OperatingSystemSupportEnd);
    Q_PROPERTY(QString HomeURL READ HomeURL);
    Q_PROPERTY(QString HardwareVendor READ HardwareVendor);
    Q_PROPERTY(QString HardwareModel READ HardwareModel);
    Q_PROPERTY(QString FirmwareVersion READ FirmwareVersion);
    Q_PROPERTY(QString FirmwareVendor READ FirmwareVendor);
    Q_PROPERTY(quint64 FirmwareDate READ FirmwareDate);
    Q_PROPERTY(QByteArray MachineID READ MachineID);
    Q_PROPERTY(QByteArray BootID READ BootID);
    Q_PROPERTY(QString Describe READ Describe);

   private:
    QString GetValueFromMachineInfo(const QString& key) const;
    void SetValueInMachineInfo(const QString& key, const QString& value);
    QString GetChassisDefaultFromDmidecode() const;
    QString GetValueFromOSRelease(const QString& key) const;
    QString GetValueFromDmiDecode(const QString& key) const;

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
    QString GetHardwareSerial() const;
    QString KernelName() const;
    QString KernelRelease() const;
    QString KernelVersion() const;
    QString OperatingSystemPrettyName() const;
    QString OperatingSystemCPEName() const;
    QString OperatingSystemPrettyCPEName() const;
    QString HomeURL() const;
    QString HardwareVendor() const;
    QString HardwareModel() const;
    QString FirmwareVersion() const;
    QString FirmwareVendor() const;
    quint64 FirmwareDate() const;
    QByteArray MachineID() const;
    QByteArray BootID() const;
    QString Describe();
};
