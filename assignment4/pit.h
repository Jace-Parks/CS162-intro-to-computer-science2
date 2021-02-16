#ifndef PIT_H
#define PIT_H 
#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include "room.h"
#include "player.h"

using namespace std;

class pit: public event {
  private:
    int height;
    int length;
  public:
    void detect();
    int action();
};

#endif
