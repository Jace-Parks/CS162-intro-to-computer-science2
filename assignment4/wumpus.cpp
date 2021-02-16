#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "pit.h"
#include "room.h"
#include "event.h"
#include "misc.h"
#include "player.h"
#include "bats.h"
#include "wumpus.h"

using namespace std;

wumpus::wumpus(){
  this -> dead = false;
}

void wumpus::detect(){
  cout << "You smell a terrible stench" << endl;
}

int wumpus::action(){
 cout << "The wumpus has eaten you" << endl;
 return 1;
}

void wumpus::set_death(bool new_death){
  this -> dead = new_death;
}

bool wumpus::get_death(){
  return dead;
}
