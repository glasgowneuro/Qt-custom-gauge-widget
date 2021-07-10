//
// Created by filippo on 04/07/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_lcd.h" resolved

#include "lcd.h"
#include "ui_lcd.h"


lcd::lcd(QWidget *parent) :
        QWidget(parent), ui(new Ui::lcd) {
    ui->setupUi(this);

    // get the palette
    auto palette = ui->lcdNumber->palette();
    // foreground color
    palette.setColor(palette.WindowText, Qt::darkRed);
    // set the palette back
    ui->lcdNumber->setPalette(palette);
    // set style
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    ui->label->setText("K");
    ui->label->setPalette(palette);

}

lcd::~lcd() {
    delete ui;
}

void lcd::on_horizontalSlider_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}