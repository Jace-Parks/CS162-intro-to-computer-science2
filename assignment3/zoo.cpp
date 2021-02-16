#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdlib>
#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "meerkat.h"
#include "otter.h"

using namespace std;

void zoo::display_info(){
  int baby = 0;
  int adol = 0;
  int adult = 0;
  cout << "Your zoo's money is " <<  money << endl;
  cout << "You have " << num_monkeys << " monkeys" << endl;
  cout << "You have " << num_meerkats << " meerkats" << endl;
  cout << "You have " << num_otters << " otters" << endl << endl;

  for(int i = 0;i < num_monkeys;i++){
    if(num_monkeys > 0){
      if(monkeys[i].get_age() < 5)
        baby++;
      if((monkeys[i].get_age() < 52) && (monkeys[i].get_age() > 5))
        adol++;
      if(monkeys[i].get_age() > 52)
        adult++;
    }
  }
  cout << "The number of baby monkeys is " << baby << endl;
  cout << "The number of adolescent monkeys is " << adol << endl;
  cout << "The number og adult monkeys is " << adult << endl << endl;
  baby = 0;
  adol = 0;
  adult = 0;
  for(int i = 0;i < num_meerkats;i++){
    if(num_meerkats > 0){
      if(meerkats[i].get_age() < 5)
        baby++;
      if((meerkats[i].get_age() < 52) && (meerkats[i].get_age() > 5))
        adol++;
      if(meerkats[i].get_age() > 52)
        adult++;
    }
  }  
  cout << "The number of baby meerkats is " << baby << endl;
  cout << "The number of adolescent meerkats is " << adol << endl;
  cout << "The number of adult meerkats is " << adult << endl << endl;
  baby = 0;
  adol = 0;
  adult = 0;
  for(int i = 0;i < num_otters;i++){
    if(num_otters > 0){
      if(otters[i].get_age() < 5)
        baby++;
      if((otters[i].get_age() < 52) && (otters[i].get_age() > 5))
        adol++;
      if(otters[i].get_age() > 52)
        adult++;
    }
  }
  cout << "The number of baby otters is " << baby << endl;
  cout << "The number of adolescent otters is " << adol << endl;
  cout << "The number of adult otters " << adult << endl << endl;
}

zoo::zoo(){
  this -> money = 100000;
  this -> b_monkeys = 0;
  this -> b_meerkats = 0;
  this -> b_otters = 0;
  this -> num_monkeys = 0;
  this -> num_meerkats = 0;
  this -> num_otters = 0;
  this -> day = 0;
  this -> monkeys = NULL;
  this -> meerkats = NULL;
  this -> otters = NULL;
}

zoo::zoo(const zoo& old_zoo){
  money = old_zoo.get_money();
  num_monkeys = old_zoo.get_num_monkeys();
  num_meerkats = old_zoo.get_num_meerkats();
  num_otters = old_zoo.get_num_otters();
  day = old_zoo.day;
  monkeys = new monkey[num_monkeys];
  meerkats = new meerkat[num_meerkats];
   otters = new otter[num_otters];
  for(int i = 0;i < num_monkeys;i++){
    if(day == 0){
      monkeys[i] = old_zoo.monkeys[i];   
      monkeys[i].set_age(56);
    }else
      monkeys[i] = old_zoo.monkeys[i];  
  }
  for(int i = 0;i < num_meerkats;i++){
    if(day == 0){
    meerkats[i] = old_zoo.meerkats[i];
    meerkats[i].set_age(56);
    }else
      meerkats[i] = old_zoo.meerkats[i];
  }
  for(int i = 0;i < num_otters;i++){
    if(day == 0){
    otters[i] = old_zoo.otters[i];
    otters[i].set_age(56);
    }else
      monkeys[i] = old_zoo.monkeys[i];
  } 

}

int zoo::get_day() const{
  return day;
}

