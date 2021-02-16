#include <iostream>
#include <string>
#include "misc.h"
#include "zoo.h"
#include "assemble.h"
#include "animal.h"
#include "meerkat.h"
#include "monkey.h"
#include "otter.h"

using namespace std;

int main(){
  welcome();
  int i = 0;
  zoo* update;
  update = new zoo[2];
  zoo z1;
  zoo z2;
 
  update[0] = z1;
  update[1] = z2;
  while(true){
    if( i == 0){
      update[1].choose();
      i++;
      update[0] = update[1];
      update[0].end_turn();
    }else if( i == 1){
      update[0].choose();
      i--;
      update[1] = update[0];
      update[1].end_turn();
    }
  }
}
