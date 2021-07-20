#include "admin.h"

#include<QString>
#include<QStringList>
#include<map>
#include<QFile>
#include<QTextStream>

admin::admin()
{

    btn1=new QPushButton("add user");
    btn2=new QPushButton("print user");
    btn3=new QPushButton("delete user");
    btn4=new QPushButton("add book");
    btn5=new QPushButton("delete book");
    btn6=new QPushButton("print admin");
    btn7=new QPushButton("quite");


    layout=new QGridLayout;
    layout->addWidget(btn1,0,0);
    layout->addWidget(btn2,1,0);
    layout->addWidget(btn3,2,0);
    layout->addWidget(btn4,3,0);
    layout->addWidget(btn5,4,0);
    layout->addWidget(btn6,5,0);
    layout->addWidget(btn7,6,0);


    this->setLayout(layout);

     this->connect(btn1,SIGNAL(clicked(bool)),this,SLOT(priuser())) ;
     this->connect(btn2,SIGNAL(clicked(bool)),this,SLOT(quite())) ;
     this->connect(btn3,SIGNAL(clicked(bool)),this,SLOT(add_book())) ;
     this->connect(btn4,SIGNAL(clicked(bool)),this,SLOT(delete_book())) ;
     this->connect(btn5,SIGNAL(clicked(bool)),this,SLOT(add_user())) ;
     this->connect(btn6,SIGNAL(clicked(bool)),this,SLOT(delete_user())) ;
     this->connect(btn7,SIGNAL(clicked(bool)),this,SLOT(pribook())) ;
}


//############################################################################################//


admin_tabel::admin_tabel()
{
    load();
}
void admin_tabel::load()
{
    QFile file(admin_q);
    file.open(QFile::Text | QFile::ReadOnly );
    if(!file.isOpen())
        return;
    QTextStream fst(&file);

    while (!fst.atEnd())
    {
        QStringList sl=fst.readLine().split(',');
        if(sl.size()!=4)
            continue;

        (*this)[sl[0]] = admin_1 { sl[1] , sl[2] ,sl[3]};

    }

  file.close();
}
void admin_tabel::save()
{

    QFile file(admin_q);
    file.open(QFile::Text | QFile ::WriteOnly);
    if(!file.isOpen())
    {
        QMessageBox :: warning(0,"Error","cant write into file" admin_q);
        throw  "cant write into file" admin_q;
        return;
    }

    QTextStream fus (&file);
    for(admin_tabel::iterator itr=begin();itr!=end();++itr)
    {
         fus<<itr->first<<","
            <<itr->second.name<<","
            <<itr->second.lastname<<","
            <<itr->second.number<<endl;
    }
    file.close();

}

admin_tabel::~admin_tabel()
{
    save();
}


