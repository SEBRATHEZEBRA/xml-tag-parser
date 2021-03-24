#include <iostream>
#include <string>
#include <cstdlib>
#include "tagParser.h"

void clear(void) {
  system("clear");
}

int main(void) {

  char choice;
  std::string inFile, tagName;

  for (;;) {

    std::cout << "r: Read and process tag file" << std::endl;
    std::cout << "p: Print all tags" << std::endl;
    std::cout << "d: Dump tags and data to a file called tag.txt" << std::endl;
    std::cout << "l: List tag data for given tag to cout" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cout << "Enter an option(r, p, d, l) or q to quit and press return." << std::endl;
    std::cin >> choice;

    if (choice == 'r') {

      std::cout << "Enter the name of the tag file:" << std::endl;
      std::cin >> inFile;

      OLVSEB001::inputFile(inFile);

    } else if (choice == 'p') {

      OLVSEB001::printAllTags();

    } else if (choice == 'd') {

      OLVSEB001::writeToFile();

    } else if (choice == 'l') {

      std::cout << "Enter the name of the tag you're looking for:" << std::endl;
      std::cin >> tagName;

      OLVSEB001::printTag(tagName);

    } else if (choice == 'q') {

      clear();
      break;

    }

  }

  return 0;
}
