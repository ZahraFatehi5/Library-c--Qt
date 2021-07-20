#include "app.h"
#include"user.h"
#include"mwidget.h"
#include"book.h"

#include<iostream>
using namespace std;

#include<QDebug>
#include<QMessageBox>
#include<QString>
#include<QTextStream>
#include<QLabel>
#include<QLineEdit>
#include<QtWidgets>
#include<QGridLayout>
#include<QPushButton>

extern QTextStream qout;
extern QTextStream qin;


app::app()
{
}

void app::wel()
{
  QMessageBox::information(0,"title","welcom to my library ^_^");
}

void app::help()
{
   mwidget ob;
   ob.show();
}

bool app::add_book()
{
//    QString number;
//    book book1;
//    mwidget book2;
//    book2.add_book();
//    if(books.find(number)!=books.end())
//    {
//        QMessageBox::warning(0,"Error","this number is registered before");
//        return false;
//    }
//    books.printbooks();
//    books[number]=book1;
    return true;
}

bool app::delbook()
{
    QString number;
    qDebug()<<"enter user number in consol";
    qin >> number;


  //if(books.erase(number)>0)
   // QMessageBox::information(0,":)","user deleted");
   // else
    //QMessageBox::information(0,":(","cant delete user");
return  true;
}
bool app::adduser()
{

//    user user;
//    mwidget use;
//    use.add_user();
//    if(uss.find(number)!=uss.end())
//    {
//        QMessageBox::warning(0,"Error","this number is registered before");
//        return false;
//    }
//    uss.printusers();
//    uss[number]=user1;
    return true;
}

bool app::deluser()
{
//    QWidget *window=new QWidget;
//    window->setWindowTitle("delete the user");

//   QGridLayout *layout2=new QGridLayout;



//    QString number;
//    QLabel *label1=new QLabel("enter user number:");
//    QLineEdit *line1=new QLineEdit;

//    layout2->addWidget(label1,0,0);
//    layout2->addWidget(line1,0,1);

//    QPushButton *btn=new QPushButton("ok");
//    layout2->addWidget(btn,1,1);
//    this->connect(btn,SIGNAL(clicked(bool)),this,SLOT(chek_number_user())) ;




//    window->setLayout(layout2);
//    window->show();
        QString number;
        qDebug()<<"enter user number in consol";
        qin >> number;


    //if(uss.erase(number)>0)
    //    QMessageBox::information(0,":)","user deleted");
   // else
  //      QMessageBox::information(0,":(","cant delete user");
    return  true;

}

