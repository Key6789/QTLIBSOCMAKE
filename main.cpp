#include "QTWidgetAndLib.h"

#include <QApplication>
#include <QDebug>
#include <QLibrary>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTWidgetAndLib w;
    w.show();

    
    /*QLibrary lib("Test11");
    if (!lib.load()) {
        qDebug() << "Failed to load library" << endl;
        return 1;
    }                                                         
    typedef int (*addTest888)(int, int);
    addTest888 addTestFunc = (addTest888)lib.resolve("addTest");
    if (!addTestFunc) {
        qDebug() << "Failed to resolve function" << endl;
        return 1;
    }
    int num = addTestFunc(3, 4);
    qDebug() << "The sum is: " << num  << endl;
    */
    //int num = addTest(3, 4);
   // qDebug() << "The sum is: " << num  << endl;
    return a.exec();
}
