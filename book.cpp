#include "book.h"
#include<QMessageBox>
#include<QDebug>

book_tabel1::book_tabel1()
{
    load1();
}

book_tabel2::book_tabel2()
{
    load2();
}

book_tabel3::book_tabel3()
{
    load3();
}

book_tabel4::book_tabel4()
{
    load4();
}
//////////////////////////////////////////////////////////////////////////////////////////////
void book_tabel1::printbooks()
{
    for (  book_tabel1::iterator itr = begin() ; itr != end() ; ++ itr )
    {

        qDebug() << "book name:" << itr-> first  ;
        itr->second.printbooks() ;
    }
}


void book_tabel2::printbooks2()
{
    for (  book_tabel2::iterator itr = begin() ; itr != end() ; ++ itr )
    {

        qDebug() << "book name:" << itr-> first  ;
        itr->second.printbooks() ;
    }
}

void book_tabel3::printbooks3()
{
    for (  book_tabel3::iterator itr = begin() ; itr != end() ; ++ itr )
    {

        qDebug() << "book name:" << itr-> first  ;
        itr->second.printbooks() ;
    }
}

void book_tabel4::printbooks4()
{
    for (  book_tabel4::iterator itr = begin() ; itr != end() ; ++ itr )
    {

        qDebug() << "book name:" << itr-> first  ;
        itr->second.printbooks() ;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

void book_tabel1::load1()
{
   QFile file1(bo1_fn);
   file1.open(QFile::Text | QFile ::ReadOnly);
   if(!file1.isOpen())
       return;
   QTextStream fst1 (&file1);

   while (!fst1.atEnd())
   {
       QStringList sl=fst1.readLine().split(',');
        if(sl.size()!=6)
            continue;
        (*this)[sl[0]]=book{sl[1],sl[2],sl[3],sl[4].toDouble(),sl[5]};

   }
file1.close();
}

void book_tabel2::load2()
{
   QFile file2(bo2_fn);
   file2.open(QFile::Text | QFile ::ReadOnly);
   if(!file2.isOpen())
       return;
   QTextStream fst2 (&file2);

   while (!fst2.atEnd())
   {
       QStringList sl=fst2.readLine().split(',');
        if(sl.size()!=6)
            continue;
        (*this)[sl[0]]=book{sl[1],sl[2],sl[3],sl[4].toDouble(),sl[5]};

   }
file2.close();
}

void book_tabel3::load3()
{
   QFile file3(bo3_fn);
   file3.open(QFile::Text | QFile ::ReadOnly);
   if(!file3.isOpen())
       return;
   QTextStream fst3 (&file3);

   while (!fst3.atEnd())
   {
       QStringList sl=fst3.readLine().split(',');
        if(sl.size()!=6)
            continue;
        (*this)[sl[0]]=book{sl[1],sl[2],sl[3],sl[4].toDouble(),sl[5]};

   }
file3.close();
}

void book_tabel4::load4()
{
   QFile file4(bo4_fn);
   file4.open(QFile::Text | QFile ::ReadOnly);
   if(!file4.isOpen())
       return;
   QTextStream fst4 (&file4);

   while (!fst4.atEnd())
   {
       QStringList sl=fst4.readLine().split(',');
        if(sl.size()!=6)
            continue;
        (*this)[sl[0]]=book{sl[1],sl[2],sl[3],sl[4].toDouble(),sl[5]};

   }
file4.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////

void book_tabel1::save1()
{
    QFile file1 (bo1_fn);
    file1.open(QFile ::Text | QFile ::WriteOnly);
    if(!file1.isOpen())
    {
        QMessageBox ::warning(0,"Error","cant write into file1");
        throw "cant write into file1";
        return;
    }
    QTextStream fst1(&file1);
    for(book_tabel1::iterator itr=begin();itr!=end();++itr)
    {
        fst1<<itr->first<<","
          <<itr->second.name_book<<","
          <<itr->second.motarjem<<","
          <<itr->second.guide<<","
          <<itr->second.sal_nashr<<","
          <<itr->second.nashr<<endl;
    }
    file1.close();
}


void book_tabel2::save2()
{
    QFile file2 (bo2_fn);
    file2.open(QFile ::Text | QFile ::WriteOnly);
    if(!file2.isOpen())
    {
        QMessageBox ::warning(0,"Error","cant write into file2");
        throw "cant write into file2";
        return;
    }
    QTextStream fst2(&file2);
    for(book_tabel2::iterator itr=begin();itr!=end();++itr)
    {
        fst2<<itr->first<<","
          <<itr->second.name_book<<","
          <<itr->second.motarjem<<","
          <<itr->second.guide<<","
          <<itr->second.sal_nashr<<","
          <<itr->second.nashr<<endl;
    }
    file2.close();
}

void book_tabel3::save3()
{
    QFile file3 (bo3_fn);
    file3.open(QFile ::Text | QFile ::WriteOnly);
    if(!file3.isOpen())
    {
        QMessageBox ::warning(0,"Error","cant write into file3");
        throw "cant write into file3";
        return;
    }
    QTextStream fst3(&file3);
    for(book_tabel3::iterator itr=begin();itr!=end();++itr)
    {
        fst3<<itr->first<<","
          <<itr->second.name_book<<","
          <<itr->second.motarjem<<","
          <<itr->second.guide<<","
          <<itr->second.sal_nashr<<","
          <<itr->second.nashr<<endl;
    }
    file3.close();
}

void book_tabel4::save4()
{
    QFile file4 (bo4_fn);
    file4.open(QFile ::Text | QFile ::WriteOnly);
    if(!file4.isOpen())
    {
        QMessageBox ::warning(0,"Error","cant write into file4");
        throw "cant write into file4";
        return;
    }
    QTextStream fst4(&file4);
    for(book_tabel4::iterator itr=begin();itr!=end();++itr)
    {
        fst4<<itr->first<<","
          <<itr->second.name_book<<","
          <<itr->second.motarjem<<","
          <<itr->second.guide<<","
          <<itr->second.sal_nashr<<","
          <<itr->second.nashr<<endl;
    }
    file4.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////
book_tabel1::~book_tabel1()
{
    save1();
}

book_tabel2::~book_tabel2()
{
    save2();
}

book_tabel3::~book_tabel3()
{
    save3();
}

book_tabel4::~book_tabel4()
{
    save4();
}
///////////////////////////////////////////////////////////////////////////////////////////////
void book::printbooks()
{
    qDebug() << "*******************************************";
    qDebug()<<"booknmae:"<<name_book;
    qDebug()<<"translator & writer :"<<motarjem;
    qDebug()<<"guide:"<<guide;
    qDebug()<<"year of publication:"<<sal_nashr;
    qDebug()<<"publication:"<<nashr;
    qDebug() << "*******************************************"  ;
}

