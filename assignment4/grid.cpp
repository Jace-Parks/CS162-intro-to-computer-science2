#include <iostream>
#include <string>
#include <vector>
#include "grid.h"
#include "player.h"
#include "event.h"
#include "room.h"

using namespace std;

grid::grid(){
  this -> height = 0;
  this -> length = 0;
}

grid::grid(int new_height,int new_length){
  this -> height = new_height;
  this -> length = new_length;
}

void grid::display(int player_x,int player_y,int ix,int iy){
  for(int i = 0;i < height;i++){
    for(int j = 0;j < length;j++){
      cout << "+---+ ";
    }
    cout << endl;
    for(int j = 0;j < length;j++){
      if((player_x == j) && (player_y == i))
        cout << "| * | ";
      else
        cout << "|   | ";
    }
    cout << endl;
    for(int j = 0;j < length;j++){
      cout << "+---+ ";
    }
    cout << endl;
  }
}

void grid::display_debug(vector<vector<room> > rooms,int player_x,int player_y,int ix,int iy){
  for(int i = 0;i < height;i++){
    for(int j = 0;j < length;j++){
      cout << "+---+ ";
    }
    cout << endl;
    for(int j = 0;j < length;j++){
      if((player_x == j) && (player_y == i))
        cout << "| * | ";
      else if(rooms[i][j].get_name() == "pit")
        cout << "| O | ";
      else if(rooms[i][j].get_name() == "bats")
        cout << "| B | ";
      else if(rooms[i][j].get_name() == "wump")
        cout << "| W | ";
      else if(rooms[i][j].get_name() == "gold")
        cout << "| $ | ";
      else if((iy == j) && (ix == i))
        cout << "| | | ";
      else
        cout << "|   | ";
    }
    cout << endl;
    for(int j = 0;j < length;j++){
      cout << "+---+ ";
    }
    cout << endl;
  }
}

void grid::set_rooms(vector<vector<room> > &new_rooms) const{
  vector<vector<room> > rooms(height);
  for(int i = 0;i < height;i++){
    rooms[i] = vector<room>(length);
  }

  for(int i = 0;i < height;i++){
    for(int j = 0;j < length;j++){
      rooms[i][j] = new_rooms[i][j]; 
    }
  }
}
