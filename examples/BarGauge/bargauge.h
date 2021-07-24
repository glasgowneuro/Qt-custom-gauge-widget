//
// Created by filippo on 10/07/21.
//

#ifndef QCGAUGEWIDGET_BARGAUGE_H
#define QCGAUGEWIDGET_BARGAUGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class BarGauge; }
QT_END_NAMESPACE

class BarGauge : public QWidget {
Q_OBJECT

public:
    explicit BarGauge(QWidget *parent = nullptr);

    ~BarGauge() override;

private:
    Ui::BarGauge *ui;
};


#endif //QCGAUGEWIDGET_BARGAUGE_H
