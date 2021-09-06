//
// Created by filippo on 18/08/21.
//

#include "ArchGauge.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArchGauge w;
    w.show();

    return a.exec();
}
