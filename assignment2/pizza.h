#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>

using namespace std;

#define MAX_INGREDIENTS 10

class pizza{

  private:
    string name;
    int num_pizzas;
    int max_ingredients;
    int sml_cost;
    int med_cost;
    int lrg_cost;
    int num_ingr;
    string* ingredients;
 
  public:
    pizza();
    ~pizza();
    pizza(const pizza&);
    pizza& operator=(const pizza&);   

     
    void set_name(string&);
    void set_num_ingredients(int&);
    void set_num_pizzas(int&);
    void set_lrg_cost(int&);
    void set_med_cost(int&);
    void set_sml_cost(int&);
    string get_name() const;
    int get_num_ingredients() const;
    int get_num_pizzas() const;
    int get_lrg_cost() const; 
    int get_med_cost() const;
    int get_sml_cost() const;
    void set_from_file(int);
    void display();    
    void add_menu(pizza*,int);
    void remove_menu(pizza*,int);
    void acost(int,int);
    bool ingredients_include(string);
    bool ingredients_exclude(string*,int);
    //void pick(pizza*,int);
    void out(pizza*,int);
};
#endif
