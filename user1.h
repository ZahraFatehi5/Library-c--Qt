#ifndef USER1_H
#define USER1_H

#include<QApplication>
#include<QWidget>
#include<QGridLayout>
#include<QtWidgets>

class user1:public QWidget
{
public:
    user1();
    Q_OBJECT

public:


    QLineEdit *line1;
    QLabel *label1;
    QLineEdit *line2;
    QLabel *label2;
    QLineEdit *line3;
    QLabel *label3;
    QLineEdit *line4;
    QLabel *label4;
    QLineEdit *line5;
    QLabel *label5;
    QLineEdit *line6;
    QLabel *label6;
    QLineEdit *line7;
    QLabel *label7;
    QLineEdit *line8;
    QLabel *label8;
    QLineEdit *line9;
    QLabel *label9;
    QLineEdit *line10;
    QLabel *label10;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn10;
    QPushButton *btn11;
    QPushButton *btn12;

    QGridLayout *layout;
    QGridLayout *layout2;
    QGridLayout *layout3;
    QGridLayout *layout4;
    QGridLayout *layout5;
    QGridLayout *layout6;

    QWidget *wid;
    QWidget *window=new QWidget;
    QWidget *window2=new QWidget;
    QWidget *window3;
    QWidget *window4;
    QWidget *window5;
    QWidget *window6;
    QWidget *window7;
    QWidget *window8;
    QWidget *window9;

};

#endif // USER1_H
