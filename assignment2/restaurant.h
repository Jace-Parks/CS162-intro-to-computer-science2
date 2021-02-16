#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include "pizzalogin.h"
#include "menu.h"

using namespace std;

class restaurant {
  private:
    int num_employs;
    menu menued;
    employee* employees;
    hours* week;
    int num_order;
    order* orders;
    string name;
    string phone;
    string address;

  public:

    restaurant();
    ~restaurant();
    void load_data_employees();
    void load_data_restaurant();
    void load_menu(int,char**,bool);
    void choices(int,char**,bool,int);
    void view_menu();
    void view_hours();
    void load_orders();
    void view_orders();
    void remove_order();
    /*void search_menu();
    void search_ingredients();
    void place_order(pizza* selection,int selection_size,int* num_ordered);*/
    void change_hours();
   // void remove_menu();
   // void remove_orders();
};
#endif
