#include "ServiceFeedback.h"
#include "ui_servicefeedback.h"
#include "Log/Log.h"
#include "ThankYou.h"

CServiceFeedback::CServiceFeedback(QWidget *parent) :QMainWindow(parent),
                                                     ui(new Ui::CServiceFeedback),
                                                     thankYouUi(new CThankYou(this))
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, this,  &CServiceFeedback::onResetClick);
    connect(ui->pushButton, &QPushButton::clicked, this,  &CServiceFeedback::onSubmitClick);
    connect(thankYouUi, &CThankYou::closeButtonClicked, this, &CServiceFeedback::onThankYouUiCloseClick);
}

CServiceFeedback::~CServiceFeedback()
{
    LogInfo(Q_FUNC_INFO);

    delete ui;
    delete thankYouUi;
}

unsigned int CServiceFeedback::GetRating() const
{
    LogInfo(Q_FUNC_INFO);

    if (ui->radioButton->isChecked())
    {
        return 1;
    }
    else if (ui->radioButton_2->isChecked())
    {
        return 2;
    }
    else if (ui->radioButton_3->isChecked())
    {
        return 3;
    }
    else if (ui->radioButton_4->isChecked())
    {
        return 4;
    }
    else if (ui->radioButton_5->isChecked())
    {
        return 5;
    }

    return 0;
}

bool CServiceFeedback::IsMandetoryDetailsEntered() const
{
    LogInfo(Q_FUNC_INFO);

    QString name = ui->lineEdit->text();
    QString address = ui->lineEdit_2->text();
    unsigned int rating = GetRating();

    if (name.isEmpty() || address.isEmpty() || rating == 0)
    {
        QString errorMsg = QString("Please enter ");
        if (name.isEmpty()) errorMsg.append(QString("name"));
        if (address.isEmpty())
        {
            if (name.isEmpty()) errorMsg.append(QString(", address"));
            else errorMsg.append(QString("address"));
        }
        if(rating == 0)
        {
            if (name.isEmpty() || address.isEmpty()) errorMsg.append(QString(", rating"));
            else errorMsg.append(QString ("rating"));
        }

        QLabel* errorMessageLabel = ui->label_5;
        errorMessageLabel->setStyleSheet("QLabel { color : red; }");
        errorMessageLabel->setText(errorMsg);

        return false;
    }

    return true;
}

void CServiceFeedback::onResetClick()
{
    LogInfo(Q_FUNC_INFO);

    ui->plainTextEdit->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->label_5->clear();

    ui->radioButton->setAutoExclusive(false);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_5->setAutoExclusive(false);

    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_5->setChecked(false);
}

void CServiceFeedback::onSubmitClick()
{
    LogInfo(Q_FUNC_INFO);
    
    ui->label_5->clear();

    if (IsMandetoryDetailsEntered())
    {
        QString name = ui->lineEdit->text();
        QString address = ui->lineEdit_2->text();
        QString feedback = ui->plainTextEdit->toPlainText();

        qDebug("Name : %s, Address : %s, Rating : %d, Feedback : %s",
               name.toUtf8().constData(),
               address.toUtf8().constData(),
               GetRating(),
               feedback.toUtf8().constData());

        thankYouUi->Show();
        this->hide();
    }
}

void CServiceFeedback::onThankYouUiCloseClick()
{
    LogInfo(Q_FUNC_INFO);

    thankYouUi->close();
    this->close();
}
