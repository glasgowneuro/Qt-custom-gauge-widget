//
// Created by filippo on 17/08/21.
//

#include "VerticaBarGauge.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VerticalBarGauge w;
    w.show();

    return a.exec();
}
