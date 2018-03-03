/*
 *Cullen Williams
 * Player.h
 */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

class Player {

public:
  /* Constructor: the empty one
   */
  Player();

  /* Constructor: the not empty one
   */
  Player(int id, int x, int y);

  int returnID();

  std::string returnName();

  /*Passes a copy of the x coordinate*/
  int returnX();

  /*Passes a copy of the y coordinate*/
  int returnY();

  void setID(int id);

private:
  int ID;
  std::string name;
  int posx;
  int posy;
};

#endif
