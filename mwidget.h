#ifndef MWIDGET_H
#define MWIDGET_H

#include"add_user_book.h"


#include"user.h"
#include"book.h"
#include"admin.h"

#include<QApplication>
#include<QWidget>
#include<QGridLayout>
#include<QtWidgets>

class QLabel;
class QLineEdit;
class QPushButton ;

class mwidget : public QWidget
{
    Q_OBJECT

public:
    mwidget();

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
    QLineEdit *line11;
    QLabel *label11;

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
    QWidget *window10;

public:
/////////////////////////////////////////////////////////////////////////////////////////////////
     user_tabel  uss8;
     book_tabel1 books8;
     book_tabel2 books9;
     book_tabel3 books10;
     book_tabel4 books11;
     ztabel  add8;
     admin_tabel adm;
/////////////////////////////////////////////////////////////////////////////////////////////////


    public slots:
        void help();
        void f();
        void f1();
        void q();
        void q1();

////////////////////////////////////////////////////////////////////////////////////////////////////
        void add_user();
        bool user1();
        void priuser();
        void delete_user();
        bool delete_user1();
////////////////////////////////////////////////////////////////////////////////////////////////////
        void add_book();
        void book_dars();
        bool book1();
        void book_romman();
        bool book2();
        void book_tarikh();
        bool book3();
        void book_elmi();
        bool book4();
        void pribook();
        void delete_book();
        bool delete_book1();

         void darsi();
         void tarikhi();
         void romman();
         void elmi();
         void ALL();
 ///////////////////////////////////////////////////////////////////////////////////////////////////
       public slots:

         bool add_usbo_dars();
        void delete_bous1();
        bool delete_bous();
        void print_bous();
////////////////////////////////////////////////////////////////////////////////////////////////////
        void search_book_darsi();
        void search_book_romman();
        void search_book_tarikhi();
        void search_book_elmi();

        void search();
        bool search1();

        bool search_book_darsi1();
        bool search_book_romman1();
        bool search_book_tarikhi1();
        bool search_book_elmi1();
 ////////////////////////////////////////////////////////////////////////////////////////////////////
        void quite();
        void search_useer();
        bool search_useer1();
////////////////////////////////////////////////////////////////////////////////////////////////////

};

#endif // MWIDGET_H
