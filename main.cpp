#include "View/ServiceFeedback.h"
#include "Log/Log.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    LogInfo(Q_FUNC_INFO, "Start of the application");

    QApplication a(argc, argv);
    CServiceFeedback w;
    w.show();

    LogInfo(Q_FUNC_INFO, "End of application");
    return a.exec();
}
