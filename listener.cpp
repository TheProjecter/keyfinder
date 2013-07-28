/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#include "listener.h"
#include <iostream>
#include "keythread.h"
#include <QPointer>

Listener::Listener(QDataStream *in, QObject *parent) :
    QThread(parent), in(in)
{
}

void Listener::run(){

    bool *input = new bool[N_BTN];
    QPointer<KeyThread> *current = new QPointer<KeyThread>[N_BTN];
    for (int s = 0; s < N_BTN; s++) input[s] = false;
    while(1){
        int n = 0;
        for (int s = 0; s < 20; s++){
            u_int32_t l;
            *in >> l;
            if (l <= 1){
                if (input[n] != l){
                    input[n] = l;
                    if (!current[n].isNull() && !current[n].data()->isFinished()) current[n].data()->kill();
                    if (!current[n].isNull()) current[n].data()->deleteLater();
                    KeyThread *kt;
                    kt = new KeyThread(n, l);
                    current[n] = kt;
                    kt->start();
                    std::cout << "Key " << n << " " << (l?"pressed":"released") <<std::endl;
                }
                n++;
            }
        }
    }
    qDebug("Stopped.");
}
