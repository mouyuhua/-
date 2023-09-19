#include "aiueo.h"
#include "ui_aiueo.h"
#include "JsonProsess.h"
#include "aiueosubwin.h"
#include <QRandomGenerator>
#include <QtDebug>

AIUEO::AIUEO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AIUEO)
{
    ui->setupUi(this);
    QGridLayout *subwinlayout;
    subwinlayout = new QGridLayout();
    subwinlayout->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    ui->scrollAreaWidgetContents->setLayout(subwinlayout);
}

AIUEO::~AIUEO()
{
    delete ui;
}

void AIUEO::resizeEvent(QResizeEvent *event)
{
    if((event->size().width()-40) >= subWinWidget)
            column = (event->size().width()-40)/subWinWidget;
    if(column != hisColumn && canResize)
    {
        hisColumn = column;
        resetSubWin();
    }
}

void AIUEO::resetSubWin()
{
    QGridLayout *wLayout = qobject_cast<QGridLayout*>(ui->scrollAreaWidgetContents->layout());
    QLayoutItem *items[wLayout->count()];
    int newRow = wLayout->count()/column;
    if(wLayout->count() % column) newRow += 1;
    int temp = wLayout->count();
    for(int i=temp-1; i>=0; i--)
    {
        items[i] = wLayout->takeAt(i);
    }
    for(int i=1; i<=newRow; i++)
    {
        for(int j=1; j<=column; j++)
        {
            if((i-1)*column + (j-1) >= temp) break;
            wLayout->addItem(items[(i-1)*column + (j-1)], i, j);
        }
    }
}

void AIUEO::clearAllSubWin()
{
    QGridLayout *wLayout = qobject_cast<QGridLayout*>(ui->scrollAreaWidgetContents->layout());
    int newRow = wLayout->count()/column;
    if(wLayout->count() % column) newRow += 1;
    int temp = wLayout->count();
    for(int i=temp-1; i>=0; i--)
    {
        wLayout->takeAt(i)->widget()->deleteLater();
    }
}

void AIUEO::on_start_clicked()
{
    clearAllSubWin();
    canResize = true;

    QGridLayout *wLayout = qobject_cast<QGridLayout*>(ui->scrollAreaWidgetContents->layout());
    int subwinNum = ui->randomNum->value();

    for(int i=0; i<subwinNum; i++)
    {
        int num = root_Obj.value("num").toInt();
        int index = QRandomGenerator::global()->bounded(num);
        QString romanYin;
        QString pingjiaName;
        QString pianjiaName;
        if(root_Obj.value("romanYin").toObject().value("bUse").toBool())
        {
            romanYin = root_Obj.value("romanYin").toObject().value("content").toArray().at(index).toString();
        }
        else
        {
            romanYin="";
        }
        if(root_Obj.value("pingjiaName").toObject().value("bUse").toBool())
        {
            pingjiaName = root_Obj.value("pingjiaName").toObject().value("content").toArray().at(index).toString();
        }
        else
        {
            pingjiaName = "";
        }
        if(root_Obj.value("pianjiaName").toObject().value("bUse").toBool())
        {
            pianjiaName = root_Obj.value("pianjiaName").toObject().value("content").toArray()at(index).toString();
        }
        else
        {
            pianjiaName = "";
        }
        aiueoSubWin * subwin = new aiueoSubWin(romanYin, pingjiaName, pianjiaName);
        aiueoSubWin * subwin = new aiueoSubWin(romanYin, pingjiaName, pianjiaName);
        subwin->setPianjiaNameVisiable(ui->bPianjiaName->isChecked());
        subwin->setPingjiaNameVisiable(ui->bPingjianame->isChecked());

        connect(ui->bRomanYin, &QCheckBox::toggled, subwin, &aiueoSubWin::setRomanYinVisiable);
        connect(ui->bPianjiaName, &QCheckBox::toggled, subwin, &aiueoSubWin::setPianjiaNameVisiable);
        connect(ui->bPingjianame, &QCheckBox::toggled, subwin, &aiueoSubWin::setPingjiaNameVisiable);

        wLayout->addWidget(subwin);
    }

    column = (ui->scrollArea->size().width()-40)/subWinWidget;

    resetSubWin();
}
