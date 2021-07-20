#include "add_user_book.h"


#include<QDebug>
#include<QMessageBox>

extern QTextStream qout;
extern QTextStream qin;

ztabel::ztabel()
{
    loadw();
}
void ztabel::print_usbo()
{
    for (  ztabel::iterator itr = begin() ; itr != end() ; ++ itr )
    {
        qDebug() << "book name:" << itr-> first  ;
        itr->second.printbu() ;
    }
}
void ztabel::loadw()
{
  QFile file(book_borrow);
  file.open(QFile::Text | QFile::ReadOnly );
  if(!file.isOpen())
      return;
  QTextStream fbb(&file);

  while (!fbb.atEnd())
  {
      QStringList sl=fbb.readLine().split(',');
      if(sl.size()!=4)
          continue;

        (*this)[sl[0]]= add_user_book {sl[1],sl[2],sl[3]};


}

file.close();

}

void ztabel::savew()
{
    QFile file(book_borrow);
    file.open(QFile::Text | QFile ::WriteOnly);
    if(!file.isOpen())
    {
        QMessageBox :: warning(0,"Error","cant write into file" book_borrow);
        throw  "cant write into file" book_borrow;
        return;
    }

    QTextStream fus (&file);
    for(ztabel::iterator itr=begin();itr!=end();++itr)
    {
         fus<<itr->first<<","
            <<itr->second.name_of_book<<","
            <<itr->second.guide_of_book<<","
            <<itr->second.number_of_user<<endl;
    }
    file.close();
}
ztabel::~ztabel()
{
    savew();
}
void add_user_book::printbu()
{
    qDebug() << "*******************************************"  ;
    qDebug ()<< "name: "   << name_of_book  ;
    qDebug() << "guide: " << guide_of_book  ;
   qDebug() << "number: " << number_of_user ;
    qDebug() << "*******************************************" ;
}
