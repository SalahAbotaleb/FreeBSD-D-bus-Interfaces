/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -m -p hostname1 /home/salah/FreeBSD-D-bus-Interfaces/hostname1/org.freedesktop.hostname1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef HOSTNAME1_H
#define HOSTNAME1_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.hostname1
 */
class OrgFreedesktopHostname1Interface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.hostname1"; }

public:
    OrgFreedesktopHostname1Interface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgFreedesktopHostname1Interface();

    Q_PROPERTY(QString Hostname READ hostname)
    inline QString hostname() const
    { return qvariant_cast< QString >(property("Hostname")); }

    Q_PROPERTY(QString IconName READ iconName)
    inline QString iconName() const
    { return qvariant_cast< QString >(property("IconName")); }

    Q_PROPERTY(QString PrettyHostname READ prettyHostname)
    inline QString prettyHostname() const
    { return qvariant_cast< QString >(property("PrettyHostname")); }

    Q_PROPERTY(QString StaticHostname READ staticHostname)
    inline QString staticHostname() const
    { return qvariant_cast< QString >(property("StaticHostname")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> SetHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QStringLiteral("SetHostname"), argumentList);
    }

    inline QDBusPendingReply<> SetIconName(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QStringLiteral("SetIconName"), argumentList);
    }

    inline QDBusPendingReply<> SetPrettyHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QStringLiteral("SetPrettyHostname"), argumentList);
    }

    inline QDBusPendingReply<> SetStaticHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QStringLiteral("SetStaticHostname"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freedesktop {
    typedef ::OrgFreedesktopHostname1Interface hostname1;
  }
}
#endif
