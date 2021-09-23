//
// Created by filippo on 10/07/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BarGauge.h" resolved

#include <QPainter>
#include <QColorDialog>
#include "bargauge.h"
#include "ui_bargauge.h"

BarGauge::BarGauge(QWidget *parent)
                    :QWidget(parent),
                    ui(new Ui::BarGauge)
{
    ui->setupUi(this);

    hBarGauge->setBgColor(Qt::darkGray);
    hBarGauge->setProgressColor(Qt::darkBlue);
    hBarGauge->setLineColor(Qt::white);
    hBarGauge->setRange(-45,45);
    hBarGauge->setPrecision(1);
    hBarGauge->setShortStep(1);
    hBarGauge->setLongStep(10);
    hBarGauge->setRulerTop(true);
    hBarGauge->setRulerBottom(true);
    ui->horizontalLayout->addWidget(hBarGauge);
/*
    ui->_valueLabel->setStyleSheet("QLabel {color: white;}");
    ui->verticalSlider->setMinimum(-45);
    ui->verticalSlider->setMaximum(45);
    ui->verticalSlider->setValue(0);



    connect(ui->verticalSlider, &QSlider::valueChanged,this,&BarGauge::valueChangeSlot);*/
}

BarGauge::~BarGauge() {
    delete ui;
}

void BarGauge::valueChangeSlot(int value)
{
    /*
    currentValue=value;
    ui->_valueLabel->setText(QString::number(value)+ "%");*/
    repaint();
}

