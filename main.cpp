#include "widget.h"
#include <QApplication>
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login o;
    o.show();

    return a.exec();
}