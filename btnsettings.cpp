#include "btnsettings.h"
#include "ui_btnsettings.h"

BtnSettings::BtnSettings(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtnSettings)
{
    ui->setupUi(this);
    ui->nameLbl->setText(name);
}

BtnSettings::~BtnSettings()
{
    delete ui;
}
