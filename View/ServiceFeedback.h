#ifndef SERVICEFEEDBACK_H
#define SERVICEFEEDBACK_H

#include <QFile>
#include <QMainWindow>

namespace Ui {
class CServiceFeedback;
}

class CThankYou;
class CAllReviewView;

class CServiceFeedback : public QMainWindow
{
    Q_OBJECT

public:
    explicit CServiceFeedback(QFile& fileStorage, QWidget *parent = nullptr);
    ~CServiceFeedback();

private slots:
    void OnResetClicked();
    void OnSubmitClicked();
    void OnThankYouUiCloseClicked(const QRect& rect);
    void OnAllReviewViewClicked();
    void OnAllReviewViewCloseClicked(const QRect& rect);

private:
    unsigned int GetRating() const;
    bool IsMandetoryDetailsEntered() const;

private:
    Ui::CServiceFeedback *ui;
    CThankYou* thankYouUi;
    CAllReviewView* allReviewView;
    QFile& iFileStorage;
};

#endif // SERVICEFEEDBACK_H
