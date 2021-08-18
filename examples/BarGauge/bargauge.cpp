//
// Created by filippo on 10/07/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BarGauge.h" resolved

#include <QPainter>
#include "bargauge.h"
#include "ui_bargauge.h"

BarGauge::BarGauge(QWidget *parent) :QWidget(parent), ui(new Ui::BarGauge)
{
    setBgColor(Qt::darkGray);
    setProgressColor(Qt::darkBlue);
    setLineColor(Qt::white);
    setRange(1,100);
    setAnimation(true);
    setPrecision(1);
    setShortStep(1);
    setLongStep(10);
    setRulerTop(true);
    setRulerBottom(true);
    //setEnabled(true);
    ui->setupUi(this);
    connect(ui->verticalSlider, &QSlider::valueChanged,this,&BarGauge::valueChangeSlot);
}

BarGauge::~BarGauge() {
    delete ui;
}
void BarGauge::valueChangeSlot(int value)
{
    currentValue=value;
    repaint();
}
void BarGauge::paintEvent(QPaintEvent *)
{
    // draw the preparation work, enable anti-aliasing
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    // draw a gradient background
    drawBg(&painter);
    // draw progress
    drawProgress(&painter);
    // draw a ruler
    if (rulerTop)   drawRulerTop(&painter);
    if(rulerBottom) drawRulerBottom(&painter);

}

void BarGauge::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(lineColor);
    painter->setBrush(bgColor);
    painter->drawRect(rect());
    painter->restore();
}

void BarGauge::drawProgress(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(progressColor);

    double length = width();
    double increment = length / (maxValue - minValue);
    double initX = (currentValue - minValue) * increment;

    QRect rect(0, 0, initX, height());
    painter->drawRect(rect);
    painter->restore();
}

void BarGauge::drawRulerTop(QPainter *painter)
{
    painter->save();
    painter->setPen(lineColor);

    double initX = 0;

    // draw a part of the bottom line on the horizontal ruler
    double initTopY = 0;
    QPointF lineTopLeftPot = QPointF(initX, initTopY);
    QPointF lineTopRightPot = QPointF(width() - initX, initTopY);
    painter->drawLine(lineTopLeftPot, lineTopRightPot);

    // draw the upper part and the lower part of the horizontal ruler scale
    double length = width();
    // Calculate how much each cell moves
    double increment = length / (maxValue - minValue);
    //Long line short line length
    int longLineLen = 15;
    int shortLineLen = 10;

    //Draw scale value and scale value according to range value. Long line needs to move 10 pixels. Short line needs to move 5 pixels.
    for (int i = minValue; i <= maxValue; i = i + shortStep) {
        if (i % longStep == 0) {
            QPointF topPot = QPointF(initX, initTopY);
            QPointF bottomPot = QPointF(initX, initTopY + longLineLen);
            painter->drawLine(topPot, bottomPot);

            // The first value and the last value do not draw
            if (i == minValue || i == maxValue) {
                initX += increment * shortStep;
                continue;
            }

            QString strValue = QString("%1").arg((double)i, 0, 'f', precision);
            double textWidth = fontMetrics().width(strValue);
            double textHeight = fontMetrics().height();

            QPointF textPot = QPointF(initX - textWidth / 2, initTopY + textHeight + longLineLen);
            painter->drawText(textPot, strValue);
        } else {
            if (i % (longStep / 2) == 0) {
                shortLineLen = 10;
            } else {
                shortLineLen = 6;
            }

            QPointF topPot = QPointF(initX, initTopY);
            QPointF bottomPot = QPointF(initX, initTopY + shortLineLen);
            painter->drawLine(topPot, bottomPot);
        }

        initX += increment * shortStep;
    }

    painter->restore();
}

