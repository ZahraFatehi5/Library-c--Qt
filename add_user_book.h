#ifndef ADD_USER_BOOK_H
#define ADD_USER_BOOK_H

#include<QString>
#include<QStringList>
#include<map>
#include<QFile>
#include<QTextStream>

#define book_borrow "borrow.txt"


    class add_user_book
    {
    public:


    QString name_of_book;
    QString guide_of_book;
    QString number_of_user;  //kasi ke ketab gerefte

    void printbu();
    };

    class  ztabel:public std::map<QString,add_user_book>
    {
        public:

        ztabel();

        bool add_bo();
        void savew();
        void loadw();
        void print_usbo();
        ~ ztabel();
    };


#endif // ADD_USER_BOOK_H
