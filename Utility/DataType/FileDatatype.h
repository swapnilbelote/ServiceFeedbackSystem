#ifndef FILEDATATYPE_H
#define FILEDATATYPE_H

#include <QString>
#include <optional>

namespace FileDatatype
{
  struct FileData
  {
      QString name;
      QString address;
      unsigned int rating;
      std::optional<QString> feedback;

      FileData() : name(""), address(""), rating(0), feedback(std::nullopt)
      {
      }

      FileData(QString aName,
               QString aAddress,
               unsigned int aRating,
               std::optional<QString> aFeedback) : name(aName),
                                                   address(aAddress),
                                                   rating(aRating),
                                                   feedback(aFeedback)
      {
      }
  };
}
#endif // FILEDATATYPE_H
