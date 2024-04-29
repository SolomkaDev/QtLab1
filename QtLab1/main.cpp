#include "Pages.h"
#include <QTextCodec>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pages w;
    w.show();
    return a.exec();
}
