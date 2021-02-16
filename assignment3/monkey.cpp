#include <iostream>
#include "monkey.h"

using namespace std;

monkey::monkey(){
  this -> age = 0;
  this -> sickness = false;
  this ->  cost = 15000; 
}

monkey& monkey::operator=(const monkey& old_monkey){
  age = old_monkey.get_age();
}
