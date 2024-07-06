#include "logger.h"

logger *logger::instance = 0;

logger::logger() {
    filepath = "log.txt";
    file.setFileName(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        stream = new QTextStream(&file);
    }
}

logger &logger::getInstance() {
    if (!instance) {
        instance = new logger();
    }
    return *instance;
}

void logger::setFilepath(const QString &path) {
    filepath = path;
    file.setFileName(filepath);
    if (stream) {
        delete stream;
    }
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        stream = new QTextStream(&file);
    }
}

void logger::log(const QString &message) {
    *stream << message << Qt::endl;
}

logger::~logger() {
    delete stream;
    if (file.isOpen()) {
        file.close();
    }
}
