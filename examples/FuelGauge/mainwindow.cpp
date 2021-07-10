#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the gauge widget
    mAirspeedGauge = new QcGaugeWidget;

    // Add background
    mAirspeedGauge->addBackground(99);

    // Add color to background
    QcBackgroundItem *bkg2 = mAirspeedGauge->addBackground(90);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::lightGray);
    bkg2->addColor(1.0,Qt::white);

    // Add a 225 degrees arc
    mAirspeedGauge->addArc(55);

    // Add tics from 0 to 100 (by default one tic each 10) and set the range between 0 and 100
    mAirspeedGauge->addDegrees(65)->setValueRange(0,100);

    // Add values and set the range between 0 and 100 (by default one each 10)
    mAirspeedGauge->addValues(80)->setValueRange(0,100);

    // Add and set value range of a color band
    auto *clrBandPort = mAirspeedGauge->addColorBand(50);
    clrBandPort->setValueRange(0,100);

    // Set colors between 0 and 100
    QList<QPair<QColor,float>> pairsPort;
    pairsPort.append(QPair<QColor,float>(Qt::red, 100));
    pairsPort.append(QPair<QColor,float>(Qt::darkGreen, 50));
    pairsPort.append(QPair<QColor,float>(Qt::yellow, 20));
    clrBandPort->setColors(pairsPort);

    // Add a label and set the text
    mAirspeedGauge->addLabel(65)->setText("%");

    // Add a label (to be connected to the needle)
    auto lab = mAirspeedGauge->addLabel(40);

    // Set the label as 0
    lab->setText("100");

    // Add a new needle
    mAirspeedNeedle = mAirspeedGauge->addNeedle(60);

    // Assign the label to the needle
    mAirspeedNeedle->setLabel(lab);

    // Set the needle color
    mAirspeedNeedle->setColor(Qt::blue);

    // Set the needle values' range
    mAirspeedNeedle->setValueRange(0,100);
    mAirspeedNeedle->setCurrentValue(100);

    // Add the widget to the horizontalLayout
    ui->horizontalLayout->addWidget(mAirspeedGauge);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mAirspeedNeedle->setCurrentValue(value);
}
