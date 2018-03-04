/*Cullen Williams
 * Board.cpp
 */
#include "board.h"
#include "player.h"
#include <iostream>

/* Constructor: Default
 default board size: 10X10
 */
Board::Board() {
  boardSize = 10;
  numberOfPlayers = 0;
}

/* Constructor: Default
  takes 10 players by if none given
 */
Board::Board(int bS) {
  std::map<int, Player> MBoard;
  boardSize = bS;
  numberOfPlayers = 0;
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
  // sets player id as a combination of x and y coordinates
  std::stringstream IDCreate;
  IDCreate << x << 0 << y;
  IDCreate >> id;
  MBoard.insert(std::pair<int, Player>(id, Player(id, x, y)));
  return true;
}

bool Board::Insert(int p, int x, int y) {
  MBoard.insert(std::pair<int, Player>(p, Player(p, x, y)));
  return true;
}

/*Implement  a  Remove  method  in  the  Board  class  that  will  allow
you  to remove  a  player  from  the  board.  The  method  should  take
as  input  the player ID to be removed, and should return true upon
successful removal and  false  otherwise  (i.e.,  player  not  found).
The  value  of  n  should also  be  accordingly  updated.  Note  that
upon  successful  removal,  the corresponding  cell  on  the  board
should  become  available  for  newer insertions.
*/
bool Board::Remove() { return false; }

/*Find  method  in  the  Board  class  that  is  given  a  player  ID
and returns true if the player is found and false otherwise.
*/
bool Board::Find(int ID) {
  // uses map to locate player by ID
  return false;
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
bool Board::MoveTo(int ID, int xto, int yto) {
  // find and movement
  if (Find(ID)) {
  }
  std::cout << "Player " << ID << "not found." << std::endl;
  return false;
}

/* PrintByID method in the Board class that prints all the player IDs along
 with their (x,y) positions, in the increasing order of their IDs. Again,
 the print should not display any unoccupied positions.
*/
void Board::PrintByID() {}
