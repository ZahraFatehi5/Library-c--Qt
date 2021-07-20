#ifndef BOOK_H
#define BOOK_H
#include<QString>
#include<QStringList>
#include<map>
#include<QFile>
#include<QTextStream>

#define bo1_fn "darsi.txt"
#define bo2_fn "romman.txt"
#define bo3_fn "tarikhi.txt"
#define bo4_fn "elmi.txt"

class book
{
public:


    QString name_book;
    QString motarjem;
    QString guide;
    double sal_nashr;
    QString  nashr;

    void printbooks();

};

class book_tabel1:public std:: map<QString ,book>
{
public:
    book_tabel1();

    void printbooks();
    void load1();  
    void save1();
    ~book_tabel1();
};
class book_tabel2:public std:: map<QString ,book>
{
public:
    book_tabel2();

    void printbooks2();
     void load2();
     void save2();
     ~book_tabel2();

};

class book_tabel3:public std:: map<QString ,book>
{
public:
    book_tabel3();

    void printbooks3();

    void load3();
    void save3();
    ~book_tabel3();


};

class book_tabel4:public std:: map<QString ,book>
{
public:
    book_tabel4();

    void printbooks4();

    void load4();
    void save4();
    ~book_tabel4();

};

#endif // BOOK_H
