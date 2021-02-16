#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include <string>
#include "event.h"
#include "room.h"
#include "player.h"

using namespace std;

class gold: public event{
  private:
  public:
    void detect();
    int action();
    void set_ip_x(int);
    void set_ip_y(int);
    void set_dim(int,int);
};
#endif
