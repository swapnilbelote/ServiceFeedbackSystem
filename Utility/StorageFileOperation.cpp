#include "StorageFileOperation.h"
#include <QTextStream>

namespace
{

const std::string KNameStr = "Name: ";
const std::string KAddressStr = "Address: ";
const std::string KRatingStr = "Rating: ";
const std::string KFeedbackStr = "Feedback: ";

// Line data is in the below form
// Name: <data> Address: <data> Rating: <data> Feedback: <data>
FileDatatype::FileData FillFileData(std::string line)
{
    FileDatatype::FileData data;

    data.name = QString::fromStdString(line.substr(KNameStr.size(), line.find(KAddressStr) - KNameStr.size() - 1));
    data.address = QString::fromStdString(line.substr(line.find(KAddressStr) + KAddressStr.size(), line.find(KRatingStr) - line.find(KAddressStr) - KAddressStr.size() - 1));
    data.rating = std::stoi(line.substr(line.find(KRatingStr) + KRatingStr.size(), line.find(KFeedbackStr) - line.find(KRatingStr) - KRatingStr.size() - 1));
    data.feedback = QString::fromStdString(line.substr(line.find(KFeedbackStr) + KFeedbackStr.size()));

    return data;
}

}

namespace StorageFileOperation
{

void WriteDataToFile(QFile& file, FileDatatype::FileData& fileData)
{
    if (file.open(QFile::OpenModeFlag::Append))
    {
        QTextStream stream(&file);
        stream << "Name: " << fileData.name.toUtf8().constData()
               << " Address: " << fileData.address.toUtf8().constData()
               << " Rating: " << fileData.rating
               << " Feedback: " << fileData.feedback->toUtf8().constData()
               << "\n";

        file.close();
    }
}

std::vector<FileDatatype::FileData> ReadFile(QFile& file)
{
    std::vector<FileDatatype::FileData> fileData;

    if (file.open(QFile::OpenModeFlag::ReadOnly))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            fileData.push_back(FillFileData(in.readLine().toStdString()));
        }

        file.close();
    }

    return fileData;
}

}
