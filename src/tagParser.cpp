#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "tagParser.h"

std::vector<OLVSEB001::TagStruct> tags;

struct OLVSEB001::TagStruct {
  std::string name;
  int count;
  std::string text;
};

void OLVSEB001::printAllTags() {
  for (OLVSEB001::TagStruct e:tags) {
      std::cout << e.name << ", " << e.count << ", " << e.text << std::endl;
  }

}

int OLVSEB001::searchVector(std::string tagName) {
  int i = 0;
  for (OLVSEB001::TagStruct e:tags) {
    if (e.name.compare(tagName) == 0)
    {
      return i;
    }
    i++;
  }

  return -1;
}

void OLVSEB001::addToVector(std::string tagName, std::string text) {
  int exists = OLVSEB001::searchVector(tagName);
  if (exists > -1) {
    tags.at(exists).count++;
    tags.at(exists).text = tags.at(exists).text + ":" + text;
  } else {

    OLVSEB001::TagStruct getOn;
    getOn.name = tagName;
    getOn.count = 1;
    getOn.text = text;
    tags.push_back(getOn);

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

  //OLVSEB001::printAllTags();

  ifs.close();
}
