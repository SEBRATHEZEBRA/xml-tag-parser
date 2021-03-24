#ifndef TAGPARSER_H
#define TAGPARSER_H

#include <string>

// Declaring all my functions and the structure I use in my source program "tagParser.cpp."
namespace OLVSEB001 {
  struct TagStruct;
  void writeToFile();
  void printTag(std::string tagName);
  void printAllTags();
  int searchVector(std::string tagName);
  void addToVector(std::string tagName, std::string text);
  void lineSplitter(std::string line);
  void inputFile(std::string file);
}

#endif
