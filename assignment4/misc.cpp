#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "grid.h"
#include "player.h"
#include "room.h"
#include "pit.h"
#include "event.h"
#include "bats.h"
#include "misc.h"
#include "gold.h"
#include "wumpus.h"

using namespace std;

int check_int(string check){
  int checked = 0;
  for(int i = 0;i < check.length();i++){
    if(isalpha(check[i]))
    return 0;
  }
  checked = atoi(check.c_str());
  return checked;
}

void debug(int height, int length){
  int randx = 0;
  int randy = 0;
  int shoot = 0;
  bool choi = true;
  wumpus* wumpus1 = new wumpus;
  event* event1 = new event;
  bool swapped = false;
  bool killed = false;

  wumpus1 -> set_death(false);
  vector<vector<room> > rooms(height);
  for(int i = 0;i < height;i++)
    rooms[i] = vector<room>(length);

  srand(time(NULL));
  randx = (rand() % length);
  randy = (rand() % height);

  grid g1(height,length);
  player p1(randx,randy);
 
  set_rooms(rooms,height,length,randx,randy,wumpus1);

  while(true){
    cout << "death" << wumpus1->get_death() << endl;
    if((wumpus1->get_death() == false) && (shoot > 0)){
      for(int i = 0;i < height;i++){
        if(swapped == true)
          break;
        for(int j = 0;j< length;j++){
          if(swapped == true)
            break;
          if(rooms[i][j].get_name() == "wump"){
            
            for(int k = 0;k < 1;k++){
              randx = (rand() % length);
              randy = (rand() % height);
              if((rooms[randy][randx].get_name() == "event") && (randy != p1.get_y()) && (randx != p1.get_x())){
                swap(rooms[i][j],rooms[randy][randx]);   
                swapped = true;  
              }else
                k--; 
            }         
          }
        }   
      }
    }else if(wumpus1->get_death() == true){
       for(int i = 0;i < height;i++){
         if(killed == true)
           break;
         for(int j = 0;j < length;j++){
           if(killed == true)
             break;
           if(rooms[i][j].get_name() == "wump"){
             rooms[i][j].set_event(event1);
             rooms[i][j].set_name("event");
             killed = true;
           }
         } 
       }
    }
    swapped = false;
    shoot = 0;
    for(int i = 0;i < 10;i++){
    hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),randx,randy,choi);
    }
    //clear went here 
    cout << shoot << endl; 
    g1.display_debug(rooms,p1.get_x(),p1.get_y(),randx,randy);
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        hazards(rooms,height,length,p1,rooms[i][j].action(p1.get_x(),p1.get_y()),randx,randy,choi);
      }
    }
    //last clear and display were here
    for(int i = 0;i < height;i++){ 
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
      }
    }
    /*while(true){
      if(rooms[p1.get_x()][p1.get_y()].get_name() == "event")
        break;
      else if((rooms[p1.get_x()][p1.get_y()].get_name() == "bats") || (rooms[p1.get_x()][p1.get_y()].get_name() == "wump") || (rooms[p1.get_x()][p1.get_y()].get_name() == "gold") || (rooms[p1.get_x()][p1.get_y()].get_name() == "pit")){
        hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),randx,randy,choi);
      if(rooms[p1.get_x()][p1.get_y()].get_name() != "bats")
        break;
      }else 
        break;
    }*/
    if((p1.get_gold() == true) && (p1.get_x() == randy) && (p1.get_y() == randx)){
      cout << "YOU HAVE WON" << endl;
      p1.set_gold(false);
      delete [] event1;
      delete [] wumpus1;
      game_over(rooms,height,length,randx,randy,choi);
    }
    shoot = p1.move(height,length);
    shot(rooms,height,length,p1,shoot,wumpus1);
  }
}

