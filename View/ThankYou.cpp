#include "ThankYou.h"
#include "ui_thankyou.h"
#include "Log/Log.h"

#include <QDir>

CThankYou::CThankYou(QWidget* parent) : QMainWindow (parent),
                                        ui(new Ui::CThankYou)
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    mo.setFileName(":/Resources/ThankYou.gif");
    mo.setScaledSize(QSize(431, 321));

    ui->label->setMovie(&mo);

    connect(ui->pushButton, &QPushButton::clicked, this, &CThankYou::closeButtonClicked);
}

CThankYou::~CThankYou()
{
    LogInfo(Q_FUNC_INFO);

    delete ui;
}

void CThankYou::Show(const QRect &rect)
{
    LogInfo(Q_FUNC_INFO);

    mo.start();

    this->setGeometry(rect);
    this->show();
}
