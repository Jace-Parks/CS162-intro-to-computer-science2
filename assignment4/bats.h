#ifndef BATS_H
#define BATS_H
#include <iostream>
#include <string>
#include "event.h"
#include "player.h"
#include "room.h"

using namespace std;

class bats: public event {
  private:
  public:
    void detect();
    int action();
};
#endif
