
#ifndef QCIRCULARBAR_H
#define QCIRCULARBAR_H

#include <Qt>
#include <QWidget>
#include <QLCDNumber>
#include <QPropertyAnimation>

class QColor;

class QCircularBar : public QWidget
{
 Q_OBJECT
    Q_ENUMS(errorCode);

public:

    enum ErrorCode {MaxValueError=1,MinValueError,ThresholdError,TargetError,PrecisionError,ColorError,UnitsEmpty,OutOfRange};


    QCircularBar(QWidget *parent = 0);
    ~QCircularBar();

    double value() const { return m_value; }
    double minValue() const { return m_minValue; }
    double maxValue() const { return m_maxValue; }
    double threshold() const { return m_threshold; }
    int precision() const { return m_precision; }
    QString label()const { return m_label; }
    QString units()const { return m_units; }
    int steps() const { return m_steps; }
    int startAngle()  { return m_startAngle;}
    int endAngle()  { return m_endAngle; }
    QColor foreground() const { return m_foreground; }
    QColor background() const { return m_background; }
    bool thresholdEnabled() const { return m_thresholdEnabled; }
    bool enableNumericIndicator() const { return m_numericIndicatorEnabled; }
    bool circularBarEnabled() const {return m_circularBarEnabled; };
    bool coverGlassEnabled() const {return m_coverGlassEnabled;};
    int digitCount() const;
    int barSize() const {return m_barSize;};

signals:
    void errorSignal(int);
    void thresholdAlarm(bool);

public slots:
    void setValue(double);
    void setValue(int);
    void setMinValue(double);
    void setMinValue(int);
    void setMaxValue(double);
    void setMaxValue(int);
    void setThreshold(double);
    void setThreshold(int);
    void setPrecision(int);
    void setLabel(QString);
    void setUnits(QString);
    void setSteps(int);
    void setStartAngle(int);
    void setEndAngle(int);
    void setForeground(QColor);
    void setBackground(QColor);
    void setThresholdEnabled(bool);
    void setNumericIndicatorEnabled(bool);
    void setCircularBarEnabled(bool);
    void setCoverGlassEnabled(bool);
    void setDigitCount(int n_digits);
    void setBarSize(int barSize);

protected:
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void changeEvent(QEvent * event);

private:

    void thresholdManager();
    int digits(int val);  
    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawTicks(QPainter *painter);
    void drawCircularBar(QPainter *painter);
    void drawCoverGlass(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawUnits(QPainter *painter);
    void drawThresholdLine(QPainter *painter);

    double m_value;
    double m_maxValue, m_minValue;
    int m_precision;
    QString m_label;
    QString m_units;
    int m_steps;
    int m_barSize;
    int m_startAngle,m_endAngle;
    double m_threshold;
    bool m_autodigits;
    bool m_thresholdEnabled;
    bool m_numericIndicatorEnabled;
    bool m_circularBarEnabled;
    bool m_coverGlassEnabled;
    QColor m_foreground;
    QColor m_background;
    QLCDNumber* m_lcd;
};


#endif // QCIRCULARBAR_H
