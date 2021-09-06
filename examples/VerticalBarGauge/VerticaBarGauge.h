//
// Created by filippo on 17/08/21.
//

#ifndef QCGAUGEWIDGET_VERTICABARGAUGE_H
#define QCGAUGEWIDGET_VERTICABARGAUGE_H

#include <Qt>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class VerticalBarGauge; }
QT_END_NAMESPACE

class VerticalBarGauge : public QWidget {
    Q_OBJECT

public:
    explicit VerticalBarGauge(QWidget *parent = nullptr);

    ~VerticalBarGauge() override;
protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawRulerLeft(QPainter *painter);
    void drawRulerRight(QPainter *painter);

private:
    Ui::VerticalBarGauge *ui;
    double _minValue=0; //minimum
    double _maxValue=0; //maximum
    double _value=0; //target value
    int _precision=0; //_precision, a few decimal places

    int _longStep=0; //long line equal division step
    int _shortStep=0; //short line equal step size
    bool _rulerLeft= false; //the tick is on left
    bool _rulerRight= false; //the tick is on right

    bool _animation= false; // whether to enable _animation display
    double _animationStep=0; // _animation display step size

    QColor _bgColor; //background color
    QColor _lineColor; //Line color
    QColor _progressColor; // progress color

    double _currentValue; //current value

private slots:
    void valueChangeSlot(int value);
public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    int getLongStep()               const;
    int getShortStep()              const;
    bool getRulerLeft()             const;
    bool getRulerRight()            const;


    bool getAnimation()             const;
    double getAnimationStep()       const;

    QColor getBgColor()             const;
    QColor getLineColor()           const;
    QColor getProgressColor()       const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    // Set the range value
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    // Set the maximum and minimum
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    // Set the target value
    void setValue(double value);
    void setValue(int value);

    // Set the accuracy
    void setPrecision(int precision);
    // Set the line equal step size
    void setLongStep(int longStep);
    void setShortStep(int shortStep);
    // Set the scale on the left
    void setRulerLeft(bool rulerLeft);
    // Set the scale on the right
    void setRulerRight(bool rulerRight);

    // Set whether to enable _animation display
    void setAnimation(bool animation);
    // Set the step size of the _animation display
    void setAnimationStep(double animationStep);

    // Set the background color
    void setBgColor(const QColor &bgColor);
    // Set the line color
    void setLineColor(const QColor &lineColor);
    // Set the progress color
    void setProgressColor(const QColor &progressColor);

Q_SIGNALS:
    void valueChanged(double value);
};


#endif //QCGAUGEWIDGET_VERTICABARGAUGE_H
