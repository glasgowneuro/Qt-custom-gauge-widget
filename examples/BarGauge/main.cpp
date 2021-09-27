//
// Created by filippo on 10/07/21.
//

#include <QApplication>
#include "bargauge.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarGauge *b=new BarGauge(0);
    b->show();
    return a.exec();
}
