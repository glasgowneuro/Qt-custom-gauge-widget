//
// Created by filippo on 27/09/21.
//

#ifndef QCGAUGEWIDGET_VERTICALBARGAUGE_H
#define QCGAUGEWIDGET_VERTICALBARGAUGE_H

#include <QWidget>
#include <qcgaugewidget.h>
#include <QLabel>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui { class verticalbargauge; }
QT_END_NAMESPACE

class verticalbargauge : public QWidget {

    Q_OBJECT
public:
    explicit verticalbargauge(QWidget *parent = nullptr);
    ~verticalbargauge() override;
    QcBar* vBarGauge ;
    QLabel* valueLabel;
    QSlider* verticalSlider;


private:
    Ui::verticalbargauge *ui;
    double _currentValue; //current value

private slots:
    void valueChangeSlot(int value);

Q_SIGNALS:
    void valueChanged(double value);
};


#endif //QCGAUGEWIDGET_VERTICALBARGAUGE_H
