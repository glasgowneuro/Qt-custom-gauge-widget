#include "button.h"
#include "./ui_button.h"
#include <qfile.h>

Button::Button(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Button)
{
    ui->setupUi(this);
    QFile file(":/qss/Button.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

Button::~Button()
{
    delete ui;
}
void Button::setTextLabel(const QString& text)
{
    ui->buttonLabel->setText(text);
}
