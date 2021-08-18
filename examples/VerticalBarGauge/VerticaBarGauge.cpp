//
// Created by filippo on 17/08/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_verticalbargauge.h" resolved
#include <QPainter>
#include <iostream>
#include "VerticaBarGauge.h"
#include "ui_verticalbargauge.h"


VerticalBarGauge::VerticalBarGauge(QWidget *parent) :
        QWidget(parent), ui(new Ui::VerticalBarGauge) {

    setBgColor(Qt::darkGray);
    setProgressColor(Qt::darkBlue);
    setLineColor(Qt::white);
    setRange(1,100);
    setAnimation(true);
    setPrecision(1);
    setShortStep(1);
    setLongStep(10);
    setRulerLeft(true);
    setRulerRight(true);
    ui->setupUi(this);
    ui->_valueLabel->setStyleSheet("QLabel {color: white;}");
    connect(ui->verticalSlider, &QSlider::valueChanged, this, &VerticalBarGauge::valueChangeSlot);
}

VerticalBarGauge::~VerticalBarGauge() {
    delete ui;
}

void VerticalBarGauge::valueChangeSlot(int value)
{
    _currentValue=value;
    ui->_valueLabel->setText(QString::number(value)+ "%");

    repaint();
}

void VerticalBarGauge::paintEvent(QPaintEvent *)
{
    // draw the preparation work, enable anti-aliasing
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    // draw a gradient background
    drawBg(&painter);
    // draw progress
    drawProgress(&painter);
    // draw a ruler
    if (_rulerLeft) drawRulerLeft(&painter);
    if (_rulerRight) drawRulerRight(&painter);


}

void VerticalBarGauge::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(_lineColor);
    painter->setBrush(_bgColor);
    painter->drawRect(rect());
    painter->restore();
}

void VerticalBarGauge::drawProgress(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(_progressColor);

    double length = height();
    double increment = length / (_maxValue - _minValue);
    double initX = (_currentValue - _minValue) * increment;
    std::cout<<initX<<std::endl;
    QRect rect(0, height()-initX, width(), initX);
    painter->drawRect(rect);
    painter->restore();
}

void VerticalBarGauge::drawRulerLeft(QPainter *painter)
{
    painter->save();
    painter->setPen(_lineColor);

    double x = 0;
    double y = height();

    QPointF lineTopLeftPot = QPointF(x, y);
    QPointF lineBottomLeftPot = QPointF(x, y+height());
    painter->drawLine(lineBottomLeftPot,lineTopLeftPot);

    double length = height();
    // Calculate how much each cell moves
    double increment = length / (_maxValue - _minValue);
    //Long line short line length
    int longLineLen = 15;
    int shortLineLen = 10;

    //Draw scale value according to range value. Long line needs to move 10 pixels and short line needs to move 5 pixels.
    for (int i = _minValue; i <= _maxValue; i = i + _shortStep) {
        if (i % _longStep == 0) {
            QPointF leftPoint = QPointF(x, y);
            QPointF rightPoint = QPointF(x + longLineLen, y);
            painter->drawLine(leftPoint, rightPoint);

            // The first value and the last value do not draw
            if (i == _minValue || i == _maxValue) {
                y -= increment * _shortStep;
                continue;
            }

            QString strValue = QString("%1").arg((double)i, 0, 'f', _precision);
            double textWidth = fontMetrics().width(strValue);
            double textHeight = fontMetrics().height();

            //QPointF textPot = QPointF(x - textWidth / 2, y + textHeight + longLineLen);
            QPointF textPot = QPointF(x + textWidth/3 +longLineLen , y +textHeight/4);

            painter->drawText(textPot, strValue);
        } else {
            if (i % (_longStep / 2) == 0) {
                shortLineLen = 10;
            } else {
                shortLineLen = 6;
            }

            QPointF leftP = QPointF(x, y);
            QPointF rightP = QPointF(x+ shortLineLen, y );
            painter->drawLine(leftP, rightP);
        }

        y -= increment * _shortStep;
    }

    painter->restore();
}

