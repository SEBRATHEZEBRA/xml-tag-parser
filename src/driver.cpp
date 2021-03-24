/*
 * Driver file of a xml tag parser.
 * Author: Sebastian Oliver
 * Date: 24/03/2021
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "tagParser.h"

// Clears the terminal when called.
void clear(void) {
  system("clear");
}

int main(void) {

  std::string choice;
  std::string inFile, tagName;

  // Main input loop.
  for (;;) {

    // Layout of the user menu.
    std::cout << "Options:" << std::endl;
    std::cout << "r: Read and process tag file" << std::endl;
    std::cout << "p: Print all tags" << std::endl;
    std::cout << "d: Dump tags and data to a file called tag.txt" << std::endl;
    std::cout << "l: List tag data for given tag to cout" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cout << "Enter an option(r, p, d, l) or q to quit and press return." << std::endl;
    std::cin >> choice;

    // Calling the corresponding functions when a option is picked.
    // As well checking if a correct option is entered.
    if (choice.length() > 1) {

      clear();
      std::cout << "Enter a single char.\n" << std::endl;

    } else if (choice[0] == 'r') {

      clear();
      std::cout << "Enter the name of the tag file:" << std::endl;
      std::cin >> inFile;

      OLVSEB001::inputFile(inFile);
      std::cout << "" << std::endl;

    } else if (choice[0] == 'p') {

      clear();
      std::cout << "Tag information:" << std::endl;
      OLVSEB001::printAllTags();
      std::cout << "" << std::endl;

    } else if (choice[0] == 'd') {

      clear();
      OLVSEB001::writeToFile();
      std::cout << "" << std::endl;

    } else if (choice[0] == 'l') {

      clear();
      std::cout << "Enter the name of the tag you're looking for:" << std::endl;
      std::cin >> tagName;

      OLVSEB001::printTag(tagName);
      std::cout << "" << std::endl;

    } else if (choice[0] == 'q') {

      clear();
      break;

    } else {

      clear();
      std::cout << "Char you entered isn't an option.\n" << std::endl;

    }

  }

  return 0;
}
