//
// Created by filippo on 18/08/21.
//

#ifndef QCGAUGEWIDGET_ARCHGAUGE_H
#define QCGAUGEWIDGET_ARCHGAUGE_H

#include <QWidget>
#include <qcgaugewidget.h>


QT_BEGIN_NAMESPACE
namespace Ui { class ArchGauge; }
QT_END_NAMESPACE

class ArchGauge : public QWidget {
Q_OBJECT

public:
    explicit ArchGauge(QWidget *parent = nullptr);
    ~ArchGauge() override;

private slots:
    void valueChangedSlot(int value);

private:
    Ui::ArchGauge *ui;
    QcGaugeWidget *mArchGauge;
    QcNeedleItem *mArchNeedle;
};


#endif //QCGAUGEWIDGET_ARCHGAUGE_H
