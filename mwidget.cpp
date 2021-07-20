#include "mwidget.h"
#include"user.h"
#include"admin.h"

#include<QPushButton>
#include<QGridLayout>
#include<QDebug>
#include<QLineEdit>
#include<QLabel>
#include<QtWidgets>
#include<QTextStream>
#include<QFile>

extern QTextStream qout;
extern QTextStream qin;


mwidget::mwidget()
{

    btn1=new QPushButton("user");
    btn2=new QPushButton ("admin");
        layout=new QGridLayout;
        layout->addWidget(btn1,0,0);
        layout->addWidget(btn2,1,0);
            this->setLayout(layout);
            this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(f())) ;
            this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(q())) ;

//    btn1=new QPushButton("print users");
//    btn3=new QPushButton("addbook");
//    btn4=new QPushButton("delete book");
//    btn5=new QPushButton("add user");
//    btn6=new QPushButton("delete user");
//    btn7=new QPushButton("print books");
//    btn9=new QPushButton("to import");
//    btn10=new QPushButton("print the books that borrowed");
//    btn11=new QPushButton("to giveback the book");
//    btn12=new QPushButton("search book");

//    layout=new QGridLayout;
//    layout->addWidget(btn1,0,0);
//    layout->addWidget(btn2,1,0);
//    layout->addWidget(btn3,2,0);
//    layout->addWidget(btn4,3,0);
//    layout->addWidget(btn5,4,0);
//    layout->addWidget(btn6,5,0);
//    layout->addWidget(btn7,6,0);
//    layout->addWidget(btn9,7,0);
//    layout->addWidget(btn10,8,0);
//    layout->addWidget(btn11,9,0);
//    layout->addWidget(btn12,10,0);

//    this->setLayout(layout);

//     this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(priuser())) ;
 //    this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(quite())) ;
//     this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(add_book())) ;
//     this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(delete_book())) ;
   // this->connect(btn5,SIGNAL(clicked(bool)),this,SLOT(add_user())) ;
//     this->connect(btn6,SIGNAL(clicked(bool)),this,SLOT(delete_user())) ;
 //    this->connect(btn7,SIGNAL(clicked(bool)),this,SLOT(pribook())) ;
//     this->connect(btn9,SIGNAL(clicked(bool)),this,SLOT(search_useer())) ;
 //   this->connect(btn10,SIGNAL(clicked(bool)),this,SLOT(print_bous())) ;
  //   this->connect(btn11,SIGNAL(clicked(bool)),this,SLOT(delete_bous1()));
 //   this->connect(btn12,SIGNAL(clicked(bool)),this,SLOT(search()));
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