zoo& zoo::operator=(const zoo& old_zoo){
    if(this != &old_zoo){
      if(monkeys != NULL)
        delete [] monkeys;
      if(meerkats != NULL)
        delete [] meerkats;
      if(otters != NULL)
        delete [] otters;
      
      money = old_zoo.money;
      num_monkeys = old_zoo.num_monkeys;
      num_meerkats = old_zoo.num_meerkats;
      num_otters = old_zoo.num_otters;
      b_monkeys = 0;
      b_meerkats = 0;
      b_otters = 0;

      day = old_zoo.day;
      monkeys = new monkey[num_monkeys];
      for(int i = 0;i < num_monkeys;i++){
        monkeys[i] = old_zoo.monkeys[i];
        if(day == 0)
          monkeys[i].set_age(56);
      }

      meerkats = new meerkat[num_meerkats];
      for(int i = 0;i < num_meerkats;i++){
        meerkats[i] = old_zoo.meerkats[i];
        if(day == 0)
          meerkats[i].set_age(56);
      }

      otters = new otter[num_otters];
      for(int i = 0;i < num_otters;i++){
        otters[i] = old_zoo.otters[i];
        if(day == 0)
          otters[i].set_age(56);
      }
   }
  return *this;
}

int zoo::get_money() const{
  return money;
}

void zoo::choose(){
  display_info();
  cout << "1. Buy Meerkat" << endl;
  cout << "2. Buy Monkey" << endl;
  cout << "3. Buy Otter" << endl;
  cout << "4. Buy Food" << endl;
  cout << "5. End turn" << endl;
  prompt();
}

void zoo::prompt(){
  int choice = 0;
  cout << "Please select one: ";
  cin >> choice;
  switch(choice){
    case 1 :
      buy_meerkat(); 
      choose();
      break;
    case 2 :
      buy_monkey();
      choose();
      break;
    case 3 : 
      buy_otter();
      choose();
      break;
    case 4 :
      cout << "Buy food for animal" << endl;
      break;
    case 5 :
      end_turn();
      break;
    default: 
      prompt();
      break;
    
  }
}

void zoo::buy_monkey(){
  cout << money << endl;
  int b_ani = b_monkeys + b_otters + b_meerkats;
  if((money >= 15000) && (b_monkeys < 2)){
    if((b_otters < 0) && (b_meerkats < 0)){
      this -> money = money - 15000;
      this -> num_monkeys++;
      this -> b_monkeys = b_monkeys + 1;
    }
  }else
    cout << "You do not have enough money or you've bought 2 before" << endl;
}

void zoo::buy_meerkat(){
  cout << money << endl;
  cout << "the number of bought meerkats is " << b_meerkats << endl; 
  if((money >= 500) && (b_meerkats < 2) && (b_meerkats < 0) && (b_otters < 0)){
    this -> money = money - 500;
    this -> num_meerkats++;
    this -> b_meerkats = b_meerkats + 1;
  }else
    cout << "You do not have enough money or you've bought 2 before" << endl;
}

void zoo::buy_otter(){
  if((money >= 5000) && (b_otters < 2) && (b_monkeys < 0) && (b_meerkats < 0)){
    this -> money = money - 5000;
    this -> num_otters++;
    this -> b_otters = b_otters + 1;
  }else
    cout << "You do not have enough money or you've bought 2 before" << endl;
}

void zoo::end_turn(){
  rando_event();
  add_rev();
  day++;
  for(int i = 0;i < num_meerkats;i++){
    meerkats[i].add_age();
  }
  for(int i = 0;i < num_monkeys;i++){
    monkeys[i].add_age();
  }
  for(int i = 0;i < num_otters;i++){
    otters[i].add_age();
  }
}

