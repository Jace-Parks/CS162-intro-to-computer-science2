#ifndef WUMPUS_H
#define WUMPUS_H
#include <iostream>
#include <string>
#include "event.h"
#include "player.h"
#include "room.h"

using namespace std;

class wumpus: public event{
  private:
   bool dead;
  public:
    wumpus();
    void detect();
    int action();
    void set_death(bool);
    bool get_death();
};

#endif