void mwidget::f()
{
    window10=new QWidget;
    window10->setWindowTitle("to import");

    layout3=new QGridLayout;

    line11=new QLineEdit;
    label11=new QLabel("admin number:");
    layout3->addWidget(label11,0,0);
    layout3->addWidget(line11,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout3->addWidget(ok,1,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(f1())) ;

    window10->setLayout(layout3);
    window10->show();

}


void mwidget::f1()
{
    if( adm.find(line11->text()) != adm .end())
    {
        admin ob;
        ob.show();
    }
    else
        QMessageBox::warning(this,"ERROR","thos number in not admin");

    window10->close();

}
void mwidget::q()
{
    QMessageBox::StandardButton  button;
    button =QMessageBox::question(this,"title","are you login before?",QMessageBox::Yes| QMessageBox::No);
    if(button==QMessageBox::Yes)
    {
    window10=new QWidget;
    window10->setWindowTitle("to import");

    layout3=new QGridLayout;

    line11=new QLineEdit;
    label11=new QLabel("user number:");
    layout3->addWidget(label11,0,0);
    layout3->addWidget(line11,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout3->addWidget(ok,1,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(q1())) ;


    window10->setLayout(layout3);
    window10->show();
    }
    else
        add_user();
}

void mwidget::q1()
{
    if( uss8.find(line11->text()) != uss8 .end())
    {

        user ob;
        ob.show();
    }
    else
        QMessageBox::warning(this,"ERROR","this user isnt belong to the library");
    window10->close();
}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//



void mwidget::search()
{
    window9=new QWidget;
    window9->setWindowTitle("search book");

    layout6=new QGridLayout;

    line10=new QLineEdit;
    label10=new QLabel("enter name of book or writer or translator or publication");
    layout6->addWidget(label10,0,0);
    layout6->addWidget(line10,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout6->addWidget(ok,4,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(search1())) ;

    window9->setLayout(layout6);
    window9->show();
}
bool mwidget::search1()
{
    for (  book_tabel1::iterator itr = books8.begin() ; itr != books8.end() ; ++ itr )
     {
     if(itr->first.toLower().startsWith( line10->text().toLower())  || itr->second.motarjem.toLower().startsWith( line10->text().toLower()) || itr->second.nashr.toLower().startsWith( line10->text().toLower()))
     {
          qDebug()<<"*****************************************";
         qDebug()<<"name of book:"<<itr->first<<endl
                <<"guide:"<<itr->second.guide<<endl
                <<"publication:"<<itr->second.nashr<<endl
                <<"translator:"<<itr->second.motarjem<<endl
               <<"year of publication:"<<itr->second.sal_nashr;
          qDebug()<<"*****************************************";

     }
     }


      for (  book_tabel2::iterator itr = books9.begin() ; itr != books9.end() ; ++ itr )
       {
          if(itr->first.toLower().startsWith( line10->text().toLower())  || itr->second.motarjem.toLower().startsWith( line10->text().toLower()) || itr->second.nashr.toLower().startsWith( line10->text().toLower()))
       {
               qDebug()<<"*****************************************";
           qDebug()<<"name of book:"<<itr->first<<endl
                  <<"guide:"<<itr->second.guide<<endl
                  <<"publication:"<<itr->second.nashr<<endl
                  <<"translator:"<<itr->second.motarjem<<endl
                 <<"year of publication:"<<itr->second.sal_nashr;
            qDebug()<<"*****************************************";

       }
       }
      for (  book_tabel3::iterator itr = books10.begin() ; itr != books10.end() ; ++ itr )
       {
          if(itr->first.toLower().startsWith( line10->text().toLower())  || itr->second.motarjem.toLower().startsWith( line10->text().toLower()) || itr->second.nashr.toLower().startsWith( line10->text().toLower()))
       {
               qDebug()<<"*****************************************";
           qDebug()<<"name of book:"<<itr->first<<endl
                  <<"guide:"<<itr->second.guide<<endl
                  <<"publication:"<<itr->second.nashr<<endl
                  <<"translator:"<<itr->second.motarjem<<endl
                 <<"year of publication:"<<itr->second.sal_nashr;
            qDebug()<<"*****************************************";

       }
       }

      for (  book_tabel4::iterator itr = books11.begin() ; itr != books11.end() ; ++ itr )
       {
          if(itr->first.toLower().startsWith( line10->text().toLower())  || itr->second.motarjem.toLower().startsWith( line10->text().toLower()) || itr->second.nashr.toLower().startsWith( line10->text().toLower()))
       {
           qDebug()<<"*****************************************";
           qDebug()<<"name of book:"<<itr->first<<endl
                  <<"guide:"<<itr->second.guide<<endl
                  <<"publication:"<<itr->second.nashr<<endl
                  <<"translator:"<<itr->second.motarjem<<endl
                 <<"year of publication:"<<itr->second.sal_nashr;
            qDebug()<<"*****************************************";

       }
       }

      window9->close();
      return  true;

}
//////////////////////////////////////////////////////////////////////////////////////////////

void mwidget::delete_bous1()
{

    window7=new QWidget;
    window7->setWindowTitle("return book");

    layout6=new QGridLayout;

    line9=new QLineEdit;
    label9=new QLabel("please enter name of book");
    layout6->addWidget(label9,0,0);
    layout6->addWidget(line9,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout6->addWidget(ok,4,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(delete_bous())) ;

    window7->setLayout(layout6);
    window7->show();

}
bool mwidget::delete_bous()
{
    if(add8.erase(line9->text())>0)
            QMessageBox::information(this,":)","book giveback");
        else
            QMessageBox::information(this,":(","this book is not in list :(");
    window7->close();
        return  true;

}
//---------------------------------------------------------------------------------------------------//

void mwidget::search_useer()
{
    window6=new QWidget;
    window6->setWindowTitle("to import");

    layout3=new QGridLayout;

    line8=new QLineEdit;
    label8=new QLabel("user number:");
    layout3->addWidget(label8,0,0);
    layout3->addWidget(line8,0,1);


      QPushButton *ok=new QPushButton("ok");
      layout3->addWidget(ok,1,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_useer1())) ;

      window6->setLayout(layout3);
      window6->show();
}

bool mwidget::search_useer1()
{
//    user mm;
//    mm.number=(line8->text());
int i=0;
    if( uss8.find(line8->text()) != uss8 .end())
    {

          for (  ztabel::iterator itr = add8.begin() ; itr != add8.end() ; ++ itr )
          {
              if(itr->second.number_of_user == line8->text())
                  i++;
          }
         if(i>3)
         {
             QMessageBox ::warning(this,"ERROR","this user book is more 3");
             window6->close();
             return false;
         }
         else
         {
        window8=new QWidget;
        window8->setWindowTitle("choose title  of book");

       label5=new QLabel("select the group:)");
        btn1=new QPushButton("text_book");
        btn2=new QPushButton("novel");
        btn3=new QPushButton("historical");
        btn4=new QPushButton("scientific");

        layout4=new QGridLayout;
        layout4->addWidget(label5,0,0);
        layout4->addWidget(btn1,1,0);
        layout4->addWidget(btn2,1,1);
        layout4->addWidget(btn3,2,0);
        layout4->addWidget(btn4,2,1);


        //this->setLayout(layout);

        this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(search_book_darsi())) ;
        this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(search_book_romman())) ;
        this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(search_book_tarikhi())) ;
        this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(search_book_elmi())) ;

        window8->setLayout(layout4);
        window8->show();
        window6->close();

         }

    }
    else
    {
        QMessageBox ::warning(this,"ERROR","this user not found");
       window6->close();
        return false;
    }
