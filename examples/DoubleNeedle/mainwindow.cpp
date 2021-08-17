#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     mSpeedGauge = new QcGaugeWidget;
     //code for background
/*
     mSpeedGauge->addBackground(99);
     QcBackgroundItem *bkg1 = mSpeedGauge->addBackground(95);
     bkg1->clearrColors();
     bkg1->addColor(0.1,Qt::black);
     bkg1->addColor(1.0,Qt::lightGray);

     QcBackgroundItem *bkg2 = mSpeedGauge->addBackground(88);
     bkg2->clearrColors();
     bkg2->addColor(0.1,Qt::lightGray);
     bkg2->addColor(1.0,Qt::white);
*/

     // drawing circular arc
     auto centerArc=mSpeedGauge->addArc(55);
     centerArc->setValueRange(0,360);
     centerArc->setDegreeOffset(90);
     centerArc->setDegreeRange(0,360);

     // drawing ticks
     auto centerArcTicks = mSpeedGauge->addDegrees(65);
     centerArcTicks->setValueRange(0,360);
     centerArcTicks->setDegreeOffset(90);
     centerArcTicks->setDegreeRange(0,360);
     centerArcTicks->setStep(10);
     centerArcTicks->setSubDegree(false);

     // drawing step values
     auto itemValues = mSpeedGauge->addValues(80);
     itemValues->setValueRange(0,359);
     itemValues->setDegreeOffset(90);
     itemValues->setDegreeRange(0,359);
     itemValues->setStep(30);

     // add first needle
     mAWANeedle = mSpeedGauge->addNeedle(60);
     mAWANeedle->setColor(Qt::red);
     mAWANeedle->setValueRange(0,360);
     mAWANeedle->setDegreeOffset(90);
     mAWANeedle->setDegreeRange(0,360);
     mAWANeedle->setCurrentValue(60);

     // add second needle
     mCOGNeedle = mSpeedGauge->addNeedle(60);
     mCOGNeedle->setColor(Qt::blue);
     mCOGNeedle->setValueRange(0,60);
     mCOGNeedle->setDegreeOffset(90);
     mCOGNeedle->setDegreeRange(0,60);
     mCOGNeedle->setCurrentValue(20);

     // add tird needle
     mTempNeedle = mSpeedGauge->addNeedle(60);
     mTempNeedle->setColor(Qt::green);
     mTempNeedle->setValueRange(180,360);
     mTempNeedle->setDegreeOffset(90);
     mTempNeedle->setDegreeRange(180,360);
     mTempNeedle->setCurrentValue(324);

    ui->verticalLayout->addWidget(mSpeedGauge);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mAWANeedle->setCurrentValue(value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    mCOGNeedle->setCurrentValue(value);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    mTempNeedle->setCurrentValue(value);
}
