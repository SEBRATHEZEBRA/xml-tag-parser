#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "tagParser.h"

std::vector<OLVSEB001::TagStruct> tags;

struct OLVSEB001::TagStruct {
  std::string name;
  int count;
  std::string text;
};

void OLVSEB001::printTag(std::string tagName) {

  int i = searchVector(tagName);
  if (i == -1) {

    std::cout << "Tag does not exist." << std::endl;

  } else {

    std::cout << tags.at(i).name << ", " << tags.at(i).count << ", " << tags.at(i).text << std::endl;

  }

}

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

  std::replace(line.begin(), line.end(), '\t', ' ');

  first = line.find('>');
  tagName = line.substr(1, first - 1);
  second = line.find('<', first);
  text = line.substr(first + 1, second - first - 1);

  OLVSEB001::addToVector(tagName, text);

}

void OLVSEB001::inputFile(std::string file) {
  std::ifstream ifs(file.c_str());
  std::string line, prevLine;
  bool multiple;

  prevLine = "";
  while (std::getline(ifs, line, '\n')) {

    if (line.compare("") == 0) {
      continue;
    } else {

        if (line.length() > line.find("</") && !multiple) {

          OLVSEB001::lineSplitter(line);

        } else if (line.length() > line.find("</") && multiple) {

          prevLine = prevLine + line;
          OLVSEB001::lineSplitter(prevLine);
          prevLine = "";

        } else {
          multiple = true;
          prevLine = prevLine + line;

        }

    }



  }

  ifs.close();
}
