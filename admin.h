#ifndef ADMIN_H
#define ADMIN_H

#include<QApplication>
#include<QWidget>
#include<QGridLayout>
#include<QtWidgets>
#include<QString>
#include<QStringList>
#include<map>
#include<QFile>
#include<QTextStream>


#define admin_q "admin.txt"


class admin:public QWidget
{
public:
    admin();


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


    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;

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


public slots:
//    void add_user();
//    void delete_user();
//    void add_book();
//    void delete_book();
//    void quite2();
//    void print_user();
//    void print_admin();


};
class admin_1
{
    public:
        QString name;
        QString lastname;
        QString number;
};
class admin_tabel:public std::map<QString,admin_1>
{

public:

admin_tabel();

bool add_admin();
void save();
void load();
void print_admin();
~ admin_tabel();
};




#endif // ADMIN_H
