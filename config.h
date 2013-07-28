#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QFile>

class Config : public QObject
{
    Q_OBJECT
public:
    enum State{READING, DONE, ERROR};
    State state;
    explicit Config(QString file = "keyfinder.conf", QObject *parent = 0);
    
private:
    QFile *cFile;
signals:
    
public slots:
    
};

#endif // CONFIG_H