void game(int height,int length){
  int randx = 0;
  int randy = 0;
  int shoot = 0;
  bool killed = false;
  bool swapped = false;
  bool choi = false;
  wumpus* wumpus1 = new wumpus;
  event* event1 = new event;
 
  vector<vector<room> > rooms(height);
  for(int i = 0;i < height;i++)
    rooms[i] = vector<room>(length);
  
  srand(time(NULL));
  randx = (rand() % length);
  randy = (rand() % height);

  grid g1(height,length);
  player p1(randx,randy);  
 
  set_rooms(rooms,height,length,randx,randy,wumpus1);

  while(true){
    if((wumpus1->get_death() == false) && (shoot > 0)){
      for(int i = 0;i < height;i++){
        if(swapped == true)
          break;
        for(int j = 0;j< length;j++){
          if(swapped == true)
            break;
          if(rooms[i][j].get_name() == "wump"){

            for(int k = 0;k < 1;k++){
              randx = (rand() % length);
              randy = (rand() % height);
              if((rooms[randy][randx].get_name() == "event") && (randy != p1.get_y()) && (randx != p1.get_x())){
                swap(rooms[i][j],rooms[randy][randx]);
                swapped = true;
              }else
                k--;
            }
          }
        }
      }
    }else if(wumpus1->get_death() == true){
       for(int i = 0;i < height;i++){
         if(killed == true)
           break;
         for(int j = 0;j < length;j++){
           if(killed == true)
             break;
           if(rooms[i][j].get_name() == "wump"){
             rooms[i][j].set_event(event1);
             rooms[i][j].set_name("event");
             killed = true;
           }
         }
       }
    }
    swapped = false;
    shoot = 0;
    for(int i = 0;i < 10;i++){
    hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),randx,randy,choi);
    }
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        hazards(rooms,height,length,p1,rooms[i][j].action(p1.get_x(),p1.get_y()),randx,randy,choi);
      }
    }
    g1.display(p1.get_x(),p1.get_y(),randx,randy);
   /* for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
      }
    }*/
    /*while(true){
      if(rooms[p1.get_x()][p1.get_y()].get_name() != "event")
        hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),randx,randy,choi);
      else if(rooms[p1.get_x()][p1.get_y()].get_name() == "event")
        break;
    }*/
    if((p1.get_gold() == true) && (p1.get_x() == randy) && (p1.get_y() == randx)){
      cout << "YOU HAVE WON" << endl;
      game_over(rooms,height,length,randx,randy,choi);
    }
     for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
      }
    }

    p1.move(height,length);
    system("clear"); 
    
 
  }
}

void game_over(vector<vector<room> > rooms,int height,int length,int p_x,int p_y,bool choi){
  int choice = 0; 

  cout << "GAME OVER" << endl;
  cout << "What would you like to do?" << endl;
  cout << "Press 1 to play again with same settings, press 2 to play with different settings" << endl;
  cout << "Press 3 to exit: ";
  cin >> choice;

  switch(choice){
    case 1 :   
      if(choi == false)
        game_rooms(rooms,height,length,p_x,p_y);
      else if(choi == true)
        game_room_debug(rooms,height,length,p_x,p_y);
    case 2 :
      if(choi == false) 
        game(height,length);
      else if(choi == true)
        debug(height,length);
    case 3 :
      exit(0);
  }
}

