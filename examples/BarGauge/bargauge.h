//
// Created by filippo on 24/09/21.
//

#ifndef QCGAUGEWIDGET_BARGAUGE_H
#define QCGAUGEWIDGET_BARGAUGE_H

#include <qcgaugewidget.h>
#include <QLabel>

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
    double _currentValue; //current value
private slots:
    void valueChangeSlot(int value);

    Q_SIGNALS:
            void valueChanged(double value);
};

#endif //QCGAUGEWIDGET_BARGAUGE_H
