/**
 *This work is licensed under the
 *Creative Commons Attribuzione 3.0
 *Unported License. To view a copy
 *of this license, visit
 *http://creativecommons.org/licenses/by/3.0/
 *
 *@author Raffaele Pertile <raffarti@gmail.com>
 */
#include "layer.h"
#include "ui_layer.h"

Layer::Layer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Layer)
{
    ui->setupUi(this);
}

Layer::~Layer()
{
    delete ui;
}
