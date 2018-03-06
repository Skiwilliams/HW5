/*
 *Cullen Williams & Garrick Hutcheson
 * Board.h
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include "player.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <sstream>
#include <string>

class Board {

public:
  /* Constructor:
   */
  Board();
  Board(int bS);

  /*Insert method in the Board class that will allow you to add a new player
  to the board.  The method should take as input the player ID to be inserted
  along with a desired (x,y) position into which it is to be initially placed.
  For successful insertion, (i) a player with the same ID should not already
  exist on the board; AND (ii) the specified insertion position on board
  should be currently unoccupied. A third condition would be to ensure the
  total number of players with this insertion should not exceed m. If
  successful, the method should update n and return true. If insertion fails,
   the code should display an error message and return false without changing
    anything*/

  bool Insert(int id, int x, int y);
  /*Implement  a  Remove  method  in  the  Board  class  that  will  allow
    you  to remove  a  player  from  the  board.  The  method  should  take
    as  input  the player ID to be removed, and should return true upon
    successful removal and  false  otherwise  (i.e.,  player  not  found).
    The  value  of  n  should also  be  accordingly  updated.  Note  that
    upon  successful  removal,  the corresponding  cell  on  the  board
    should  become  available  for  newer insertions.
*/

  std::string intPairToSearchString(int x, int y);

  bool coordEmpty(int x, int y);

  bool remove(int ID);

  bool removeByCoord(int x, int y);

  /*Find  method  in  the  Board  class  that  is  given  a  player  ID
and returns true if the player is found and false otherwise.
*/
  bool find(int ID);

  /*MoveTo
  takes as input a player ID and a destination (x2,y2) cell position.

first locate the player
move the player from (x1,y1), (x2,y2) only if: (x2,y2) is within
  bounds, AND the movement from (x1,y1) to (x2,y2) is always along the same
    row, same column, or same diagonal in any direction

If the destination cell (x2,y2) already has some other player, say Y. Then
this function should first remove Y from the board before placing this
player (ID) in its new position. If any player was removed in the process, the
method should print a message to indicate which player was removed. prints when
player eliminated Returns True on successfull move or displays error and returns
false
*/
  bool moveTo(int ID, int xto, int yto);

  /* PrintByID method in the Board class that prints all the player IDs along
     with their (x,y) positions, in the increasing order of their IDs. Again,
     the print should not display any unoccupied positions.
*/
  void printByID();
  void printByVan();

  bool checkBounds(int x, int y);
  bool checkValidMove(int x1, int y1, int x2, int y2);

  void printFancy();

private:
  std::map<int, Player> idBoard;
  std::map<std::string, std::map<int, Player>::iterator> coordBoard;
  int boardSize;
  int numberOfPlayers;
};

#endif
