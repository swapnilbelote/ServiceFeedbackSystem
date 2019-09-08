#include "ServiceFeedback.h"
#include "ui_servicefeedback.h"
#include "Log/Log.h"
#include "ThankYou.h"
#include "Utility/StorageFileOperation.h"

CServiceFeedback::CServiceFeedback(QFile& fileStorage, QWidget *parent) : QMainWindow(parent),
                                                                          ui(new Ui::CServiceFeedback),
                                                                          thankYouUi(new CThankYou(this)),
                                                                          iFileStorage(fileStorage)
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    connect(ui->resetPushButton, &QPushButton::clicked, this,  &CServiceFeedback::onResetClick);
    connect(ui->submitPushButton, &QPushButton::clicked, this,  &CServiceFeedback::onSubmitClick);
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

    if (ui->rating_1->isChecked())
    {
        return 1;
    }
    else if (ui->rating_2->isChecked())
    {
        return 2;
    }
    else if (ui->rating_3->isChecked())
    {
        return 3;
    }
    else if (ui->rating_4->isChecked())
    {
        return 4;
    }
    else if (ui->rating_5->isChecked())
    {
        return 5;
    }

    return 0;
}

bool CServiceFeedback::IsMandetoryDetailsEntered() const
{
    LogInfo(Q_FUNC_INFO);

    QString name = ui->nameLineEdit->text();
    QString address = ui->addressLineEdit->text();
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

        QLabel* errorMessageLabel = ui->errorLabel;
        errorMessageLabel->setStyleSheet("QLabel { color : red; }");
        errorMessageLabel->setText(errorMsg);

        return false;
    }

    return true;
}

void CServiceFeedback::onResetClick()
{
    LogInfo(Q_FUNC_INFO);

    ui->feedbackPlainTextEdit->clear();
    ui->nameLineEdit->clear();
    ui->addressLineEdit->clear();
    ui->errorLabel->clear();

    ui->rating_1->setAutoExclusive(false);
    ui->rating_2->setAutoExclusive(false);
    ui->rating_3->setAutoExclusive(false);
    ui->rating_4->setAutoExclusive(false);
    ui->rating_5->setAutoExclusive(false);

    ui->rating_1->setChecked(false);
    ui->rating_2->setChecked(false);
    ui->rating_3->setChecked(false);
    ui->rating_4->setChecked(false);
    ui->rating_5->setChecked(false);
}

void CServiceFeedback::onSubmitClick()
{
    LogInfo(Q_FUNC_INFO);
    
    ui->errorLabel->clear();

    if (IsMandetoryDetailsEntered())
    {
        FileDatatype::FileData data(ui->nameLineEdit->text().toUtf8().constData(),
                                    ui->addressLineEdit->text().toUtf8().constData(),
                                    GetRating(),
                                    ui->feedbackPlainTextEdit->toPlainText().toUtf8().constData());

        qDebug("Name : %s, Address : %s, Rating : %d, Feedback : %s",
               data.name.c_str(),
               data.address.c_str(),
               data.rating,
               data.feedback->c_str());

        StorageFileOperation::WriteDataToFile(iFileStorage, data);

        thankYouUi->Show(this->geometry());
        this->hide();
    }
}

void CServiceFeedback::onThankYouUiCloseClick()
{
    LogInfo(Q_FUNC_INFO);

    thankYouUi->close();
    this->close();
}
