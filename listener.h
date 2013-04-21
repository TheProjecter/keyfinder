/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QDataStream>

#define N_BTN 10

class Listener : public QThread
{
    Q_OBJECT
public:
    explicit Listener(QDataStream *in, QObject *parent = 0);
    void run();

private:
    QDataStream *in;
signals:
    
public slots:
    
};

#endif // LISTENER_H
