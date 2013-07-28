#include "keythread.h"
#include "keyprinter.h"

KeyThread::KeyThread(int n, bool press, QObject *parent) :
    QThread(parent), n(n), press(press)
{

}

void KeyThread::run(){
    KeyPrinter::sendKey(n, press);
}

void KeyThread::kill(){
    qDebug("A key Timed Out");
    this->terminate();
}
