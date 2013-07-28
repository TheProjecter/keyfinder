#ifndef KEYTHREAD_H
#define KEYTHREAD_H

#include <QThread>

class KeyThread : public QThread
{
    Q_OBJECT
public:
    explicit KeyThread(int n, bool press, QObject *parent = 0);
    void run();
    
private:
    bool press;
    int n;

signals:

public slots:
    void kill();
};

#endif // KEYTHREAD_H
