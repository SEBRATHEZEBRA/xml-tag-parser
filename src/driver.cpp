#include <iostream>
#include <cstdlib>
#include "tagParser.h"

int main(void) {

  char choice;

  for (;;) {
    std::cout << "r: Read and process tag file" << std::endl;
    std::cout << "p: Print all the tags" << std::endl;
    std::cout << "d: Dump tags and data to a file called tag.txt" << std::endl;
    std::cout << "l: List tag data for given tag to cout" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cout << "Enter an option(r, p, d, l) or q to quit and press return." << std::endl;

    std::cin >> choice;

    if (choice == 'q') {
      break;
    }
  }

  return 0;
}

void clear(void) {
  system("clear");
}