void zoo::add_rev(){
  for(int i = 0;i < num_meerkats;i++){
    if(meerkats[i].get_age() < 5)
      this -> money = money + 50;
    if((meerkats[i].get_age() < 52) && (meerkats[i].get_age() > 5))
      this -> money = money + 25;
    if(meerkats[i].get_age() > 52)
      this -> money = money + 25;
  }
  for(int i = 0;i < num_monkeys;i++){
    if(monkeys[i].get_age() < 5)
      this -> money = money + 1500;
    if((monkeys[i].get_age() < 52) && (monkeys[i].get_age() > 5))
      this -> money = money + 750;
    if(monkeys[i].get_age() > 52)
      this -> money = money + 750;
  }
  for(int i = 0;i < num_otters;i++){
    if(otters[i].get_age() < 5)
      this -> money = money + 500;
    if((otters[i].get_age() < 52) && (otters[i].get_age() > 5))
      this -> money = money + 250;
    if(otters[i].get_age() > 52)
      this -> money = money + 250;
  }
}

int zoo::get_num_monkeys() const{
  return num_monkeys;
}

int zoo::get_num_meerkats() const{
  return num_meerkats;
}

int zoo::get_num_otters() const{ 
  return num_otters;
}

int zoo::get_num_b_mon() const{
  return b_monkeys;
}

int zoo::get_num_b_mee() const{
  return b_meerkats;
}

int zoo::get_num_b_ott() const{
  return b_otters;
}

void zoo::update(){
  int rando = 0;
  srand(time(NULL));
  rando = (rand() % 4) + 1;

  cout << rando << endl;
}

void zoo::rando_event(){
  int rando = 0;
  srand(time(NULL));
  rando = (rand() % 4) + 1;
  cout << rando << endl; 
  switch(rando){
    case 1:
      //gets sick
      cout << "This bitch sick af" << endl;
      get_sick();
      break;
    case 2: 
     //animal gives birth
     cout << "giving birth" << endl;
     birth();
     break;
    case 3:
     //boom in attendence
     cout << "boom" << endl;
     boom();
     break;
    case 4:
     cout << "Nothing happened" << endl;
     break;
  }
} 

void zoo::get_sick(){
  srand(time(NULL));
  int random_A;
  int animals;
  animals = num_monkeys + num_meerkats + num_otters;
  random_A = (rand() % animals);

  if((random_A < num_meerkats) && (num_meerkats > 0)){
    meerkats[random_A].sick();
    if(heal(meerkats[random_A]) == false)
      remove_meerkat(random_A);
    else
     ;
  }else if((random_A <= (num_meerkats + num_otters)) && (random_A >= num_meerkats) && (num_otters > 0)){
    otters[random_A - num_meerkats].sick();
    if(heal(otters[random_A - num_meerkats]) == false)
      remove_otter(random_A - num_meerkats);
    else 
      ;
  }else if(((random_A) <= (num_meerkats + num_otters + num_monkeys)) && (random_A >= (num_meerkats + num_otters)) && (num_monkeys > 0)){
    monkeys[random_A -(num_otters - num_meerkats)].sick(); 
    if(heal(monkeys[random_A - (num_otters - num_meerkats)]) == false)
      remove_monkey(random_A - (num_otters - num_meerkats));
    else
      ;
  }else if(animals <= 0)
    cout << "You have no animals right now" << endl;
}

bool zoo::heal(animal& sick_animal){
  cout << "Your animal has become sick!" << endl;
  if(money > (sick_animal.get_cost() / 2)){
    cout << "your animal is healed!" << endl;
    money - (sick_animal.get_cost() / 2);
    sick_animal.not_sick();
    return true;
  }else{
    cout << "your animal will die..." << endl;
    return false;
  }
  
}

void zoo::remove_meerkat(int array_num){
  meerkats[array_num] = meerkats[num_meerkats];
  num_meerkats - 1;
}

void zoo::remove_otter(int array_num){
  meerkats[array_num] = meerkats[num_meerkats];
  num_meerkats - 1;
}

void zoo::remove_monkey(int array_num){
  meerkats[array_num] = meerkats[num_meerkats];
  num_meerkats - 1; 
}

void zoo::birth(){

}

void zoo::boom(){

}

zoo::~zoo(){
  delete [] monkeys;
  delete [] meerkats;
  delete [] otters;
}
