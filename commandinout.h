#ifndef COMMANDINOUT_H
#define COMMANDINOUT_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <QProcess>

class CommandInOut : public QObject
{
    Q_OBJECT
public:
    explicit CommandInOut(QObject *parent = nullptr);
 void Send(QString command);
signals:

public slots:

private:
 QString program;
 QObject *parent;
};

#endif // COMMANDINOUT_H
