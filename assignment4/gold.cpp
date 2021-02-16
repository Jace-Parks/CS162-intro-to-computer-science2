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
#include "gold.h"

using namespace std;

void gold::detect(){
  cout << "You see a glimmer nearby" << endl;
}

int gold::action(){
  cout << "You've found the gold" << endl;
  return 4;
}


