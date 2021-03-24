#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "tagParser.h"

std::vector<OLVSEB001::TagStruct> tags;

struct OLVSEB001::TagStruct {
  std::string name;
  int pairCount;
  std::string text;
};

int OLVSEB001::searchVector(std::string tag) {

}

void OLVSEB001::addToVector(std::string tagName, std::string text) {
  int exists = OLVSEB001::searchVector(tagName);
  if (exists > -1) {

  }
}

void OLVSEB001::lineSplitter(std::string line) {
  std::string tagName, text;
  int first, second;

  first = line.find('>');
  tagName = line.substr(1, first - 1);
  second = line.find('<', first);
  text = line.substr(first + 1, second - first - 1);

  OLVSEB001::addToVector(tagName, text);

}

void OLVSEB001::inputFile(std::string file) {
  std::ifstream ifs(file.c_str());
  std::string line;

  while (std::getline(ifs, line, '\n')) {

    OLVSEB001::lineSplitter(line);

  }

  ifs.close();
}
