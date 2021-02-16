#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

player::player(){
  this -> x = 0;
  this -> y = 0;
  this -> height = 0;
  this -> length = 0; 
  this -> arrows = 3;
}

player::player(int h, int l){
  this -> x = l;
  this -> y = h;
  this -> arrows = 3;
  this -> height = 0;
  this -> length = 0;
}

void player::move_w(){
  if(y > 0){
    y--;
  }else
    cout << "You can't move back" << endl;
}

void player::move_a(int length){
  if(x < (length-1))
    x++;
  else
    cout << "you can't move to the right" << endl;
}

void player::move_d(){
  if(x > 0)
    x--;
  else
    cout << "you can't move to the left" << endl;
}

void player::move_s(int height){
  if(y < (height-1))
    y++;
  else
    cout << "You can't move down" << endl;
}

void player::set_height(int new_height){
  this -> height = new_height;
}

void player::set_length(int new_length){
  this -> length = new_length;
}

void player::set_random_pos(){
  int random_x = 0;
  int random_y = 0;

  cout << "here" << endl;
  srand(time(NULL));
  cout << "here" << endl;
  random_x = (rand() % length);
  random_y = (rand() % height); 

  this -> x = random_x;
  this -> y = random_y;

 cout << "good so far" << endl;  
}


int player::shoot_s(){
  if(arrows > 0){
    this -> arrows--;
    return 1;
  }else{
   cout << "You have no arrows" << endl;
   return 0;
  }
  return 0;
}

int player::shoot_d(){
  if(arrows > 0){
    this -> arrows--;
    return 2;
  }else{
   cout << "You have no arrows" << endl;
   return 0;
  }
  return 0;
}

int player::shoot_a(){
  if(arrows > 0){
    this -> arrows--;
    return 3;
  }else{
   cout << "You have no arrows" << endl;
   return 0;
  }
  return 0;
}

int player::shoot_w(){
  if(arrows > 0){
    this -> arrows--;
    return 4;
  }else{
   cout << "You have no arrows" << endl;
   return 0;
  }
  return 0;
}

int player::get_x(){
  return x;
}

int player::get_y(){
  return y;
}

int player::move(int height,int length){
  string choice;

  cout << "what would you like to do?" << endl;
  getline(cin,choice);

  if((choice[0] == 's') || (choice[0] == 'S')){
    move_s(height);
    return 0;
  }else if((choice[0] == 'd') || (choice[0] == 'D')){
    move_a(length);
    return 0;
  }else if((choice[0] == 'a') || (choice[0] == 'A')){
    move_d();
    return 0;
  }else if((choice[0] == 'w') || (choice[0] == 'W')){
    move_w();
    return 0;
  }else if((choice[0] == ' ') && ((choice[1] == 'S') || (choice[1] == 's')))
    return(shoot_s());
  else if((choice[0] == ' ') && ((choice[1] == 'D') || (choice[1] == 'd')))
    return(shoot_d());
  else if((choice[0] == ' ') && ((choice[1] == 'A') || (choice[1] == 'a')))
    return(shoot_a());
  else if((choice[0] == ' ') && ((choice[1] == 'W') || (choice[1] == 'w')))
    return(shoot_w());
  else
    move(height,length);
  
}

void player::set_x(int new_x){
  this -> x = new_x;
}

void player::set_y(int new_y){
  this -> y = new_y;
}

bool player::get_gold(){
  return gold;
}

void player::set_gold(bool new_gold){
  cout << "YOU HAVE FOUND THE GOLD" << endl;
  this -> gold = new_gold;
}
