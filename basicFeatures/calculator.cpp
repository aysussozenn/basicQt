#include "calculator.h"
#include "ui_calculator.h"
#include <QPushButton>


double result =0.0;
bool divide = false;
bool add = false;
bool multiply = false;
bool substract = false;
Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    QPushButton *numbers[10];
    for(int i=0 ;i<10;i++){
        QString buttonName = "pushButton_"+ QString::number(i);
        numbers[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numbers[i],SIGNAL(released()),this,SLOT(numPressed()));

    }
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(mathOperationsPressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(mathOperationsPressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(mathOperationsPressed()));
    connect(ui->pushButton_substract,SIGNAL(released()),this,SLOT(mathOperationsPressed()));
    connect(ui->pushButton_equals,SIGNAL(released()),this,SLOT(equalsPressed()));
    connect(ui->pushButton_sign,SIGNAL(released()),this,SLOT(sign()));
    connect(ui->pushButton_C,SIGNAL(released()),this,SLOT(clearAll()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(percent()));
    connect(ui->pushButton_dot,SIGNAL(released()),this,SLOT(dot()));



}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator :: numPressed(){
    QPushButton *button = (QPushButton*)sender();
    QString value = button->text();
    QString display = ui->label_result->text();
    if((display.toDouble()==0) || (display.toDouble()==0.0)){
        ui->label_result->setText(value);
    }
    else{
        QString newValue = display+value;
        double finalResult = newValue.toDouble();
        ui->label_result->setText(QString::number(finalResult,'g',16));
    }

}

void Calculator :: mathOperationsPressed(){
    divide = false;
    add = false;
    multiply = false;
    substract = false;
    QString display = ui->label_result->text();
    result = display.toDouble();
    QPushButton *button = (QPushButton*)sender();
    QString value = button->text();
    if(QString::compare(value,"/",Qt::CaseInsensitive)==0){
        divide=true;
    }
    else if(QString::compare(value,"X",Qt::CaseInsensitive)==0){
        multiply=true;
    }
    else if(QString::compare(value,"+",Qt::CaseInsensitive)==0){
        add=true;
    }
    else if(QString::compare(value,"-",Qt::CaseInsensitive)==0){
        substract=true;
    }
    ui->label_result->setText("");

}

void Calculator :: equalsPressed(){
    double finalResult=0.0;
    QString currentNum = ui->label_result->text();
    double currentNumDouble = currentNum.toDouble();
    if(add){
        finalResult = result+currentNumDouble;
    }
    else if(substract){
        finalResult = result-currentNumDouble;
    }
    else if(multiply){
        finalResult = result*currentNumDouble;
    }
    else if(divide){
        finalResult = result/currentNumDouble;
    }
    ui->label_result->setText(QString::number(finalResult));

}
void Calculator :: sign(){
    QPushButton *button = (QPushButton*)sender();
    double sign;
    QString newValue;
    if(button->text()=="+/-"){
        sign = ui->label_result->text().toDouble() * -1;
        newValue = QString::number(sign);
        ui->label_result->setText(newValue);
    }

}

void Calculator :: percent(){
    QPushButton *button = (QPushButton*)sender();
    double sign;
    QString newValue;
    if(button->text()=="%"){
        sign = ui->label_result->text().toDouble() * 0.01;
        newValue = QString::number(sign);
        ui->label_result->setText(newValue);
    }

}

void Calculator ::clearAll(){
    ui->label_result->setText("");
}

void Calculator :: dot(){
    QPushButton *button = (QPushButton*)sender();
    QString sign;
    double newDouble;
    QString newValue;
    if(button->text().contains(".")){
        sign = ui->label_result->text()+button->text();
        newDouble = sign.toDouble();
        newValue = QString::number(newDouble);
        ui->label_result->setText(sign);
    }
}
