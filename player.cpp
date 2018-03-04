/*
 *Cullen Williams
 * Player.cpp
 */
#include "player.h"

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
  coordUpdate();
  vanityName();
}

/* Constructor:
 */
Player::Player(int id, int x, int y) {
  posx = x;
  posy = y;
  ID = id;
  coordUpdate();
  vanityName();
}

// gives players usless but fun names
void Player::vanityName() {
  std::string inname = "";
  int rand = clock() % 14;
  std::ifstream fin;
  fin.open("Names.txt");
  for (int i = 0; i <= rand; i++) {
    std::getline(fin, inname);
  }
  name = inname;
}

// coordinate naming system
void Player::coordUpdate() {
  SID = "";
  std::stringstream ID;
  ID << "x, " << posx << "y, " << posy;
  ID >> SID;
}

/*Passes a copy of the x coordinate*/
int Player::returnX() { return posx; }

/*Passes a copy of the y coordinate*/
int Player::returnY() { return posy; }

int Player::returnID() { return ID; }

std::string Player::returnName() { return name; }
