#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

int animal::get_age() const{
  return age;  
}

void animal::set_age(int new_age){
  this -> age = new_age;
}

void animal::add_age(){
  this -> age++;
}

void animal::sick(){
  this -> sickness = true;
}

bool animal::get_sick(){
  return sickness;
}

int animal::get_cost(){
  return cost;
}

void animal::not_sick(){
  this -> sickness = false;
}
