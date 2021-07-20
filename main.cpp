#include <QApplication>
#include<mwidget.h>
#include<QMessageBox>
#include<windows.h>

QTextStream qout (stdout) ;
QTextStream qin (stdin) ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("color F0");
    mwidget dd;
    dd.show();

    return a.exec();
}



