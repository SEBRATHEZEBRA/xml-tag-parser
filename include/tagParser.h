#ifndef TAGPARSER_H
#define TAGPARSER_H

#include <string>

namespace OLVSEB001 {
  struct TagStruct;
  int searchVector(std::string tagName);
  void addToVector(std::string tagName, std::string text);
  void lineSplitter(std::string line);
  void inputFile(std::string file);
}

#endif
