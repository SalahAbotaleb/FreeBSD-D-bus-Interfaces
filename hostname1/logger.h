#pragma once
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

class logger {
   private:
    QString filepath;
    QTextStream *stream;
    QFile file;
    static logger *instance;
    logger();

   public:
    static logger &getInstance();
    void setFilepath(const QString &path);
    void log(const QString &message);
    ~logger();
};
