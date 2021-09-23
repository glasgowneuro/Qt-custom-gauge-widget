//
// Created by filippo on 10/07/21.
//

#ifndef QCGAUGEWIDGET_BARGAUGE_H
#define QCGAUGEWIDGET_BARGAUGE_H

#include <Qt>
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include "qcgaugewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BarGauge; }
QT_END_NAMESPACE

class BarGauge : public QWidget {

    Q_OBJECT
 public:
    explicit BarGauge(QWidget *parent = nullptr);
    ~BarGauge() override;
    QcHorizontalBar* hBarGauge ;

private:
    Ui::BarGauge *ui;

    double currentValue; //current value
private slots:
    void valueChangeSlot(int value);

Q_SIGNALS:
    void valueChanged(double value);
};


#endif //QCGAUGEWIDGET_BARGAUGE_H




