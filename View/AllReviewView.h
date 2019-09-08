#ifndef ALLREVIEWVIEW_H
#define ALLREVIEWVIEW_H

#include <QMainWindow>

namespace Ui {
class CAllReviewView;
}

class CAllReviewView : public QMainWindow
{
    Q_OBJECT

public:
    CAllReviewView(QWidget* parent);
    ~CAllReviewView();

    void Show(const QRect& rect);

signals:
    void CloseButtonClicked(const QRect& rect);

public slots:
    void OnCloseButtonClicked();

private:
    Ui::CAllReviewView* ui;
};

#endif // ALLREVIEWVIEW_H