return true;
}
void mwidget::search_book_darsi()
{
           window3=new QWidget;
           window3->setWindowTitle("for search the book");

           layout=new QGridLayout;

           line7=new QLineEdit;
           label7=new QLabel("book name:");
           layout->addWidget(label7,0,0);
           layout->addWidget(line7,1,0);

           QPushButton *ok=new QPushButton("ok");
           layout->addWidget(ok,3,0);
           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_darsi1()));

           window3->setLayout(layout);
           window3->show();
           window8->close();
           window->close();
}

void mwidget::search_book_romman()
{
           window3=new QWidget;
           window3->setWindowTitle("for search the book");

           layout=new QGridLayout;

           line7=new QLineEdit;
           label7=new QLabel("book name:");
           layout->addWidget(label7,0,0);
           layout->addWidget(line7,1,0);

           QPushButton *ok=new QPushButton("ok");
           layout->addWidget(ok,3,0);
           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_romman1()));

           window3->setLayout(layout);
           window3->show();
            window8->close();
            window->close();
}


void mwidget::search_book_tarikhi()
{
           window3=new QWidget;
           window3->setWindowTitle("for search the book");

           layout=new QGridLayout;

           line7=new QLineEdit;
           label7=new QLabel("book name:");
           layout->addWidget(label7,0,0);
           layout->addWidget(line7,1,0);

           QPushButton *ok=new QPushButton("ok");
           layout->addWidget(ok,3,0);
           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_tarikhi1()));

           window3->setLayout(layout);
           window3->show();
            window8->close();
           window->close();
}

void mwidget::search_book_elmi()
{
    window3=new QWidget;
           window3->setWindowTitle("for search the book");

           layout=new QGridLayout;

           line7=new QLineEdit;
           label7=new QLabel("book name:");
           layout->addWidget(label7,0,0);
           layout->addWidget(line7,1,0);

           QPushButton *ok=new QPushButton("ok");
           layout->addWidget(ok,3,0);
           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_elmi1()));

           window3->setLayout(layout);
           window3->show();
           window8->close();
           window->close();
}
///////////////////////////////////////////////////////////////////////////////////////////////

