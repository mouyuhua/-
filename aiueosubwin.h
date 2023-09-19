#ifndef AIUEOSUBWIN_H
#define AIUEOSUBWIN_H

#include <QWidget>

namespace Ui {
class aiueoSubWin;
}

class aiueoSubWin : public QWidget
{
    Q_OBJECT

public:
    explicit aiueoSubWin(QString romanYin, QString pingjiaName, QString pianjiaName, QWidget *parent = nullptr);
    ~aiueoSubWin();

public slots:
    void setRomanYinVisiable(bool visiable);
    void setPingjiaNameVisiable(bool visiable);
    void setPianjiaNameVisiable(bool visiable);

private:
    Ui::aiueoSubWin *ui;
};

#endif // AIUEOSUBWIN_H
