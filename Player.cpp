/*
 *Cullen Williams & Garrick Hutcheson
 * Player.cpp
 */
#include "Player.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
/* Constructor:
 */
Player::Player() {
  posx = 0;
  posy = 0;
  name = "Regie";
  coordUpdate(posx, posy);
  vanityName();
}

/* Constructor:
 */
Player::Player(int id, int x, int y) {
  posx = x;
  posy = y;
  ID = id;
  coordUpdate(x, y);
  vanityName();
}

// gives players usless but fun names
void Player::vanityName() {
  std::string inname = "";
  int rand = clock() % 23;
  std::ifstream fin;
  fin.open("Names.txt");
  for (int i = 0; i <= rand; i++) {
    std::getline(fin, inname);
  }
  name = inname;
}

// coordinate naming system
void Player::coordUpdate(int newX, int newY) {
  posx = newX;
  posy = newY;
  SID = "";
  std::stringstream ID;
  ID << "x " << posx << ",y " << posy;
  SID = ID.str();
}

/*Passes a copy of the x coordinate*/
int Player::getX() { return posx; }

std::string Player::getSID() { return SID; }

/*Passes a copy of the y coordinate*/
int Player::getY() { return posy; }

// Passes a copy of players ID
int Player::getID() { return ID; }

std::string Player::getName() { return name; }
