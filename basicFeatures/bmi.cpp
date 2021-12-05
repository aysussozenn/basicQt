#include "bmi.h"
#include "ui_bmi.h"


bool us = false;
bool metrics = false;
Bmi::Bmi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bmi)
{
    ui->setupUi(this);

    QPixmap pixBmi(":/img/img/bmi-about.png");
    int widthLabelBmi= ui->label_Bmi->width();
    int heightLabelBmi= ui->label_Bmi->height();
    ui->label_Bmi->setPixmap(pixBmi.scaled(widthLabelBmi,heightLabelBmi,Qt::KeepAspectRatio));
    ui->lineEdit_inch->setVisible(false);
    connect(ui->radioButton_Metrics,SIGNAL(released()),this,SLOT(radioButtonPressed()));
    connect(ui->radioButton_Us,SIGNAL(released()),this,SLOT(radioButtonPressed()));
    connect(ui->pushButton_Calculate,SIGNAL(released()),this,SLOT(calculateButtonPressed()));
    connect(ui->pushButton_Clear,SIGNAL(released()),this,SLOT(clearButtonPressed()));
}

void Bmi :: radioButtonPressed(){


    if(ui->radioButton_Metrics->isChecked()){
        ui->lineEdit_inch->setVisible(false);
        ui->label_feet->setVisible(false);
        ui->label__Weight->setText("kg");
        ui->label_height->setText("cm");
        metrics =true;
    }
    else if(ui->radioButton_Us->isChecked()){
        ui->lineEdit_inch->setVisible(true);
        ui->label_feet->setVisible(true);
        ui->label__Weight->setText("lbs");
        ui->label_height->setText("inch");
        ui->label_feet->setText("feet");
        us = true;
    }

}

void Bmi :: calculateButtonPressed(){
    double result=0;
    if (metrics){
        double weight = ui->lineEdit_Weight->text().toDouble();
        double height = ui->lineEdit_Height->text().toDouble();
        double heightInMeters = height/100;
        result = weight / (heightInMeters*heightInMeters);

    }
    else if(us){
        double weight = ui->lineEdit_Weight->text().toDouble();
        double feet = ui->lineEdit_inch->text().toDouble();
        double inch = ui->lineEdit_Height->text().toDouble();
        double heightInInchs = feet*12;
        result = (weight / ((heightInInchs+inch)*(heightInInchs+inch)))*703;
    }

    if(result <18.5){
       ui->label->setText("You are underweight. Your BMI is : "+QString::number(result));
    }
    else if(result >18.5 && result<24.99){
       ui->label->setText("You are healthy. Your BMI is : "+QString::number(result));
    }
    else if(result >25.00 && result<29.99){
       ui->label->setText("You are overweight. Your BMI is : "+QString::number(result));
    }
    else if(result >30){
       ui->label->setText("You are obese. Your BMI is : "+QString::number(result));
    }


}

void Bmi :: clearButtonPressed(){
    ui->lineEdit_Height->setText("");
    ui->lineEdit_Weight->setText("");
    ui->lineEdit_inch->setText("");
    ui->label->setText("");

}

Bmi::~Bmi()
{
    delete ui;
}
