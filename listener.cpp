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
#include "keyprinter.h"
#include <iostream>

Listener::Listener(QDataStream *in, QObject *parent) :
    QThread(parent), in(in)
{
}

void Listener::run(){

    bool *input = new bool[N_BTN];
    for (int s = 0; s < N_BTN; s++) input[s] = false;
    while(1){
        int n = 0;
        for (int s = 0; s < 20; s++){
            u_int32_t l;
            *in >> l;
            if (l <= 1){
                if (input[n] != l){
                    input[n] = l;
                    KeyPrinter::sendKey(n, l);
                    std::cout << "Key " << n << " " << (l?"pressed":"released") <<std::endl;
                }
                n++;
            }
        }
    }
    qDebug("Stopped.");
}
