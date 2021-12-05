#include "mainpage.h"
#include "ui_mainpage.h"
#include <QPixmap>
#include "calculator.h"

mainPage::mainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainPage)
{
    ui->setupUi(this);
    QPixmap pixCalc(":/img/img/Apple_Hesap_makinesi_Calculator-icon.png");
    QPixmap pixBmi(":/img/img/bmi.png");
    int widthLabelCalc= ui->label_Calc->width();
    int widthLabelBmi= ui->label_BMI->width();
    int heightLabelCalc= ui->label_Calc->height();
    int heightLabelBmi= ui->label_BMI->height();

    ui->label_Calc->setPixmap(pixCalc.scaled(widthLabelCalc,heightLabelCalc,Qt::KeepAspectRatio));
    ui->label_BMI->setPixmap(pixBmi.scaled(widthLabelBmi,heightLabelBmi,Qt::KeepAspectRatio));

    connect(ui->pushButton_Calculator,SIGNAL(released()),this,SLOT(pressCalc()));
    connect(ui->pushButton_BMI,SIGNAL(released()),this,SLOT(pressBmi()));


}

mainPage::~mainPage()
{
    delete ui;
}

void mainPage :: pressCalc()
{

  calculator = new Calculator(this);
  calculator->show();

}
void mainPage :: pressBmi(){
    bmi = new Bmi(this);
    bmi->show();
}