bool mwidget::search_book_darsi1()
{

    //mm.name_book=(line7->text());
    if(add8.find(line7->text()) !=add8.end())
    {
        QMessageBox ::warning(this,"ERROR","this book is browed befor");
        window3->close();
        return false;
    }
  else  if( books8.find(line7->text()) != books8 .end())
    {
      window5=new QWidget;
      window5->setWindowTitle("title");


      layout2=new QGridLayout;

      line1=new QLineEdit(line7->text());
      label1=new QLabel("book name:");
      layout2->addWidget(label1,0,0);
      layout2->addWidget(line1,0,1);

      line2=new QLineEdit;
      label2=new QLabel("guide:");
      layout2->addWidget(label2,1,0);
      layout2->addWidget(line2,1,1);


      line3=new QLineEdit(line8->text());
      label3=new QLabel("user number:");
      layout2->addWidget(label3,2,0);
      layout2->addWidget(line3,2,1);



      QPushButton *ok=new QPushButton("ok");
      layout2->addWidget(ok,3,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(add_usbo_dars())) ;

      window5->setLayout(layout2);
      window5->show();
      window3->close();
    }

    else
    {
        QMessageBox ::warning(this,"ERROR","this book not found");
        window3->close();
        return false;
    }
    return true;
}
bool mwidget::search_book_romman1()
{
    if(add8.find(line7->text()) !=add8.end())
    {
        QMessageBox ::warning(this,"ERROR","this book is browed befor");
        window3->close();
        return false;
    }
   else if( books9.find(line7->text()) != books9 .end())
    {
      window5=new QWidget;
      window5->setWindowTitle("title");


      layout2=new QGridLayout;

      line1=new QLineEdit(line7->text());
      label1=new QLabel("book name:");
      layout2->addWidget(label1,0,0);
      layout2->addWidget(line1,0,1);


      line2=new QLineEdit;
      label2=new QLabel("guide:");
      layout2->addWidget(label2,1,0);
      layout2->addWidget(line2,1,1);


      line3=new QLineEdit(line8->text());
      label3=new QLabel("user number:");
      layout2->addWidget(label3,2,0);
      layout2->addWidget(line3,2,1);



      QPushButton *ok=new QPushButton("ok");
      layout2->addWidget(ok,3,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(add_usbo_dars())) ;

      window5->setLayout(layout2);
      window5->show();
      window3->close();

    }

    else
    {
        QMessageBox ::warning(this,"ERROR","this book not found");
        window3->close();
        return false;
    }
    return true;
}
bool mwidget::search_book_tarikhi1()
{
    if(add8.find(line7->text()) !=add8.end())
    {
        QMessageBox ::warning(this,"ERROR","this book is browed befor");
        window3->close();
        return false;
    }
   else if( books10.find(line7->text()) != books10 .end())
    {
      window5=new QWidget;
      window5->setWindowTitle("title");


      layout2=new QGridLayout;

      line1=new QLineEdit(line7->text());
      label1=new QLabel("book name:");
      layout2->addWidget(label1,0,0);
      layout2->addWidget(line1,0,1);


      line2=new QLineEdit;
      label2=new QLabel("guide:");
      layout2->addWidget(label2,1,0);
      layout2->addWidget(line2,1,1);


      line3=new QLineEdit(line8->text());
      label3=new QLabel("user number:");
      layout2->addWidget(label3,2,0);
      layout2->addWidget(line3,2,1);



      QPushButton *ok=new QPushButton("ok");
      layout2->addWidget(ok,3,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(add_usbo_dars())) ;

      window5->setLayout(layout2);
      window5->show();
      window3->close();

    }

    else
    {
        QMessageBox ::warning(this,"ERROR","this book not found");
        window3->close();
        return false;
    }
    return true;
}
bool mwidget::search_book_elmi1()
{
    if(add8.find(line7->text()) !=add8.end())
    {
        QMessageBox ::warning(this,"ERROR","this book is browed befor");
        window3->close();
        return false;
    }
  else  if( books11.find(line7->text()) != books11 .end())
    {
      window5=new QWidget;
      window5->setWindowTitle("title");


      layout2=new QGridLayout;

      line1=new QLineEdit(line7->text());
      label1=new QLabel("book name:");
      layout2->addWidget(label1,0,0);
      layout2->addWidget(line1,0,1);


      line2=new QLineEdit;
      label2=new QLabel("guide:");
      layout2->addWidget(label2,1,0);
      layout2->addWidget(line2,1,1);


      line3=new QLineEdit(line8->text());
      label3=new QLabel("user number:");
      layout2->addWidget(label3,2,0);
      layout2->addWidget(line3,2,1);



      QPushButton *ok=new QPushButton("ok");
      layout2->addWidget(ok,3,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(add_usbo_dars())) ;

      window5->setLayout(layout2);
      window5->show();
      window3->close();
    }

    else
    {
        QMessageBox ::warning(this,"ERROR","this book not found");
        window3->close();
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------//

bool mwidget::add_usbo_dars()
{
    add_user_book  mm;
    mm.name_of_book=(line1->text());
    mm.guide_of_book=(line2->text());
    mm.number_of_user=(line3->text());

        mm.printbu();
        add8 [mm.name_of_book]=mm;
        window5->close();
        window8->close();        return true;

}
void mwidget::print_bous()
{
    add8.print_usbo();

}




//-----------------------------------------------------------------------------------------------//



void mwidget::add_user()
{

    wid=new QWidget;
    wid->setWindowTitle("add_user");

    layout2=new QGridLayout;

    line1=new QLineEdit;
    label1=new QLabel("name:");
    layout2->addWidget(label1,0,0);
    layout2->addWidget(line1,0,1);


    line2=new QLineEdit;
    label2=new QLabel("family:");
    layout2->addWidget(label2,1,0);
    layout2->addWidget(line2,1,1);


    line3=new QLineEdit;
    label3=new QLabel("number:");
    layout2->addWidget(label3,2,0);
    layout2->addWidget(line3,2,1);


    line4=new QLineEdit;
    label4=new QLabel("number_of_parcel:");
    layout2->addWidget(label4,3,0);
    layout2->addWidget(line4,3,1);


      QPushButton *ok=new QPushButton("ok");
      layout2->addWidget(ok,4,1);
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(user1())) ;

      wid->setLayout(layout2);
      wid->show();

}

bool mwidget::user1()
{

    user_t mm;

    mm.name=(line1->text());
    mm.family=(line2->text());
    mm.number=(line3->text());
    mm.number_of_parcel=(line4->text().toInt());
    if( uss8.find(mm.number) != uss8 .end())
        {
            QMessageBox::warning(this,"Error","this number is registered before");
           wid->close();
            return false;
        }
     mm.printusers();
     uss8 [mm.number]=mm;
     wid->close();

    return true;

}

void mwidget::priuser()
{

 uss8 .printusers();
}

void mwidget::delete_user()
{

    window7=new QWidget;
    window7->setWindowTitle("delete user");

    layout6=new QGridLayout;

    line9=new QLineEdit;
    label9=new QLabel("please enter thenumber of user");
    layout6->addWidget(label9,0,0);
    layout6->addWidget(line9,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout6->addWidget(ok,4,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(delete_user1())) ;

    window7->setLayout(layout6);
    window7->show();
}
bool mwidget::delete_user1()
{
    if(uss8.erase(line9->text())>0)
            QMessageBox::information(this,":)","user removed");
        else
            QMessageBox::information(this,":(","this user is not in list :(");
    window7->close();
        return  true;
}
//........................................................................................///


void mwidget::delete_book()
{

    window7=new QWidget;
    window7->setWindowTitle("return book");

    layout6=new QGridLayout;

    line9=new QLineEdit;
    label9=new QLabel("please enter name of book");
    layout6->addWidget(label9,0,0);
    layout6->addWidget(line9,0,1);

    QPushButton *ok=new QPushButton("ok");
    layout6->addWidget(ok,4,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(delete_book1())) ;

    window7->setLayout(layout6);
    window7->show();
}
bool mwidget::delete_book1()
{

    if(books8.erase(line9->text())>0)
               QMessageBox::information(this,":)","book removed");
    else if(books9.erase(line9->text())>0)
                   QMessageBox::information(this,":)","book removed");
    else if(books10.erase(line9->text())>0)
                   QMessageBox::information(this,":)","book removed");
    else if(books11.erase(line9->text())>0)
                   QMessageBox::information(this,":)","book removed");


    else
         QMessageBox::information(this,":(","this book is not in list :(");
 window7->close();
     return  true;
}
//........................................................................................///
void mwidget::add_book()
{
    //wid=new QWidget;
    window->setWindowTitle("add_book");


    btn1=new QPushButton("text_book");
    btn2=new QPushButton("novel");
    btn3=new QPushButton("historical");
    btn4=new QPushButton("scientific");

    layout4=new QGridLayout;
    layout4->addWidget(btn1,0,0);
    layout4->addWidget(btn2,0,1);
    layout4->addWidget(btn3,1,0);
    layout4->addWidget(btn4,1,1);


    //this->setLayout(layout);

    this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(book_dars())) ;
    this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(book_romman())) ;
    this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(book_tarikh())) ;
    this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(book_elmi())) ;

    window->setLayout(layout4);
    window->show();


}
//////////////////////////////////////////////////////////////////////////////////////////////////
void mwidget::book_dars()
{
    wid=new QWidget;
    wid->setWindowTitle("add_book");

    layout2=new QGridLayout;

    line1=new QLineEdit;
    label1=new QLabel("name:");
    layout2->addWidget(label1,0,0);
    layout2->addWidget(line1,0,1);


    line2=new QLineEdit;
    label2=new QLabel("translator & writer:");
    layout2->addWidget(label2,1,0);
    layout2->addWidget(line2,1,1);


    line3=new QLineEdit;
    label3=new QLabel("publication:");
    layout2->addWidget(label3,2,0);
    layout2->addWidget(line3,2,1);

    line4=new QLineEdit;
    label4=new QLabel("guide:");
    layout2->addWidget(label4,3,0);
    layout2->addWidget(line4,3,1);

    line5=new QLineEdit;
    label5=new QLabel("year of publication:");
    layout2->addWidget(label5,4,0);
    layout2->addWidget(line5,4,1);


    QPushButton *ok=new QPushButton("ok");
    layout2->addWidget(ok,5,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(book1())) ;

    wid->setLayout(layout2);
    wid->show();
    window->close();
}
void mwidget::book_romman()
{
    wid=new QWidget;
    wid->setWindowTitle("add_book");

    layout2=new QGridLayout;

    line1=new QLineEdit;
    label1=new QLabel("name:");
    layout2->addWidget(label1,0,0);
    layout2->addWidget(line1,0,1);


    line2=new QLineEdit;
    label2=new QLabel("translator & writer:");
    layout2->addWidget(label2,1,0);
    layout2->addWidget(line2,1,1);


    line3=new QLineEdit;
    label3=new QLabel("publication:");
    layout2->addWidget(label3,2,0);
    layout2->addWidget(line3,2,1);

    line4=new QLineEdit;
    label4=new QLabel("guide:");
    layout2->addWidget(label4,3,0);
    layout2->addWidget(line4,3,1);

    line5=new QLineEdit;
    label5=new QLabel("year of publication:");
    layout2->addWidget(label5,4,0);
    layout2->addWidget(line5,4,1);


    QPushButton *ok=new QPushButton("ok");
    layout2->addWidget(ok,5,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(book2())) ;

    wid->setLayout(layout2);
    wid->show();
     window->close();
}
void mwidget::book_elmi()
{
    wid=new QWidget;
    wid->setWindowTitle("add_book");

    layout2=new QGridLayout;

    line1=new QLineEdit;
    label1=new QLabel("name:");
    layout2->addWidget(label1,0,0);
    layout2->addWidget(line1,0,1);


    line2=new QLineEdit;
    label2=new QLabel("translator & writer:");
    layout2->addWidget(label2,1,0);
    layout2->addWidget(line2,1,1);


    line3=new QLineEdit;
    label3=new QLabel("publication:");
    layout2->addWidget(label3,2,0);
    layout2->addWidget(line3,2,1);

    line4=new QLineEdit;
    label4=new QLabel("guide:");
    layout2->addWidget(label4,3,0);
    layout2->addWidget(line4,3,1);

    line5=new QLineEdit;
    label5=new QLabel("year of publication:");
    layout2->addWidget(label5,4,0);
    layout2->addWidget(line5,4,1);


    QPushButton *ok=new QPushButton("ok");
    layout2->addWidget(ok,5,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(book3())) ;

    wid->setLayout(layout2);
    wid->show();
     window->close();
}
void  mwidget::book_tarikh()
{
    wid=new QWidget;
    wid->setWindowTitle("add_book");

    layout2=new QGridLayout;

    line1=new QLineEdit;
    label1=new QLabel("name:");
    layout2->addWidget(label1,0,0);
    layout2->addWidget(line1,0,1);


    line2=new QLineEdit;
    label2=new QLabel("translator & writer:");
    layout2->addWidget(label2,1,0);
    layout2->addWidget(line2,1,1);


    line3=new QLineEdit;
    label3=new QLabel("publication:");
    layout2->addWidget(label3,2,0);
    layout2->addWidget(line3,2,1);

    line4=new QLineEdit;
    label4=new QLabel("guide:");
    layout2->addWidget(label4,3,0);
    layout2->addWidget(line4,3,1);

    line5=new QLineEdit;
    label5=new QLabel("year of publication:");
    layout2->addWidget(label5,4,0);
    layout2->addWidget(line5,4,1);


    QPushButton *ok=new QPushButton("ok");
    layout2->addWidget(ok,5,1);
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(book4())) ;

    wid->setLayout(layout2);
    wid->show();
     window->close();
}
///////////////////////////////////////////////////////////////////////////////////////

