#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "qcgaugewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QcGaugeWidget * mSpeedGauge;
    QcNeedleItem *mAWANeedle;
    QcNeedleItem * mCOGNeedle;
    QcNeedleItem *mTempNeedle;

signals:

};

#endif // MAINWINDOW_H
