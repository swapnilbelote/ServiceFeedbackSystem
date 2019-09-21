#include "AllReviewView.h"
#include "ui_reviewview.h"
#include "Log/Log.h"
#include "Utility/StorageFileOperation.h"

#include <QListWidgetItem>

namespace
{
const int KColumn = 4;
const std::vector<std::pair<int, QString>> KHeaderString = {{0, "Name"},
                                                            {1, "Address"},
                                                            {2, "Rating"},
                                                            {3, "Feedback"}};
}
CAllReviewView::CAllReviewView(QWidget* parent, QFile &file): QMainWindow(parent),
                                                              ui(new Ui::CAllReviewView),
                                                              iFileStorage(file)
{
    LogInfo(Q_FUNC_INFO);

    ui->setupUi(this);

    QStringList columnHeader;
    columnHeader << KHeaderString[0].second <<
        KHeaderString[1].second <<
        KHeaderString[2].second <<
        KHeaderString[3].second;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(columnHeader);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

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
    ShowReviews();
}

void CAllReviewView::OnCloseButtonClicked()
{
    LogInfo(Q_FUNC_INFO);

    this->close();
    emit CloseButtonClicked(this->geometry());
}

void CAllReviewView::ShowReviews()
{
    std::vector<FileDatatype::FileData> fileDataList = StorageFileOperation::ReadFile(iFileStorage);

    qDebug("Data file: %d", fileDataList.size());

    for (size_t index = 0; index < fileDataList.size(); ++index)
    {
        ui->tableWidget->insertRow(index);

        QTableWidgetItem * nameItem = new QTableWidgetItem();
        nameItem->setData( Qt::DisplayRole, QVariant(fileDataList[index].name));
        ui->tableWidget->setItem(index, KHeaderString[0].first,  nameItem);

        QTableWidgetItem * addressItem = new QTableWidgetItem();
        addressItem->setData( Qt::DisplayRole, QVariant(fileDataList[index].address));
        ui->tableWidget->setItem(index, KHeaderString[1].first, addressItem);

        QTableWidgetItem * ratingItem = new QTableWidgetItem();
        ratingItem->setData( Qt::DisplayRole, QVariant(fileDataList[index].rating));
        ui->tableWidget->setItem(index, KHeaderString[2].first, ratingItem );

        QTableWidgetItem * feedbackItem = new QTableWidgetItem();
        feedbackItem->setData( Qt::DisplayRole, QVariant(fileDataList[index].feedback.value()));
        ui->tableWidget->setItem(index, KHeaderString[3].first, feedbackItem );
    }
}
