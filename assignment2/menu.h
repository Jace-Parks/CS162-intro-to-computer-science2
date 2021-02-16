#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include "pizza.h"

using namespace std;

class menu{
  private:
    int num_pizzas;
    pizza* pizzas;
  public:
    menu();
    menu(int);
    ~menu();

    void display_menu();
    menu search_cost(int);
    menu search_ingred_exclude(string*,int);
    void add_to_menu(pizza);
    void load_file_add();
    void load_file_remove();
    void add();
    void remove_from(int);
    void get_order_user(string&,int&,int&);
    void get_info(string&,int&,int&);
    void load_file();
    void place_order();
    void upload_order(string*,int);
    void search_ingredients();
    void include_ingredients();
    void exclude_ingredients();
    void exclude(string*,int);
    void compare_ingredients(string*,int);
    bool ingredients_include(string);
};
#endif
