//
// Created by filippo on 04/07/21.
//

#ifndef QCGAUGEWIDGET_LCD_H
#define QCGAUGEWIDGET_LCD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class lcd; }
QT_END_NAMESPACE

class lcd : public QWidget {
Q_OBJECT

public:
    explicit lcd(QWidget *parent = nullptr);

    ~lcd() override;

private:
    Ui::lcd *ui;

private slots:
    void on_horizontalSlider_valueChanged(int value);
};


#endif //QCGAUGEWIDGET_LCD_H
