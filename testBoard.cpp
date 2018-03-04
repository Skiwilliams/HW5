/*
 *Cullen Williams
 * Board.h
 *
 */
#include "board.h"

int main() {
  Board myboard;

  myboard.Insert(2, 3);
  myboard.Insert(2, 4);
  myboard.MoveTo(203, 2, 4);
  return 0;
}
