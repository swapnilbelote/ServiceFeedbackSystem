#include "ServiceFeedback.h"
#include "ui_servicefeedback.h"
#include "Log/Log.h"

CServiceFeedback::CServiceFeedback(QWidget *parent) :
                                                      QMainWindow(parent),
                                                      ui(new Ui::CServiceFeedback)
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, this,  &CServiceFeedback::onResetClick);
    connect(ui->pushButton, &QPushButton::clicked, this,  &CServiceFeedback::onSubmitClick);
}

CServiceFeedback::~CServiceFeedback()
{
    LogInfo(Q_FUNC_INFO);

    delete ui;
}

void CServiceFeedback::onResetClick()
{
    LogInfo(Q_FUNC_INFO);

    ui->plainTextEdit->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void CServiceFeedback::onSubmitClick()
{
    LogInfo(Q_FUNC_INFO);
}
