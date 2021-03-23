#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "tagParser.h"


struct OLVSEB001::TagStruct {
  char *name;
  int pairCount;
  char *text;
};

void OLVSEB001::inputFile(std::string file) {
  std::string line;
  std::ifstream ifs(file.c_str());

  while (std::getline(ifs, line, '\n')) {

    std::istringstream iss(line);
    std::string current;
    while (!iss.eof()) {
      iss >> current >> std::ws;
      std::cout << current << std::endl;
    }

  }

  ifs.close();
}