void BarGauge::drawRulerBottom(QPainter *painter)
{
    painter->save();
    painter->setPen(lineColor);

    double initX = 0;

    // draw the bottom line of the lower part of the horizontal ruler
    double initBottomY = height();
    QPointF lineBottomLeftPot = QPointF(initX, initBottomY);
    QPointF lineBottomRightPot = QPointF(width() - initX, initBottomY);
    painter->drawLine(lineBottomLeftPot, lineBottomRightPot);

    // draw the upper part and the lower part of the horizontal ruler scale
    double length = width();
    // Calculate how much each cell moves
    double increment = length / (maxValue - minValue);
    //Long line short line length
    int longLineLen = 15;
    int shortLineLen = 10;

    //Draw scale value and scale value according to range value. Long line needs to move 10 pixels. Short line needs to move 5 pixels.
    for (int i = minValue; i <= maxValue; i = i + shortStep) {
        if (i % longStep == 0) {
            QPointF topPot = QPointF(initX, initBottomY);
            QPointF bottomPot = QPointF(initX, initBottomY - longLineLen);
            painter->drawLine(topPot, bottomPot);

            // The first value and the last value do not draw
            if (i == minValue || i == maxValue) {
                initX += increment * shortStep;
                continue;
            }

            QString strValue = QString("%1").arg((double)i, 0, 'f', precision);
            double textWidth = fontMetrics().width(strValue);
            double textHeight = fontMetrics().height();

            QPointF textPot = QPointF(initX - textWidth / 2, initBottomY - textHeight / 2 - longLineLen);
            painter->drawText(textPot, strValue);
        } else {
            if (i % (longStep / 2) == 0) {
                shortLineLen = 10;
            } else {
                shortLineLen = 6;
            }

            QPointF topPot = QPointF(initX, initBottomY);
            QPointF bottomPot = QPointF(initX, initBottomY - shortLineLen);
            painter->drawLine(topPot, bottomPot);
        }

        initX += increment * shortStep;
    }

    painter->restore();
}
double BarGauge::getMinValue() const{ return minValue;}
double BarGauge::getMaxValue() const{return maxValue;}
double BarGauge::getValue() const{ return value;}
double BarGauge::getAnimationStep() const{return animationStep;}
int BarGauge::getPrecision() const{return precision;}
int BarGauge::getLongStep() const{return longStep;}
int BarGauge::getShortStep() const{return shortStep;}
bool BarGauge::getRulerTop() const{return rulerTop;}
bool BarGauge::getRulerBottom() const{return rulerBottom;}

bool BarGauge::getAnimation() const{return animation;}
QColor BarGauge::getBgColor() const{return bgColor;}
QColor BarGauge::getLineColor() const{return lineColor;}
QColor BarGauge::getProgressColor() const{return progressColor;}
QSize BarGauge::sizeHint() const{return minimumSize();}
QSize BarGauge::minimumSizeHint() const{return minimumSizeHint();}


void BarGauge::setRange(double MinValue, double MaxValue){minValue = MinValue; maxValue = MaxValue;}
void BarGauge::setRange(int MinValue, int MaxValue){ minValue = MinValue; maxValue = MaxValue;}
void BarGauge::setMinValue(double MinValue){ minValue=MinValue; }
void BarGauge::setMaxValue(double MaxValue){ maxValue = MaxValue;}
void BarGauge::setValue(double Value){value = Value;}
void BarGauge::setValue(int Value){value = Value;}
void BarGauge::setPrecision(int Precision){precision =Precision;}
void BarGauge::setLongStep(int LongStep){longStep = LongStep;}
void BarGauge::setShortStep(int ShortStep){shortStep= ShortStep;}
void BarGauge::setRulerTop(bool RulerTop){rulerTop=RulerTop;}
void BarGauge::setRulerBottom(bool RulerBottom){rulerBottom=RulerBottom;}
void BarGauge::setAnimation(bool Animation){animation = Animation;}
void BarGauge::setAnimationStep(double AnimationStep){animationStep = AnimationStep;}
void BarGauge::setBgColor(const QColor &BgColor){bgColor = BgColor;}
void BarGauge::setLineColor(const QColor &LineColor){lineColor = LineColor;}
void BarGauge::setProgressColor(const QColor &ProgressColor){progressColor = ProgressColor;}

