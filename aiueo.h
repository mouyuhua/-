#ifndef AIUEO_H
#define AIUEO_H

#include <QMainWindow>
#include <QGridLayout>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class AIUEO; }
QT_END_NAMESPACE

class AIUEO : public QMainWindow
{
    Q_OBJECT

public:
    AIUEO(QWidget *parent = nullptr);
    ~AIUEO();
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_start_clicked();

private:
    void resetSubWin();
    void clearAllSubWin();
    Ui::AIUEO *ui;
    int subWinWidget = 82;
    int subWinHeight = 74;
    int column = 0;
    int hisColumn = 2;
    bool canResize = false;
};
#endif // AIUEO_H
