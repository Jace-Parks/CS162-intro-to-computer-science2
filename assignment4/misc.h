#ifndef MISC_H
#define MISC_H
#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "event.h"
#include "wumpus.h"
using namespace std;

int check_int(string);
void game(int,int);
void debug(int,int);
void game_over(vector<vector<room> >,int,int,int,int,bool);
void set_rooms(vector<vector<room> > &,int,int,int,int,wumpus*);
void game_rooms(vector<vector<room> >,int,int,int,int);
void game_room_debug(vector<vector<room> >,int,int,int,int);
void hazards(vector<vector<room> > &rooms,int height,int length,player &p1,int action,int,int,bool);
void shot(vector<vector<room> > &rooms,int height,int length,player &p1,int shoot,wumpus*);
#endif
