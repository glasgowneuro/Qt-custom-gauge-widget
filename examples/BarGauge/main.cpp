//
// Created by filippo on 10/07/21.
//

#include "bargauge.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarGauge w;
    w.show();

    return a.exec();
}
