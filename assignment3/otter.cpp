#include <iostream>
#include <string>
#include "otter.h"

using namespace std;

otter::otter(){
  this -> age = 0;
  this -> sickness = false;
  this -> cost = 5000;
}

otter& otter::operator=(const otter& old_otter){
  this -> age = old_otter.get_age();
}
