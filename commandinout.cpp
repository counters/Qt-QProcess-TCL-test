#include "commandinout.h"



CommandInOut::CommandInOut(QObject *parent) : QObject(parent)
{
   QString program = "C:\\Tcl\\bin\\tclsh86.exe";
   program = QDir::fromNativeSeparators(program);
   qDebug()<<"program:"<< program;


}

void CommandInOut::Send(QString command)
{

        QStringList arguments;
        qDebug() << "Send Command " << ":" << command;
        arguments << command;

        /*
         * http://doc.qt.io/Qt-5/qprocess.html
        QProcess *myProcess = new QProcess(parent);
        */
        QProcess *myProcess = new QProcess(this);

        myProcess->start(program, arguments);
        qDebug()<<"waitForStarted";
        myProcess->waitForStarted();

         qDebug()<<"waitForBytesWritten";
        myProcess->waitForBytesWritten();
         qDebug()<<"waitForReadyRead";
         myProcess->waitForReadyRead();

        qDebug() <<"readAllStandardError"<< myProcess->readAllStandardError();
        qDebug() <<"readAllStandardOutput"<< myProcess->readAllStandardOutput();



         qDebug()<<"waitForFinished";
       myProcess->waitForFinished();
 qDebug()<<"End myProcess";

}
