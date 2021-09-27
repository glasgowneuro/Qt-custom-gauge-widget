//
// Created by filippo on 10/07/21.
//

#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include "qcgaugewidget.h"
#include "bargauge.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QWidget *widget = new QWidget;
    QHBoxLayout layout;
    widget->setLayout(&layout);
    widget->setMinimumSize(450,130);

    QcHorizontalBar* hBarGauge =  new QcHorizontalBar(widget);
    hBarGauge->setBgColor(Qt::darkGray);
    hBarGauge->setProgressColor(Qt::darkBlue);
    hBarGauge->setLineColor(Qt::white);
    hBarGauge->setRange(-45,45);
    hBarGauge->setPrecision(1);
    hBarGauge->setShortStep(1);
    hBarGauge->setLongStep(10);
    hBarGauge->setRulerTop(true);
    hBarGauge->setRulerBottom(true);

    QSlider* verticalSlider = new QSlider(widget);
    verticalSlider->setMinimum(-45);
    verticalSlider->setMaximum(45);
    verticalSlider->setValue(0);

    layout.addWidget(hBarGauge);
    layout.addWidget(verticalSlider);

    widget->show();
*/
    BarGauge *b=new BarGauge(0);
    b->show();
    return a.exec();
}