bool mwidget::book1()
{
    book mm;

    mm.name_book=(line1->text());
    mm.motarjem=(line2->text());
    mm.guide=(line4->text());
    mm.nashr=(line3->text());
    mm.sal_nashr=(line5->text().toDouble());
    if( books8.find(mm.name_book) !=books8.end())
    {
        QMessageBox::warning(this,"Error","this number is registered before");
        wid->close();
        return false;
    }


    mm.printbooks();
    books8  [mm.name_book]=mm;
    wid->close();
    return true;
}

bool mwidget::book2()
{
    book mm;

    mm.name_book=(line1->text());
    mm.motarjem=(line2->text());
    mm.guide=(line4->text());
    mm.nashr=(line3->text());
    mm.sal_nashr=(line5->text().toDouble());
    if( books9.find(mm.name_book) !=books9.end())
    {
        QMessageBox::warning(this,"Error","this number is registered before");
        wid->close();
        return false;
    }


    mm.printbooks();
    books9  [mm.name_book]=mm;
    wid->close();
    return true;
}
bool mwidget::book3()
{
    book mm;

    mm.name_book=(line1->text());
    mm.motarjem=(line2->text());
    mm.guide=(line4->text());
    mm.nashr=(line3->text());
    mm.sal_nashr=(line5->text().toDouble());
    if( books10.find(mm.name_book) !=books10.end())
    {
        QMessageBox::warning(this,"Error","this number is registered before");
        wid->close();
        return false;
    }


    mm.printbooks();
    books10  [mm.name_book]=mm;
    wid->close();
    return true;
}
bool mwidget::book4()
{
    book mm;

    mm.name_book=(line1->text());
    mm.motarjem=(line2->text());
    mm.guide=(line4->text());
    mm.nashr=(line3->text());
    mm.sal_nashr=(line5->text().toDouble());
    if( books11.find(mm.name_book) !=books11.end())
    {
        QMessageBox::warning(this,"Error","this number is registered before");
        wid->close();
        return false;
    }


    mm.printbooks();
    books11  [mm.name_book]=mm;
    wid->close();
    return true;
}
//**********************************************************************************************//
void mwidget::pribook()
{
    window2->setWindowTitle("add_book");


    btn1=new QPushButton("text_book");
    btn2=new QPushButton("novel");
    btn3=new QPushButton("historical");
    btn4=new QPushButton("scientific");
    btn5=new QPushButton("ALL") ;

    layout=new QGridLayout;
    layout->addWidget(btn1,0,0);
    layout->addWidget(btn2,0,1);
    layout->addWidget(btn3,1,0);
    layout->addWidget(btn4,1,1);
    layout->addWidget(btn5,2,0);

    this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(darsi())) ;
    this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(romman())) ;
    this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(tarikhi())) ;
    this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(elmi())) ;
    this->connect(btn5,SIGNAL(clicked(bool)),this,SLOT(ALL())) ;

    window2->setLayout(layout);
    window2->show();
}

void mwidget::darsi()
{
    books8 .printbooks();
}

void mwidget::romman()
{
    books9 .printbooks2();
}
void mwidget::tarikhi()
{
    books10 .printbooks3();
}
void mwidget::elmi()
{
    books11 .printbooks4();
}

void mwidget::ALL()
{
    books8 .printbooks();
    books9 .printbooks2();
    books10 .printbooks3();
    books11 .printbooks4();
}
//**********************************************************************************************//


void mwidget::quite()
{
    close();
}


void mwidget::help()
{

}
