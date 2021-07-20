#ifndef USER_H
#define USER_H

#include<QApplication>
#include<QWidget>
#include<QGridLayout>
#include<QtWidgets>
#include<QString>
#include<QStringList>
#include<map>
#include<QFile>
#include<QTextStream>
#include"book.h"
#include"add_user_book.h"

#define  us_fn "user.txt"

class user:public QWidget
{

public:
user();
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


QGridLayout *layout;
QGridLayout *layout2;
QGridLayout *layout3;
QGridLayout *layout4;
QGridLayout *layout5;
QGridLayout *layout6;

QWidget *windows;
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


//****************************************//

book_tabel1 books8;
book_tabel2 books9;
book_tabel3 books10;
book_tabel4 books11;
ztabel  add8;

//*****************************************//


public slots:

void showing();

void print_books();
void dars();
void roman();
void tarikh();
void elm();
void all();

void print_borrowed();

void giveback();
bool giveback1();

void borrow();
bool borrow1();

bool searchdars1();
bool searchroman1();


void search_book();
bool search_book1();

void quite1();

};
class  user_t
{

public:

    QString name;
    QString family;
    QString number;
    int number_of_parcel;

    void printusers();
};

class user_tabel : public std::map<QString,user_t>
{
    public:

       user_tabel();
       void printusers();
       void load();
       void save();
      ~user_tabel();
};


#endif // USER_H
