#include "user1.h"

user1::user1()
{
    btn1=new QPushButton("print users");
    btn2=new QPushButton("quit");
    btn3=new QPushButton("addbook");
    btn4=new QPushButton("delete book");
    btn5=new QPushButton("add user");
    btn6=new QPushButton("delete user");
    btn7=new QPushButton("print books");
    btn9=new QPushButton("to import");
    btn10=new QPushButton("print the books that borrowed");
    btn11=new QPushButton("to giveback the book");
    btn12=new QPushButton("search book");

    layout=new QGridLayout;
    layout->addWidget(btn1,0,0);
    layout->addWidget(btn2,1,0);
    layout->addWidget(btn3,2,0);
    layout->addWidget(btn4,3,0);
    layout->addWidget(btn5,4,0);
    layout->addWidget(btn6,5,0);
    layout->addWidget(btn7,6,0);
    layout->addWidget(btn9,7,0);
    layout->addWidget(btn10,8,0);
    layout->addWidget(btn11,9,0);
    layout->addWidget(btn12,10,0);

    this->setLayout(layout);

     this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(priuser())) ;
     this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(quite())) ;
     this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(add_book())) ;
     this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(delete_book())) ;
     this->connect(btn5,SIGNAL(clicked(bool)),this,SLOT(add_user())) ;
     this->connect(btn6,SIGNAL(clicked(bool)),this,SLOT(delete_user())) ;
     this->connect(btn7,SIGNAL(clicked(bool)),this,SLOT(pribook())) ;
     this->connect(btn9,SIGNAL(clicked(bool)),this,SLOT(search_useer())) ;
     this->connect(btn10,SIGNAL(clicked(bool)),this,SLOT(print_bous())) ;
     this->connect(btn11,SIGNAL(clicked(bool)),this,SLOT(delete_bous1()));
     this->connect(btn12,SIGNAL(clicked(bool)),this,SLOT(search()));
}
