#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

meerkat::meerkat(){
  this -> age = 0;
  this -> cost = 500;
  this -> sickness = false;
}

meerkat& meerkat::operator=(const meerkat& old_meerkat){
  this -> age = old_meerkat.get_age();
}

meerkat::~meerkat(){

}
