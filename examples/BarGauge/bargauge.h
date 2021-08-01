//
// Created by filippo on 10/07/21.
//

#ifndef QCGAUGEWIDGET_BARGAUGE_H
#define QCGAUGEWIDGET_BARGAUGE_H

#include <Qt>
#include <QWidget>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class BarGauge; }
QT_END_NAMESPACE

class BarGauge : public QWidget {

    Q_OBJECT
    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(bool rulerTop READ getRulerTop WRITE setRulerTop)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)


public:
    explicit BarGauge(QWidget *parent = nullptr);

    ~BarGauge() override;
protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawRulerTop(QPainter *painter);
    void drawRulerBottom(QPainter *painter);

private:
    Ui::BarGauge *ui;
    double minValue; //minimum
    double maxValue; //maximum
    double value; //target value
    int precision; //precision, a few decimal places

    int longStep; //long line equal division step
    int shortStep; //short line equal step size
    bool rulerTop; //the tick is above
    bool rulerBottom; //the tick is under

    bool animation; // whether to enable animation display
    double animationStep; // animation display step size

    QColor bgColor; //background color
    QColor lineColor; //Line color
    QColor progressColor; // progress color

    bool reverse; //regression
    double currentValue; //current value
    QTimer *timer; //Timer draw animation
    QProgressBar* m_prgbar;

private slots:
    void valueChangeSlot(int value);
public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    int getLongStep()               const;
    int getShortStep()              const;
    bool getRulerTop()              const;
    bool getRulerBottom()           const;

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
    // Set the scale on the top
    void setRulerTop(bool rulerTop);
    // Set the scale on the bottom
    void setRulerBottom(bool rulerBottom);

    // Set whether to enable animation display
    void setAnimation(bool animation);
    // Set the step size of the animation display
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


#endif //QCGAUGEWIDGET_BARGAUGE_H




