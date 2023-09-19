#include "aiueosubwin.h"
#include "ui_aiueosubwin.h"

aiueoSubWin::aiueoSubWin(QString romanYin, QString pingjiaName, QString pianjiaName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aiueoSubWin)
{
    ui->setupUi(this);

    ui->romanYin->setVisible(false);
    ui->pingjiaName->setVisible(false);
    ui->pianjiaName->setVisible(false);

    ui->romanYin->setText(romanYin);
    ui->pingjiaName->setText(pingjiaName);
    ui->pianjiaName->setText(pianjiaName);
}

aiueoSubWin::~aiueoSubWin()
{
    delete ui;
}

void aiueoSubWin::setRomanYinVisiable(bool visiable)
{
    ui->romanYin->setVisible(visiable);
}

void aiueoSubWin::setPingjiaNameVisiable(bool visiable)
{
    ui->pingjiaName->setVisible(visiable);
}

void aiueoSubWin::setPianjiaNameVisiable(bool visiable)
{
    ui->pianjiaName->setVisible(visiable);
}
