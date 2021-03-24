#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "tagParser.h"

// Creating a global vector variable to hold all the tags.
std::vector<OLVSEB001::TagStruct> tags;

// Creating a structure that stores the required information of a tag.
struct OLVSEB001::TagStruct {

  std::string name;
  int count;
  std::string text;
};

// Writes the tag data stored in the vector to a file called tag.txt.
void OLVSEB001::writeToFile() {

  std::string line;

  std::ofstream ofs("output/tag.txt");
  for (OLVSEB001::TagStruct e:tags) {
    line = e.name + ", " + std::to_string(e.count) + ", " + e.text;
    ofs << line << std::endl;
  }

  std::cout << "Tag information has to been written to output/tag.txt." << std::endl;

}

// Prints out the tag information of the tag provided, if its found.
void OLVSEB001::printTag(std::string tagName) {

  int i = searchVector(tagName);
  if (i == -1) {

    std::cout << "Tag does not exist." << std::endl;

  } else {

    std::cout << tags.at(i).name << ", " << tags.at(i).count << ", " << tags.at(i).text << std::endl;

  }

}

// Prints out all the information of the tags stored in the vector variable.
void OLVSEB001::printAllTags() {

  for (OLVSEB001::TagStruct e:tags) {
      std::cout << e.name << ", " << e.count << ", " << e.text << std::endl;
  }

}

// Searches the vector variable to see if it contains the tagName, returning the index of the tagName if found.
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

// Adds the provided tag information to the vector variable, either by creating a new structure or adding to an already defined one.
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

// Splits the line into their tag names and text inbetween the tags.
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

// Reads the provided input file into a string line by line.
void OLVSEB001::inputFile(std::string file) {

  std::ifstream ifs(file.c_str());
  std::string line, prevLine;
  bool multiple;

  prevLine = "";
  while (std::getline(ifs, line, '\n')) {

    if (line.compare("") == 0) {
      continue;
    } else {

        // Checking if a tag is multiple lines or not, if it is the lines are concatenated together.
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
