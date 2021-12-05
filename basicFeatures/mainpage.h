#ifndef MAINPAGE_H
#define MAINPAGE_H


#include <QMainWindow>
#include "calculator.h"
#include "bmi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainPage; }
QT_END_NAMESPACE

class mainPage : public QMainWindow
{
    Q_OBJECT

public:
    mainPage(QWidget *parent = nullptr);
    ~mainPage();

private slots:
    void pressCalc();
    void pressBmi();
private:
    Ui::mainPage *ui;
    Calculator *calculator;
    Bmi *bmi;



};
#endif // MAINPAGE_H
