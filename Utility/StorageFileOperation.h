#ifndef STORAGEFILEOPERATION_H
#define STORAGEFILEOPERATION_H

#include <vector>
#include <QFile>

#include "Utility/DataType/FileDatatype.h"

namespace StorageFileOperation
{
void WriteDataToFile(QFile& file, FileDatatype::FileData& fileData);
std::vector<FileDatatype::FileData> ReadFile(QFile& file);
}

#endif // STORAGEFILEOPERATION_H
