#ifndef APP_H
#define APP_H

#include<iostream>
using namespace std;
#include<QTextStream>
extern QTextStream qin;

#include"user.h"
#include"book.h"
#include"mwidget.h"

#include<QApplication>

class app:public QObject
{

public:
    app();

void wel();
  public
    slots:

    bool add_book();
    bool delbook();
    void chek_number_user();
    bool adduser();
    bool deluser();
    void help();

//    user_tabel uss;
//    book_tabel books;
};

#endif // APP_H
