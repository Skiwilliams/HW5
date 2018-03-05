/*
 *Cullen Williams & Garrick Hutcheson
 * Board.h
 *
 */
#include "board.h"

int main() {
  Board myboard;

  myboard.Insert(2, 3);
  myboard.Insert(2, 4);
  myboard.Insert(9, 9);

  myboard.printByID();
  if (myboard.find(0)) {
    std::cout << "found 0" << std::endl;
  }
  // if (myboard.remove(2)) {
  // std::cout << "removed 2" << std::endl;
  //}
  if (myboard.find(1)) {
    std::cout << "found 1" << std::endl;
  }

  if (myboard.moveTo(0, 2, 4)) {
    std::cout << "moved 0 to 1" << std::endl;
  }

  myboard.printByID();

  if (myboard.moveTo(0, 9, 9)) {
    std::cout << "moved 0 to tintin" << std::endl;
  }

  myboard.printByID();

  return 0;
}
