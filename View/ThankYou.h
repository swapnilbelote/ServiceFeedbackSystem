#ifndef THANKYOU_H
#define THANKYOU_H

#include <QMainWindow>
#include <QMovie>

namespace Ui {
class CThankYou;
}

class CThankYou : public QMainWindow
{
    Q_OBJECT

public:
    explicit CThankYou(QWidget* parent);
    ~CThankYou();

    void Show();

signals:
    void closeButtonClicked();

private:
    Ui::CThankYou* ui;
    QMovie mo;
};

#endif // THANKYOU_H
