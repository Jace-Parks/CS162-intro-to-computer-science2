#ifndef GRID_H
#define GRID_H
#include <vector>
#include "player.h"
#include "room.h"

using namespace std;

class grid{
  private:
    int height;
    int length;
    friend class player;
  public:
    grid();
    grid(int,int);
    void set_rooms(vector<vector<room> >&) const;
    void display(int,int,int,int);
    void display_debug(vector<vector<room> >,int,int,int,int);
};

#endif
