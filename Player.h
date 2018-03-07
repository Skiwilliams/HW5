/*
 *Cullen Williams & Garrick Hutcheson
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

  void coordUpdate(int newX, int newY);

  void vanityName();

  int getID();

  std::string getSID();

  std::string getName();

  /*Passes a copy of the x coordinate*/
  int getX();

  /*Passes a copy of the y coordinate*/
  int getY();

private:
  std::string SID;
  int ID;
  std::string name;
  int posx;
  int posy;
};

#endif
