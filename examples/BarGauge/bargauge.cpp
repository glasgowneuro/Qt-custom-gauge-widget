//
// Created by filippo on 24/09/21.
//

#include "bargauge.h"
#include "ui_bargauge.h"

BarGauge::BarGauge(QWidget *parent):QWidget(parent), ui(new Ui::BarGauge)
{
    ui->setupUi(this);
    hBarGauge = new QcHorizontalBar(parent);
    hBarGauge->setBgColor(Qt::darkGray);
    hBarGauge->setProgressColor(Qt::darkBlue);
    hBarGauge->setLineColor(Qt::white);
    hBarGauge->setRange(-45,45);
    hBarGauge->setPrecision(1);
    hBarGauge->setShortStep(1);
    hBarGauge->setLongStep(10);
    hBarGauge->setRulerTop(true);
    hBarGauge->setRulerBottom(true);

    ui->_valueLabel->setStyleSheet("QLabel {color: black;}");
    ui->verticalSlider->setMinimum(-45);
    ui->verticalSlider->setMaximum(45);
    ui->verticalSlider->setValue(0);
    ui->horizontalLayout->addWidget(hBarGauge);
    connect(ui->verticalSlider, &QSlider::valueChanged,this,&BarGauge::valueChangeSlot);
}

BarGauge::~BarGauge() {
    delete ui;
}

void BarGauge::valueChangeSlot(int value)
{
    _currentValue=value;
    ui->_valueLabel->setText(QString::number(value)+ "%");
    hBarGauge->setCurrentValue(value);
}
