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

using namespace std;

void bats::detect(){
  cout << "You hear flapping wings" << endl;
}

int bats::action(){
   cout << "You've been moved" << endl;
   return 2;
}

