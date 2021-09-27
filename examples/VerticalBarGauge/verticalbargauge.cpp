//
// Created by filippo on 27/09/21.
//

#include "verticalbargauge.h"
#include "ui_verticalbargauge.h"

verticalbargauge::verticalbargauge(QWidget *parent):QWidget(parent), ui(new Ui::verticalbargauge)
{
    ui->setupUi(this);
    vBarGauge = new QcBar(parent);
    vBarGauge->setDirection(QcBar::DirectionEnum::Vertical);
    vBarGauge->setBgColor(Qt::darkGray);
    vBarGauge->setProgressColor(Qt::darkBlue);
    vBarGauge->setLineColor(Qt::white);
    vBarGauge->setRange(-45,45);
    vBarGauge->setCurrentValue(0);
    vBarGauge->setPrecision(1);
    vBarGauge->setShortStep(1);
    vBarGauge->setLongStep(10);
    vBarGauge->setRulerRight(true);
    vBarGauge->setRulerLeft(true);

    valueLabel=new QLabel(parent);
    valueLabel->setStyleSheet("QLabel {color: black;}");
    valueLabel->setText("%");
    verticalSlider=new QSlider(parent);
    verticalSlider->setMinimum(-45);
    verticalSlider->setMaximum(45);
    verticalSlider->setValue(0);
    ui->horizontalLayout->addWidget(vBarGauge);
    ui->horizontalLayout->addWidget(verticalSlider);
    ui->horizontalLayout->addWidget(valueLabel);
    connect(verticalSlider, &QSlider::valueChanged,this,&verticalbargauge::valueChangeSlot);

}

verticalbargauge::~verticalbargauge() {
    delete ui;
}

void verticalbargauge::valueChangeSlot(int value)
{
    _currentValue=value;
    valueLabel->setText(QString::number(value)+ "%");
    vBarGauge->setCurrentValue(value);
}
