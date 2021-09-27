//
// Created by filippo on 17/08/21.
//

#include <QApplication>
#include "verticalbargauge.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    verticalbargauge* v= new verticalbargauge(0);
    v->show();
    return a.exec();
}
