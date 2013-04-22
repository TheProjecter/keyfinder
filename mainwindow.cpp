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
#include "ui_mainwindow.h"
#include "btnsettings.h"

MainWindow::MainWindow(int numBtns, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLayout *layout = ui->BtnList->layout();
    for (int s = 0; s < numBtns; s++) layout->addWidget(new BtnSettings(QString::number(s)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
