#include "View/ServiceFeedback.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CServiceFeedback w;
    w.show();

    return a.exec();
}