void set_rooms(vector<vector<room> > &rooms,int height, int length,int p_x,int p_y,wumpus* wumpus1){
  event* event1 = new event;
  pit* pit1 = new pit;
  bats* bat1 = new bats;
  gold* gold1 = new gold;
  int randx = 0;
  int randy = 0;
  

  for(int i = 0;i < height;i++){
    for(int j = 0;j < length;j++){
      rooms[i][j].set_x(j);
      rooms[i][j].set_y(i);
      rooms[i][j].set_event(event1);
      rooms[i][j].set_name("event");
    }
  }

  for(int i = 0;i < 2;i++){ 
    srand(time(NULL));
    randx = (rand() % length);
    randy = (rand() % height);
    if((randx == p_x) && (randy == p_y))
      i--;
    else if(rooms[randy][randx].get_event() != pit1 && ((randx != p_x) && (randy != p_y))){
      rooms[randy][randx].set_event(pit1);
      rooms[randy][randx].set_name("pit");
    }else
      i--;
    }

   for(int i = 0;i < 2;i++){
     srand(time(NULL));
     randx = (rand() % length);
     randy = (rand() % height);
     if((randx == p_x) && (randy == p_y))
       i--;
     else if((rooms[randy][randx].get_event() != pit1) && (rooms[randy][randx].get_event() != bat1) && ((randx != p_x) && (randy != p_y))){
       rooms[randy][randx].set_event(bat1);
       rooms[randy][randx].set_name("bats");
     }else
       i--;
   }
    
   for(int i = 0;i < 1;i++){
     srand(time(NULL));
     randx = (rand() % length);
     randy = (rand() % height);
     if((randx == p_x) && (randy == p_y))
       i--;
     else if((rooms[randy][randx].get_event() != pit1) && (rooms[randy][randx].get_event() != bat1)  && ((randx != p_x) && (randy != p_y))){
       rooms[randy][randx].set_event(gold1);
       rooms[randy][randx].set_name("gold");
     }else
       i--;
     }

   for(int i = 0;i < 1;i++){
     srand(time(NULL));
     randx = (rand() % length);
     randy = (rand() % height);
     if((randx == p_x) && (randy == p_y))
       i--;
     else if((rooms[randy][randx].get_event() != pit1) && ((rooms[randy][randx].get_event() != bat1) && (rooms[randy][randx].get_event() != gold1))){
       rooms[randy][randx].set_event(wumpus1);
       rooms[randy][randx].set_name("wump");
     }else
       i--;
     }

    
  }

void game_rooms(vector<vector<room> > rooms,int height,int length,int p_x,int p_y){
   grid g1(height,length);
   player p1(p_x,p_y);
   bool choi = false;

    while(true){
      for(int i = 0;i < 10;i++){
        hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),p_x,p_y,choi);
    }
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        hazards(rooms,height,length,p1,rooms[i][j].action(p1.get_x(),p1.get_y()),p_x,p_y,choi);
      }
    }
    g1.display(p1.get_x(),p1.get_y(),p_x,p_y);
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
      }
    }
    /*while(true){
      if(rooms[p1.get_x()][p1.get_y()].get_name() != "event")
        hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),p_x,p_y,choi);
      else if(rooms[p1.get_x()][p1.get_y()].get_name() == "event")
        break;
    }*/
    if((p1.get_gold() == true) && (p1.get_x() == p_x) && (p1.get_y() == p_y)){
      cout << "YOU HAVE WON" << endl;
      game_over(rooms,height,length,p_x,p_y,choi);
    }
    p1.move(height,length);
    system("clear");
    
  }
}

