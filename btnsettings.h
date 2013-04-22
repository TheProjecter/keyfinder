#ifndef BTNSETTINGS_H
#define BTNSETTINGS_H

#include <QWidget>

namespace Ui {
class BtnSettings;
}

class BtnSettings : public QWidget
{
    Q_OBJECT
    
public:
    explicit BtnSettings(QString name, QWidget *parent = 0);
    ~BtnSettings();
    
private:
    Ui::BtnSettings *ui;
};

#endif // BTNSETTINGS_H
