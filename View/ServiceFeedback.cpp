#include "ServiceFeedback.h"
#include "ui_servicefeedback.h"

CServiceFeedback::CServiceFeedback(QWidget *parent) :
                                                      QMainWindow(parent),
                                                      ui(new Ui::CServiceFeedback)
{
    ui->setupUi(this);
}

CServiceFeedback::~CServiceFeedback()
{
    delete ui;
}
