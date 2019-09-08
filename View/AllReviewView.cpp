#include "AllReviewView.h"
#include "ui_reviewview.h"
#include "Log/Log.h"

CAllReviewView::CAllReviewView(QWidget* parent): QMainWindow(parent),
                                                 ui(new Ui::CAllReviewView)
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    connect(ui->reviewViewCloseBtn, &QPushButton::clicked, this, &CAllReviewView::OnCloseButtonClicked);
}

CAllReviewView::~CAllReviewView()
{
    LogInfo(Q_FUNC_INFO);

    delete ui;
}

void CAllReviewView::Show(const QRect& rect)
{
    LogInfo(Q_FUNC_INFO);

    this->setGeometry(rect);
    this->show();
}

void CAllReviewView::OnCloseButtonClicked()
{
    LogInfo(Q_FUNC_INFO);

    this->close();
    emit CloseButtonClicked(this->geometry());
}
