#include <QApplication>
#include <QtWidgets>
#include <logiciel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logiciel logiciel;
    logiciel.show();
    return a.exec();
}