void VerticalBarGauge::drawRulerRight(QPainter *painter) 
{
    painter->save();
    painter->setPen(_lineColor);

    double x = width();
    double y = height();
/*
    QPointF lineTopRightPot = QPointF(x, y);
    QPointF lineBottomRightPot = QPointF(x, height());
    painter->drawLine(lineBottomRightPot, lineTopRightPot);
*/

    double length = height();
    // Calculate how much each cell moves
    double increment = length / (_maxValue - _minValue);
    //Long line short line length
    int longLineLen = 15;
    int shortLineLen = 10;

    //Draw scale value according to range value. Long line needs to move 10 pixels. Short line needs to move 5 pixels.
    for (int i = _minValue; i <= _maxValue; i = i + _shortStep) {
        if (i % _longStep == 0) {

            QPointF leftPoint = QPointF(x - longLineLen, y);
            QPointF rightPoint = QPointF(x, y);
            painter->drawLine(rightPoint, leftPoint);

            // The first value and the last value do not draw
            if (i == _minValue || i == _maxValue) {
                y -= increment * _shortStep;
                continue;
            }

            QString strValue = QString("%1").arg((double)i, 0, 'f', _precision);
            double textWidth = fontMetrics().width(strValue);
            double textHeight = fontMetrics().height();

            QPointF textPot = QPointF(x - longLineLen*2.5 - textWidth/2, y+ textHeight/4);

            painter->drawText(textPot, strValue);
        } else {
            if (i % (_longStep / 2) == 0) {
                shortLineLen = 10;
            } else {
                shortLineLen = 6;
            }

            QPointF leftP = QPointF(x - shortLineLen, y );
            QPointF rightP = QPointF(x, y);
            painter->drawLine(rightP,leftP);
        }

        y -= increment * _shortStep;
    }

    painter->restore();
}

double VerticalBarGauge::getMinValue() const{ return _minValue;}
double VerticalBarGauge::getMaxValue() const{return _maxValue;}
double VerticalBarGauge::getValue() const{ return _value;}
double VerticalBarGauge::getAnimationStep() const{return _animationStep;}
int VerticalBarGauge::getPrecision() const{return _precision;}
int VerticalBarGauge::getLongStep() const{return _longStep;}
int VerticalBarGauge::getShortStep() const{return _shortStep;}
bool VerticalBarGauge::getRulerLeft() const{return _rulerLeft;}
bool VerticalBarGauge::getRulerRight() const{return _rulerRight;}


bool VerticalBarGauge::getAnimation() const{return _animation;}
QColor VerticalBarGauge::getBgColor() const{return _bgColor;}
QColor VerticalBarGauge::getLineColor() const{return _lineColor;}
QColor VerticalBarGauge::getProgressColor() const{return _progressColor;}
QSize VerticalBarGauge::sizeHint() const{return minimumSize();}
QSize VerticalBarGauge::minimumSizeHint() const{return minimumSizeHint();}


void VerticalBarGauge::setRange(double MinValue, double MaxValue){ _minValue = MinValue; _maxValue = MaxValue;}
void VerticalBarGauge::setRange(int MinValue, int MaxValue){ _minValue = MinValue; _maxValue = MaxValue;}
void VerticalBarGauge::setMinValue(double MinValue){ _minValue=MinValue; }
void VerticalBarGauge::setMaxValue(double MaxValue){ _maxValue = MaxValue;}
void VerticalBarGauge::setValue(double Value){_value = Value;}
void VerticalBarGauge::setValue(int Value){_value = Value;}
void VerticalBarGauge::setPrecision(int Precision){ _precision =Precision;}
void VerticalBarGauge::setLongStep(int LongStep){ _longStep = LongStep;}
void VerticalBarGauge::setShortStep(int ShortStep){ _shortStep= ShortStep;}
void VerticalBarGauge::setRulerLeft(bool RulerLeft){ _rulerLeft=RulerLeft;}
void VerticalBarGauge::setRulerRight(bool RulerRight){ _rulerRight=RulerRight;}

void VerticalBarGauge::setAnimation(bool Animation){ _animation = Animation;}
void VerticalBarGauge::setAnimationStep(double AnimationStep){ _animationStep = AnimationStep;}
void VerticalBarGauge::setBgColor(const QColor &BgColor){ _bgColor = BgColor;}
void VerticalBarGauge::setLineColor(const QColor &LineColor){ _lineColor = LineColor;}
void VerticalBarGauge::setProgressColor(const QColor &ProgressColor){ _progressColor = ProgressColor;}

