/*
 * Cullen Williams & Garrick Hutcheson
 * Board.cpp
 */
#include "board.h"
#include <iostream>

/* Constructor: Default
   default board size: 10X10
 */
Board::Board() {
  boardSize = 10;
  numberOfPlayers = 0;
  tote = 0;
}

/* Constructor: Default
   takes 10 players by if none given
 */
Board::Board(int bS) {
  std::map<int, Player> idBoard;
  boardSize = bS;
  numberOfPlayers = 0;
  tote = 0;
}

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
bool Board::Insert(int x, int y) {
  int id;
  std::string searchString = intPairToSearchString(x, y);
  // sets player id as a combination of x and y coordinates
  id = totePlayers();
  if (coordEmpty(x, y)) {

    tote++; // incrementing total players who have played on boardSize

    // inserting new player in idBoard and storing return info from insert
    // operation in pair insertInfo
    std::pair<std::map<int, Player>::iterator, bool> insertInfo =
        idBoard.insert(std::pair<int, Player>(id, Player(id, x, y)));

    // inserting new pair in to coordBoard, pair consists of searchable xy
    // string  and iterator to new player stored in idBoard
    coordBoard.insert(std::pair<std::string, std::map<int, Player>::iterator>(
        searchString, insertInfo.first));
    numberOfPlayers++;
    return true;
  }
  return false;
}

int Board::totePlayers() { return tote; }

/*

bool Board::Insert(int p, int x, int y) {
    idBoard.insert(std::pair<int, Player>(p, Player(p, x, y)));
    numberOfPlayers++;
    tote++;
    return true;
}
*/

std::string Board::intPairToSearchString(int x, int y) {
  std::stringstream idCreate;
  idCreate << "x " << x << ",y " << y;
  return idCreate.str();
}

bool Board::coordEmpty(int x, int y) {
  std::string searchString = intPairToSearchString(x, y);
  if (coordBoard.find(searchString.c_str()) == coordBoard.end()) {
    return true;
  }
  std::cout << "no space at: " << searchString.c_str() << std::endl;
  return false;
}

/*Implement  a  Remove  method  in  the  Board  class  that  will  allow
   you  to remove  a  player  from  the  board.  The  method  should  take
   as  input  the player ID to be removed, and should return true upon
   successful removal and  false  otherwise  (i.e.,  player  not  found).
   The  value  of  n  should also  be  accordingly  updated.  Note  that
   upon  successful  removal,  the corresponding  cell  on  the  board
   should  become  available  for  newer insertions.
 */
bool Board::remove(int i) {
  if (find(i)) {
    std::map<int, Player>::iterator toDel;
    toDel = idBoard.find(i);
    // delete from coordmap
    coordBoard.erase(toDel->second.getSID());
    // deletefrom idmap
    idBoard.erase(i);
    std::cout << "Player " << i << " removed" << std::endl;
    numberOfPlayers--;
    return true;
  }
  std::cout << "Player not found" << std::endl;
  return false;
}

bool Board::removeByCoord(int x, int y) {
  std::string moveSID = intPairToSearchString(x, y);

  std::map<std::string, std::map<int, Player>::iterator>::iterator
      coordBoardItr = coordBoard.find(moveSID);
  if (coordBoardItr != coordBoard.end()) // player at new space
  {
    idBoard.erase(coordBoardItr->second);
    coordBoard.erase(coordBoardItr);
    numberOfPlayers--;
    return true;
  }

  return false;
}

/*Find  method  in  the  Board  class  that  is  given  a  player  ID
   and returns true if the player is found and false otherwise.
 */
bool Board::find(int ID) {
  return (idBoard.find(ID) == idBoard.end()) ? (false) : (true);
}

/*MoveTo
   takes as input a player ID and a destination (x2,y2) cell position.  The
   method should first locate the player, and move the player from its current
   position,(x1,y1), to the new position (x2,y2) only if: (x2,y2) is within
   bounds, AND the movement from (x1,y1) to (x2,y2) is always along the same
   row, same column, or same diagonal in any direction
   if the destination cell (x2,y2) already has some other player, say Y. Then
   this function should first remove Y from the board before placing this
   player (ID) in its new position. Upon a successful move, the method should
   return true. If any player was removed in the process, the method should
   print a message to indicate which player was removed. If the move fails, the
   code should display an error message stating the reason of failure and
   return false.
   Note: Any player(s) on the board along the path of moving from (x1,y1) to
   (x2,y2) is/are left unaffected by this move.
 */
bool Board::moveTo(int ID, int xto, int yto) {
  if (find(ID)) {
    removeByCoord(xto, yto);
    std::map<int, Player>::iterator movingPlayer = idBoard.find(ID);
    coordBoard.erase(movingPlayer->second.getSID());
    movingPlayer->second.coordUpdate(xto, yto);
    coordBoard.insert(std::pair<std::string, std::map<int, Player>::iterator>(
        movingPlayer->second.getSID(), movingPlayer)); // find and movement
  } else {
    std::cout << "Player " << ID << "not found." << std::endl;
    return false;
  }
  return true;
}

/* PrintByID method in the Board class that prints all the player IDs along
   with their (x,y) positions, in the increasing order of their IDs. Again,
   the print should not display any unoccupied positions.
 */
void Board::printByID() {
  for (std::map<int, Player>::iterator p = idBoard.begin(); p != idBoard.end();
       p++) {
    std::cout << "ID: " << p->second.getID() << " X: " << p->second.getX()
              << " y: " << p->second.getY() << std::endl;
  }
}

void Board::printFancy() {}
