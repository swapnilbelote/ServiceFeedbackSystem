#ifndef FILEDATATYPE_H
#define FILEDATATYPE_H

#include <string>
#include <optional>

namespace FileDatatype
{
  struct FileData
  {
      std::string name;
      std::string address;
      unsigned int rating;
      std::optional<std::string> feedback;

      FileData() : name(""), address(""), rating(0), feedback(std::nullopt)
      {
      }

      FileData(std::string aName,
               std::string aAddress,
               unsigned int aRating,
               std::optional<std::string> aFeedback) : name(aName),
                                                       address(aAddress),
                                                       rating(aRating),
                                                       feedback(aFeedback)
      {
      }
  };
}
#endif // FILEDATATYPE_H
