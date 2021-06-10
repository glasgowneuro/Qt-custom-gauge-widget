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

    mWindGauge = new QcGaugeWidget;
    auto itemArc=mWindGauge->addArc(55);
    itemArc->setValueRange(-180,180);
    itemArc->setDegreeOffset(90);
    itemArc->setDegreeRange(-180,180);


    auto itemDegrees = mWindGauge->addDegrees(65);
    itemDegrees->setValueRange(-180,180);
    itemDegrees->setDegreeOffset(90);
    itemDegrees->setDegreeRange(-180,180);
    itemDegrees->setStep(10);
    itemDegrees->setSubDegree(true);



    QcColorBand *clrBandPort = mWindGauge->addColorBand(50);
    clrBandPort->setValueRange(-60,-20);
    clrBandPort->setDegreeRange(-60,-20);
    clrBandPort->setDegreeOffset(90);

    QList<QPair<QColor,float>> pairsPort;
    pairsPort.append(QPair<QColor,float>(Qt::red, -60));
    pairsPort.append(QPair<QColor,float>(Qt::red, -20));

    clrBandPort->setColors(pairsPort);

    QcColorBand *clrBandStarboard = mWindGauge->addColorBand(50);
    clrBandStarboard->setValueRange(20,60);
    clrBandStarboard->setDegreeRange(20,60);
    clrBandStarboard->setDegreeOffset(90);

    QList<QPair<QColor,float>> pairsStarboard;
    pairsStarboard.append(QPair<QColor,float>(Qt::darkGreen, 20));
    pairsStarboard.append(QPair<QColor,float>(Qt::darkGreen, 60));

    clrBandStarboard->setColors(pairsStarboard);

    auto itemValues = mWindGauge->addValues(80);
    itemValues->setValueRange(-150,150);
    itemValues->setDegreeOffset(90);
    itemValues->setDegreeRange(-150,150);
    itemValues->setStep(30);

    mWindGauge->addLabel(70)->setText("AWA°");
    QcLabelItem *lab = mWindGauge->addLabel(40);
    lab->setText("0");

    mWindNeedle = mWindGauge->addNeedle(60);
    mWindNeedle->setLabel(lab);
    mWindNeedle->setColor(Qt::blue);

    mWindNeedle->setValueRange(-180,180);
    mWindNeedle->setDegreeOffset(90);
    mWindNeedle->setDegreeRange(-180,180);

    mWindGauge->addBackground(7);
    ui->horizontalLayout->addWidget(mWindGauge);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mWindNeedle->setCurrentValue(value);
}
