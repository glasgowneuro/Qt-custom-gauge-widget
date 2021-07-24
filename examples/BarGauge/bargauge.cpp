//
// Created by filippo on 10/07/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BarGauge.h" resolved

#include "bargauge.h"
#include "ui_bargauge.h"


BarGauge::BarGauge(QWidget *parent) :
        QWidget(parent), ui(new Ui::BarGauge) {
    ui->setupUi(this);

    
}

BarGauge::~BarGauge() {
    delete ui;
}

