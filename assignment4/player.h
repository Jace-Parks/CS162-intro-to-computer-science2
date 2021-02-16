#ifndef PLAYER_H
#define PLAYER_H
#include "bats.h"

class player{
  private:
    int x;
    int y;
    int height;
    int length;
    int arrows;
    bool gold;

    void move_w();
    void move_a(int);
    void move_d();
    void move_s(int);

    int shoot_s();
    int shoot_d();
    int shoot_a();
    int shoot_w();
  public:
    player();
    player(int,int);
   
    void set_random_pos();
    void set_height(int);
    void set_length(int); 
    int get_x();
    int get_y();
    void set_x(int);
    void set_y(int);
    int move(int,int);
    bool get_gold();
    void set_gold(bool);
};

#endif
