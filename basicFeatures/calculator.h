#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void numPressed();
    void mathOperationsPressed();
    void equalsPressed();
    void clearAll();
    void sign();
    void percent();
    void dot();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
