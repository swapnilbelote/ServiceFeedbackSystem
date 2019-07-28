#ifndef SERVICEFEEDBACK_H
#define SERVICEFEEDBACK_H

#include <QMainWindow>

namespace Ui {
class CServiceFeedback;
}

class CThankYou;

class CServiceFeedback : public QMainWindow
{
    Q_OBJECT

public:
    explicit CServiceFeedback(QWidget *parent = nullptr);
    ~CServiceFeedback();

private slots:
    void onResetClick();
    void onSubmitClick();
    void onThankYouUiCloseClick();

private:
    unsigned int GetRating() const;
    bool IsMandetoryDetailsEntered() const;

private:
    Ui::CServiceFeedback *ui;
    CThankYou* thankYouUi;
};

#endif // SERVICEFEEDBACK_H
