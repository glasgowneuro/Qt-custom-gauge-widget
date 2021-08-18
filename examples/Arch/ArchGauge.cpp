//
// Created by filippo on 18/08/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_archgauge.h" resolved

#include "ArchGauge.h"
#include "ui_ArchGauge.h"


ArchGauge::ArchGauge(QWidget *parent) :
        QWidget(parent), ui(new Ui::ArchGauge)
{
    ui->setupUi(this);

    mArchGauge = new QcGaugeWidget;

    // drawing circular arc
    auto centerArc=mArchGauge->addArc(55);
    centerArc->setValueRange(-90,90);
    centerArc->setDegreeOffset(90);
    centerArc->setDegreeRange(-90,90);

    // drawing ticks
    auto centerArcTicks = mArchGauge->addDegrees(65);
    centerArcTicks->setValueRange(-90,90);
    centerArcTicks->setDegreeOffset(0);
    centerArcTicks->setDegreeRange(-90,90);
    centerArcTicks->setStep(10);
    centerArcTicks->setSubDegree(true);

    // drawing step values
    auto itemValues = mArchGauge->addValues(75);
    itemValues->setValueRange(-90,90);
    itemValues->setDegreeOffset(0);
    itemValues->setDegreeRange(-90,90);
    itemValues->setStep(30);

    mArchGauge->addLabel(10)->setText("Pitch");
    auto lab = mArchGauge->addLabel(25);
    lab->setText("0");

    mArchNeedle = mArchGauge->addNeedle(50);
    mArchNeedle->setLabel(lab);
    mArchNeedle->setColor(Qt::gray);
    mArchNeedle->setValueRange(-90,90);
    mArchNeedle->setDegreeOffset(0);
    mArchNeedle->setDegreeRange(-90,90);
    mArchNeedle->setCurrentValue(0);

    ui->verticalLayout->addWidget(mArchGauge);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &ArchGauge::valueChangedSlot);

}

ArchGauge::~ArchGauge() {
    delete ui;
}

void ArchGauge::valueChangedSlot(int value)
{
    mArchNeedle->setCurrentValue(value);
}
