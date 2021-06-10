/***************************************************************************
**                                                                        **
**  QcGauge, for instrumentation, and real time data measurement          **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2015 Hadj Tahar Berrima                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Hadj Tahar Berrima                                  **
**           Website: http://pytricity.com/                               **
**           Contact: berrima_tahar@yahoo.com                             **
**           Date:    1 dec 2014                                          **
**           Version:  1.0                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the gauge widget
    mAirspeedGauge = new QcGaugeWidget;

    // Add a 225 degrees arc
    mAirspeedGauge->addArc(55);

    // Add tics from 0 to 100 (by default one tic each 10) and set the range between 0 and 100
    mAirspeedGauge->addDegrees(65)->setValueRange(0,100);

    // Add a color band
    auto clrBand = mAirspeedGauge->addColorBand(50);

    // Set colors between 0 and 100
    clrBand->setValueRange(0,100);

    // Add values and set the range between 0 and 100 (by default one each 10)
    mAirspeedGauge->addValues(80)->setValueRange(0,100);

    // Add a label and set the text
    mAirspeedGauge->addLabel(70)->setText("Km/h");

    // Add a label (to be connected to the needle)
    auto lab = mAirspeedGauge->addLabel(40);

    // Set the label as 0
    lab->setText("0");

    // Add a new needle
    mAirspeedNeedle = mAirspeedGauge->addNeedle(60);

    // Assign the label to the needle
    mAirspeedNeedle->setLabel(lab);

    // Set the needle color
    mAirspeedNeedle->setColor(Qt::blue);

    // Set the needle values' range
    mAirspeedNeedle->setValueRange(0,100);

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
