#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include "commandinout.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream outStream(stdout);
    outStream<< QString("Start")<< endl;

    QStringList Commands;
    Commands << "puts Start_TCL"
             << "set hello Privet"
             << "puts $hello"
             << "proc proc_while { x } {while {$x < 10} {puts $x; incr x;}}"
             << "proc_while 5";

CommandInOut ComInOut;
    for (int i = 0; i < Commands.size(); ++i){
        qDebug() << "Command " << i << ":" << Commands.at(i);
ComInOut.Send(Commands.at(i));
    }


    return a.exec();
}