void game_room_debug(vector<vector<room> > rooms,int height, int length, int p_x,int p_y){
   grid g1(height,length);
   player p1(p_x,p_y);
   bool choi = true;
   int shoot = 0;
   int randx = 0;
   int randy = 0;
   bool killed = false;
   bool swapped = false;
   wumpus* wumpus1 = new wumpus;
   event* event1 = new event;
    while(true){
    if((wumpus1->get_death() == false) && (shoot > 0)){
      for(int i = 0;i < height;i++){
        if(swapped == true)
          break;
        for(int j = 0;j< length;j++){
          if(swapped == true)
            break;
          if(rooms[i][j].get_name() == "wump"){

            for(int k = 0;k < 1;k++){
              randx = (rand() % length);
              randy = (rand() % height);
              if((rooms[randy][randx].get_name() == "event") && (randy != p1.get_y()) && (randx != p1.get_x())){
                swap(rooms[i][j],rooms[randy][randx]);
                swapped = true;
              }else
                k--;
            }
          }
        }
      }
    }else if(wumpus1->get_death() == true){
       for(int i = 0;i < height;i++){
         if(killed == true)
           break;
         for(int j = 0;j < length;j++){
           if(killed == true)
             break;
           if(rooms[i][j].get_name() == "wump"){
             rooms[i][j].set_event(event1);
             rooms[i][j].set_name("event");
             killed = true;
           }
         }
       }
    }
    swapped = false;
    shoot = 0;

    for(int i = 0;i < 10;i++)
    hazards(rooms,height,length,p1,rooms[p1.get_x()][p1.get_y()].action(p1.get_x(),p1.get_y()),p_x,p_y,choi);
    g1.display_debug(rooms,p1.get_x(),p1.get_y(),p_x,p_y);
    cout << shoot << endl;
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
        hazards(rooms,height,length,p1,rooms[i][j].action(p1.get_x(),p1.get_y()),p_x,p_y,choi);
      }
    }
    system("clear");
    g1.display_debug(rooms,p1.get_x(),p1.get_y(),p_x,p_y);
    for(int i = 0;i < height;i++){
      for(int j = 0;j < length;j++){
        rooms[i][j].detect(p1.get_x(),p1.get_y());
      }
    }
    if((p1.get_gold() == true) && (p1.get_x() == p_y) && (p1.get_y() == p_x)){
      cout << "YOU HAVE WON" << endl;
      game_over(rooms,height,length,p_x,p_y,choi);
    }
    cout << endl;
    shoot = p1.move(height,length);
    cout << shoot << endl;
    
    system("clear");
    }
}


void hazards(vector<vector<room> > &rooms,int height,int length,player &p1,int action,int in_x,int in_y,bool choi){
  int randx = 0;
  int randy = 0;

  switch(action){
    case 0:
      break;
    case 1:
      game_over(rooms,height,length,in_x,in_y,choi);
      break;
    case 2:
      srand(time(NULL));
      randx = (rand() % length);
      randy = (rand() % height);
      
      p1.set_x(randx);
      p1.set_y(randy);
      break;
    case 3:
      game_over(rooms,height,length,in_x,in_y,choi);
      break;
    case 4:
      p1.set_gold(true);
      break;
  }
}  

void shot(vector<vector<room> > &rooms,int height,int length,player &p1,int shoot,wumpus* wumpus1){
  int range_down = 0;
  int range_left = 0;
  int range_right = 0;
  int range_up = 0;

  if((height - p1.get_y()) >= 3)
    range_down = 3;
  else
    range_down = (height - p1.get_y());

  if(p1.get_y() >= 3)
    range_up = 3;
  else
    range_up = p1.get_y();

  if((length - p1.get_x()) >= 3)
    range_right = 3;
  else 
    range_right = (length - p1.get_x());

  if(p1.get_x() >= 3)
    range_left = 3;
  else 
    range_left = p1.get_x();

  switch(shoot){
    case 1:
      for(int i = 0;i < range_down;i++){
        if(rooms[p1.get_x()][p1.get_y() + i].get_name() == "wump"){
          cout << "shot a" << endl;
          wumpus1->set_death(true);
        }
      }
      break;
    case 2:
      for(int i = 0;i < range_right;i++){
        if(rooms[p1.get_x()][p1.get_y() + i].get_name() == "wump"){
          cout << "shot b" << endl;
          wumpus1->set_death(true);
        }
      }
      break;
    case 3:
      for(int i = 0;i < range_left;i++){
        if(rooms[p1.get_x()][p1.get_y() - i].get_name() == "wump"){
          cout << "shot c" << endl;
          wumpus1->set_death(true);
        }
      }
      break;
    case 4:
      for(int i = 0;i < range_up;i++){
        if(rooms[p1.get_x()][p1.get_y() - i].get_name() == "wump"){
          cout << "shot d" << endl;
          wumpus1->set_death(true);
        }
      }
      break;
    default:
      return;
  }
}
