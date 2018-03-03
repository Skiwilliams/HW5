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
}

/* Constructor:
 */
Player::Player(int x, int y) {
  posx = x;
  posy = y;
  std::string inname = "";
  int rand = clock() % 14;
  // sets player id as a combination of x and y coordinates
  std::stringstream IDCreate;
  IDCreate << x << 0 << y;
  IDCreate >> ID;
  // totally useless but fun naming system
  std::ifstream fin;
  fin.open("Names.txt");
  for (int i = 0; i <= rand; i++) {
    std::getline(fin, inname);
  }
  name = inname;
}

/*Passes a copy of the x coordinate*/
int Player::returnX() { return posx; }

/*Passes a copy of the y coordinate*/
int Player::returnY() { return posy; }

int Player::returnID() { return ID; }

std::string Player::returnName() { return name; }
