#include <iostream>
#include <string>
#include <vector>
#include "pit.h"
#include "room.h"
#include "event.h"
#include "misc.h"
#include "player.h"

using namespace std;

void pit::detect(){
  cout << "You feel a breeze" << endl;
}

int pit::action(){
  cout << "you have fallen in the pit" << endl;
  return 3;  
}

