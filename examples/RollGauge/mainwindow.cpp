#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the gauge widget
    mRollGauge = new QcGaugeWidget;

    mRollGauge->addArc(55);
    mRollGauge->addDegrees(65)->setValueRange(-90, 90);
    mRollGauge->addValues(80)->setValueRange(-90, 90);

    mRollGauge->addLabel(65)->setText("Roll");
    auto lab = mRollGauge->addLabel(40);
    lab->setText("0");
    mRollNeedle = mRollGauge->addNeedle(60);
    mRollNeedle->setLabel(lab);
    mRollNeedle->setColor(Qt::black);
    mRollNeedle->setValueRange(-90, 90);
    mRollNeedle->setCurrentValue(0);

    // Add the widget to the horizontalLayout
    ui->horizontalLayout->addWidget(mRollGauge);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mRollNeedle->setCurrentValue(value);
}
