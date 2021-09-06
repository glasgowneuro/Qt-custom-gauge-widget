//
// Created by filippo on 04/07/21.
//

#include "lcd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lcd w;
    w.show();

    return a.exec();
}
