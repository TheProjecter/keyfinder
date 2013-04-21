/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#ifndef LAYER_H
#define LAYER_H

#include <QWidget>

namespace Ui {
class Layer;
}

class Layer : public QWidget
{
    Q_OBJECT
    
public:
    explicit Layer(QWidget *parent = 0);
    ~Layer();
    
private:
    Ui::Layer *ui;
};

#endif // LAYER_H
