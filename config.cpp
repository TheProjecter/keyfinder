#include "config.h"
#include <QTextStream>


enum PState{A, MACRO, E};
PState stateA(QString line);
PState stateMACRO(QString line);

Config::Config(QString file, QObject *parent) :
    QObject(parent), cFile(new QFile(file))
{
    int nLine = 0;
    QTextStream in;
    PState a = A;
    QList<PState*> pState;
    pState.append(&a);
    QString tag;
    while(in.atEnd()){
        nLine++;
        PState rState;
        QString l = in.readLine();
        switch(*pState.last()){
        case A:
       //     rState = stateA(l);
            break;
        case MACRO:
        //    rState = stateMACRO(l);
            break;
        default:;
        }
        if (rState == E){

        } else pState.append(&rState);
    }
}
