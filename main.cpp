#include "View/ServiceFeedback.h"
#include "Log/Log.h"

#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    LogInfo(Q_FUNC_INFO, "Start of the application");

    QApplication a(argc, argv);

    QFile fileStorage("data.txt");
    CServiceFeedback w(fileStorage);
    w.show();

    LogInfo(Q_FUNC_INFO, "End of application");
    return a.exec();
}
