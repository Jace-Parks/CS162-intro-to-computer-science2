#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "event.h"

using namespace std;

class room{
private:
  int x;
  int y;
  string name;
  event* this_event;
public:
  room();
  room(int,int);
  void set_event(event*);
  void set_x(int);
  void set_y(int); 
  int get_y() const;
  int get_x() const;
  void set_name(string);
  string get_name() const;
  void detect(int,int);
  int action(int,int);
  event* get_event() const;
  room& operator=(const room& old_room);
};

#endif
