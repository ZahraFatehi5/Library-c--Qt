#include "user.h"

#include<QtWidgets>
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
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

user::user()
{
showing();

}
void user::showing()
{

    windows=new QWidget;
    windows->setWindowTitle("help");

    btn1=new QPushButton("print books");
    btn2=new QPushButton("print the books that borrowed");
    btn3=new QPushButton("to giveback the book");
    btn4=new QPushButton("to borrow");
    btn5=new QPushButton("search book");
    btn6=new QPushButton("quite");


    layout=new QGridLayout;
    layout->addWidget(btn1,0,0);
    layout->addWidget(btn2,1,0);
    layout->addWidget(btn3,2,0);
    layout->addWidget(btn4,3,0);
    layout->addWidget(btn5,4,0);
    layout->addWidget(btn6,5,0);


    this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(print_books())) ;
    this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(print_borrowed())) ;
    this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(giveback())) ;
    this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(borrow())) ;
    this->connect(btn5,SIGNAL(clicked(bool)),this,SLOT(search_book())) ;
    this->connect(btn6,SIGNAL(clicked(bool)),this,SLOT(quite1())) ;

    windows->setLayout(layout);
    windows->show();

}
void user::print_books()
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
void user::borrow()
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
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(borrow1())) ;

      window6->setLayout(layout3);
      window6->show();
}
bool user ::borrow1()
{
    int i=0;

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
}

bool user::searchdars1()
{
    if(add8.find(line7->text()) !=add8.end())
    {
        QMessageBox ::warning(this,"ERROR","this book is browed befor");
        window3->close();
        return false;
    }
  else  if( books8.find(line7->text()) != books8 .end()  ||  books9.find(line7->text()) != books9 .end() || books10.find(line7->text()) != books10.end() ||books11.find(line7->text()) != books11.end() )
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
      this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(searchroman1())) ;

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

bool user::searchroman1()
{
    add_user_book  mm;
    mm.name_of_book=(line1->text());
    mm.guide_of_book=(line2->text());
    mm.number_of_user=(line3->text());

        mm.printbu();
        add8 [mm.name_of_book]=mm;
        window5->close();
        window8->close();
        return true;
}
//void user::searchdars()
//{
//           window3=new QWidget;
//           window3->setWindowTitle("for search the book");

//           layout=new QGridLayout;

//           line7=new QLineEdit;
//           label7=new QLabel("book name:");
//           layout->addWidget(label7,0,0);
//           layout->addWidget(line7,1,0);

//           QPushButton *ok=new QPushButton("ok");
//           layout->addWidget(ok,3,0);
//           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_darsi1()));

//           window3->setLayout(layout);
//           window3->show();
//           window8->close();
//           window->close();
//}

//void user::searchroman()
//{
//           window3=new QWidget;
//           window3->setWindowTitle("for search the book");

//           layout=new QGridLayout;

//           line7=new QLineEdit;
//           label7=new QLabel("book name:");
//           layout->addWidget(label7,0,0);
//           layout->addWidget(line7,1,0);

//           QPushButton *ok=new QPushButton("ok");
//           layout->addWidget(ok,3,0);
//           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_romman1()));

//           window3->setLayout(layout);
//           window3->show();
//            window8->close();
//            window->close();
//}


//void user::searchtarikh()
//{
//           window3=new QWidget;
//           window3->setWindowTitle("for search the book");

//           layout=new QGridLayout;

//           line7=new QLineEdit;
//           label7=new QLabel("book name:");
//           layout->addWidget(label7,0,0);
//           layout->addWidget(line7,1,0);

//           QPushButton *ok=new QPushButton("ok");
//           layout->addWidget(ok,3,0);
//           connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_tarikhi1()));

//           window3->setLayout(layout);
//           window3->show();
//            window8->close();
//           window->close();
//}

//void user::searchelm()
//{
//    window3=new QWidget;
//           window3->setWindowTitle("for search the book");

//           layout=new QGridLayout;

//           line7=new QLineEdit;
//           label7=new QLabel("book name:");
//           layout->addWidget(label7,0,0);
//           layout->addWidget(line7,1,0);

//           QPushButton *ok=new QPushButton("ok");
//           layout->addWidget(ok,3,0);
 //          connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book_elmi1()));

//           window3->setLayout(layout);
//           window3->show();
//           window8->close();
//           window->close();
//}



void user::giveback()
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
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(giveback1())) ;

    window7->setLayout(layout6);
    window7->show();
}
bool user::giveback1()
{
    if(add8.erase(line9->text())>0)
            QMessageBox::information(this,":)","book giveback");
        else
            QMessageBox::information(this,":(","this book is not in list :(");
    window7->close();
        return  true;
}
void user::print_borrowed()
{
     add8.print_usbo();
}
void user::dars()
{
    books8 .printbooks();
}
void user::roman()
{
    books9 .printbooks2();
}
void user::tarikh()
{
    books10 .printbooks3();
}
void user::elm()
{
    books11 .printbooks4();
}
void user::all()
{
    books8 .printbooks();
    books9 .printbooks2();
    books10 .printbooks3();
    books11 .printbooks4();
}
void user::search_book()
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
    this->connect(ok,SIGNAL(clicked(bool)),this,SLOT(search_book1())) ;

    window9->setLayout(layout6);
    window9->show();
}
bool user::search_book1()
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
void user::quite1()
{

    close();
}



//#############################################################################################//
user_tabel::user_tabel()
{

    load();

}

void user_tabel::printusers()
{

        for (  user_tabel::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            qDebug() << "user number:" << itr-> first  ;
            itr->second.printusers() ;
        }

}
void user_tabel::load()
{
  QFile file(us_fn);
  file.open(QFile::Text | QFile::ReadOnly );
  if(!file.isOpen())
      return;
  QTextStream fst(&file);

  while (!fst.atEnd())
  {
      QStringList sl=fst.readLine().split(',');
      if(sl.size()!=5)
          continue;

      (*this)[sl[0]]= user_t { sl[1] , sl[2] ,sl[3], sl[4].toInt()};

  }

file.close();

}

/////////////////////////////////////////////////////////


void user_tabel::save()
{
    QFile file(us_fn);
    file.open(QFile::Text | QFile ::WriteOnly);
    if(!file.isOpen())
    {
        QMessageBox :: warning(0,"Error","cant write into file" us_fn);
        throw  "cant write into file" us_fn;
        return;
    }

    QTextStream fus (&file);
    for(user_tabel::iterator itr=begin();itr!=end();++itr)
    {
         fus<<itr->first<<","
            <<itr->second.name<<","
            <<itr->second.family<<","
            <<itr->second.number<<","
            <<itr->second.number_of_parcel<<endl;
    }
    file.close();
}
user_tabel::~user_tabel()
{
    save();
}
void user_t::printusers()
{
    qDebug() << "*******************************************"  ;
    qDebug ()<< "name: "   << name  ;
    qDebug() << "family: " << family  ;
    qDebug() << "number: " << number ;
    qDebug()<<"number_of_parcel"<<number_of_parcel;
    qDebug() << "*******************************************" ;

}


