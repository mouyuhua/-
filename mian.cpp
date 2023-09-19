#include "aiueo.h"
#include "JsonProsess.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadData();

    AIUEO w;
    w.show();
    return a.exec();
}
