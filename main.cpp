/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#include "mainwindow.h"
#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <iostream>
#include "listener.h"

static int dispatcher(int argc, char *argv[]);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int e = 0;
    if (argc != 1){
        e = dispatcher(argc, argv);
    }
    qDebug("%d",e);
    MainWindow gui(10);
    switch(e){
    case 1:
        gui.show();
    }

    if (e < 0){
        return a.exec();
    }
    QFile *file = new QFile("/dev/usb/hiddev0");
    QDataStream *in = new QDataStream(file);
    in->setByteOrder(QDataStream::LittleEndian);
    FILE *ff = fopen ("/dev/usb/hiddev0" , "r");
    if (ff)file->open(ff , QFile::ReadOnly, QFile::DontCloseHandle);
    else{
        if (!file->exists())qDebug("Fatal: hiddev0 not found!");
        else{
            system(QString("kdesu ").append(QString(argv[0])).toLatin1());
        }
        return -1;
    }
    qDebug(file->isOpen()?"true":"bugg");
    if (!file->isOpen()){
        qDebug("Fatal: failed to open /dev/usb/hiddev0, check read permission.");
        return -1;
    }
    Listener *listener = new Listener(in);
    listener->start();
    return a.exec();
}

static int dispatcher(int argc, char *argv[]){
    if (QString(argv[1]) == "--kdesu"){
        return system((QString("kdesu ") + argv[0]).toLatin1());
    }
    if (QString(argv[1]) == "gui") return 1;
    return 0;
}
