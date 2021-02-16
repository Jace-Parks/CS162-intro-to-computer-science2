#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <string>
#include "animal.h"
#include "monkey.h"
#include "meerkat.h"
#include "otter.h"

class zoo{
  private:
    int money;
    int b_monkeys;
    int b_meerkats;
    int b_otters;
    int num_monkeys;
    int num_meerkats;
    int num_otters;
    int day;
    int babies;
    float food_cost;
    monkey* monkeys;
    meerkat* meerkats;
    otter* otters;

    void display_info();  
    void prompt();  
    void add_rev();
    int get_num_monkeys() const;
    int get_num_meerkats() const;
    int get_num_otters() const;
    int get_num_b_mon() const;
    int get_num_b_mee() const;
    int get_num_b_ott() const;
    void update();
    void feed();
    void rando_event();
    void get_sick();
    bool heal(animal&);
    void remove_meerkat(int);
    void remove_otter(int);
    void remove_monkey(int);
    void birth();
    void boom();
    void lose();

  public:
    zoo();
    zoo(const zoo&); 
    int get_day() const;
    zoo& operator=(const zoo&); 
    int get_money() const;
    void choose();
    void buy_monkey();
    void buy_meerkat();
    void buy_otter();
    void end_turn();
    ~zoo();
};

#endif 
