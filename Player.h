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

// mutates x y and SID to newX and newY passed as arguments
void coordUpdate(int newX, int newY);

// makes useless but fun names for each player
void vanityName();

// returns player ID for idBoard
int getID();

// returns player SID for coordBoard
std::string getSID();

// returns the vanity name of a player
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
