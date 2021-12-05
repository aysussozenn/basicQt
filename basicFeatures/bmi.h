#ifndef BMI_H
#define BMI_H

#include <QMainWindow>

namespace Ui {
class Bmi;
}

class Bmi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bmi(QWidget *parent = nullptr);
    ~Bmi();

private:
    Ui::Bmi *ui;

private slots:
    void radioButtonPressed();
    void calculateButtonPressed();
    void clearButtonPressed();
};


#endif // BMI_H
