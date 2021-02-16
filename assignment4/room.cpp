#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "event.h"
#include "pit.h"
#include "player.h"

using namespace std;

room::room(){
  this -> x = 0;
  this -> y = 0;
  this -> name = "NO NAME";
  this -> this_event = NULL;
}

room::room(int length,int height){
  this -> x = length;
  this -> y = height;
  this -> name = "NO NAME";
  this -> this_event = NULL;
}

void room::set_event(event* new_event){
  this -> this_event = new_event;
}

event* room::get_event() const{
  return this_event;
}

int room::get_x() const{
  return x;
}

int room::get_y() const{
  return y;
}

void room::set_x(int newx){
  this -> x = newx;
}

void room::set_y(int newy){
  this -> y = newy;
}

void room::set_name(string new_name){
  this -> name = new_name;
}

string room::get_name() const{
  return name;
}

void room::detect(int player_x,int player_y){
  if(((player_x + 1) == x) && (player_y == y))
    this_event->detect();
  else if(((player_x - 1) == x) && (player_y == y))
    this_event->detect();
  else if((player_x == x) && ((player_y + 1)== y))
    this_event->detect();
  else if((player_x == x) && ((player_y - 1)== y))
    this_event->detect();
}

int room::action(int player_x,int player_y){ 
  if((player_x == x) && (player_y == y))
    return(this_event->action());
  return 0; 
}

room& room::operator=(const room& old_room){
  this -> x = old_room.get_x();
  this -> y = old_room.get_y();
  this -> name = old_room.get_name();
  this -> this_event = old_room.get_event();
}
