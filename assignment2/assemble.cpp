#include <iostream>
#include <string>
#include <stdlib.h>
#include "pizza.h"
#include "pizzalogin.h"
#include "menu.h"
#include "restaurant.h"

using namespace std;

int main(int argc,char** argv){
  int em_num = 0;
  int pizzas = get_line();
  bool var;
  employee* mas_array;
  pizza* pizzased;
  pizzased = new pizza[pizzas];
//login
  welcome(argc,argv);
  var = prompt(argc,argv); 
  mas_array = login(argc,argv,var,em_num); 
  login_welcome(var,mas_array,em_num);
//menu    
  restaurant r1;
  r1.load_data_restaurant();
  r1.load_menu(argc,argv,var);

return 0;
}


