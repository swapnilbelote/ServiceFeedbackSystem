#ifndef ALLREVIEWVIEW_H
#define ALLREVIEWVIEW_H

#include <QFile>
#include <QMainWindow>

namespace Ui {
class CAllReviewView;
}

class CAllReviewView : public QMainWindow
{
    Q_OBJECT

public:
    CAllReviewView(QWidget* parent, QFile& file);
    ~CAllReviewView();

    void Show(const QRect& rect);

signals:
    void CloseButtonClicked(const QRect& rect);

public slots:
    void OnCloseButtonClicked();

private:
    void ShowReviews();

private:
    Ui::CAllReviewView* ui;
    QFile& iFileStorage;
};

#endif // ALLREVIEWVIEW_H
