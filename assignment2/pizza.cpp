#include <iostream>
#include <string>
#include "pizza.h"
#include "pizzalogin.h"
#include <fstream>

using namespace std;

pizza& pizza::operator=(const pizza& oldpizza){
  if(this != &oldpizza){
    delete [] ingredients;
    this -> name = oldpizza.name;
    this -> sml_cost = oldpizza.sml_cost;
    this -> med_cost = oldpizza.med_cost;
    this -> lrg_cost = oldpizza.lrg_cost;
    this -> num_ingr = oldpizza.num_ingr;
    
    ingredients = new string[max_ingredients];
    for(int i = 0;i < num_ingr;i++){
      ingredients[i] = oldpizza.ingredients[i];
    }
  }
}


pizza::pizza(const pizza& old_piz){
  this -> name = old_piz.name;
  this -> sml_cost = old_piz.sml_cost;
  this -> med_cost = old_piz.med_cost;
  this -> lrg_cost = old_piz.lrg_cost;
  this -> num_ingr = old_piz.num_ingr;
  ingredients = new string[num_ingr];
    for(int i = 0;i < old_piz.num_ingr;i++)
      ingredients[i] = old_piz.ingredients[i];
}

//defult
pizza::pizza() : max_ingredients(MAX_INGREDIENTS){
  this -> name = "NO-NAME";
  this -> num_pizzas = (get_line() - 1);
  this -> sml_cost = 0;
  this -> med_cost = 0;
  this -> lrg_cost = 0;
  this -> num_ingr = 0;
  ingredients = new string[max_ingredients];
}

void pizza::set_name(string& new_name){
  this -> name = new_name;
}

void pizza::set_num_ingredients(int& numb){
  this -> num_ingr = numb;
}

void pizza::set_num_pizzas(int& num_piz){
  this -> num_pizzas = num_piz;
}

string pizza::get_name() const{
  return name;
} 

int pizza::get_num_ingredients() const{
  return num_ingr;
}

int pizza::get_num_pizzas() const{
  return num_pizzas;
}

void pizza::set_from_file(int num){
  ifstream file;
  string nada;
  string menuname;
  string name = "menu.txt";
  file.open(name.c_str(),ifstream::in);
  if(file.is_open()){
    for(int i = 0;i < num;i++)
      getline(file,nada);
    file >> this -> name;
    file >> sml_cost;
    file >> med_cost;
    file >> lrg_cost;
    file >> num_ingr;
    for(int i = 0;i < num_ingr;i++){
      file >> ingredients[i];
    }
  }
  file.close();
}

void pizza::display(){
  cout << name << " " << sml_cost << " " ;
  cout <<  med_cost << " " << lrg_cost << " " << endl;
  for(int i = 0;i < num_ingr;i++){
    cout << ingredients[i] << " ";
  }
  cout << endl;

}

void pizza::add_menu(pizza* pizzas,int num){
  ofstream file;
  string names = "menu.txt";
  string nada;

  cout << "what would you like to name your pizza?: ";
  cin >> name;
  cout << "How many ingredients would you like to add?: ";
  cin >> num_ingr;
  ingredients = new string[num_ingr];
  for(int i = 0;i < num_ingr;i++){
    cout << "For ingredient " << i << " what would you like?: ";
    cin >> ingredients[i];
  }
  cin >> nada;
  cout << "what is the small cost of the pizza?: ";
  cin >> sml_cost;
  cout << "What is the medium price of the pizza?: ";
  cin >> med_cost;
  cout << "What is the Large cost of the pizza?: ";
  cin >> lrg_cost;
  
  file.open(("menu.txt"));
  if(file.is_open()){
    file << name << " " << sml_cost << " " << med_cost << " " << lrg_cost << " " << num_ingr << " ";
    for(int i = 0;i < num_ingr;i++){
      file << ingredients[i] << " ";
    }
    file << endl;
    for(int i = 0;i < num;i++){
      file << pizzas[i].name << " " << pizzas[i].sml_cost << " " << pizzas[i].med_cost << " ";
      file << pizzas[i].lrg_cost << " " << pizzas[i].num_ingr << " ";
      for(int j = 0;j < pizzas[i].num_ingr;j++){
        file << pizzas[i].ingredients[j] << " ";
      }
     file << endl;
    }
  }
}

void pizza::remove_menu(pizza* pizzas,int num){
  int choi = 0;
  ofstream file;
  
  cout << "Wich pizza would you like to remove?" << endl;
  cout << "Enter the number from menu: ";  
  cin >> choi;  
 
  file.open(("menu.txt"));
  if(file.is_open()){
    for(int i = 0;i < num;i++){
      if(i == choi)
              ; //do nothing
      else{
        file << pizzas[i].name << " " << pizzas[i].sml_cost << " " << pizzas[i].med_cost << " " << pizzas[i].lrg_cost;
        file << " " << pizzas[i].num_ingr << " ";
        for(int j = 0;j < pizzas[i].num_ingr;j++){
          file << pizzas[i].ingredients[j] << " ";
        }
        file << endl; 
      }
    }
  }
  file.close();
}
 
void pizza::acost(int acost,int count){
    if((this -> lrg_cost <= acost) && (this -> lrg_cost != 0)){
      cout <<  "(" << count << ") " << this -> name << " small cost: " << this -> sml_cost << " medium cost: " << this ->  med_cost;
      cout << " large cost: " << this -> lrg_cost << " ingredients: ";
      for(int i = 0;i < this -> num_ingr;i++){
        cout << ingredients[i] << " ";
      }
      cout << endl;
    }else if((this -> med_cost <= acost) && (this -> med_cost != 0)){
      this -> lrg_cost = 0;
      cout << "(" << count << ") " << this -> name << " small cost: " << this -> sml_cost << " medium cost: " << this -> med_cost << " ingredients ";
      for(int i = 0;i < this -> num_ingr;i++){
        cout << ingredients[i] << " ";
      }
      cout << endl;
    }else if((this -> sml_cost <= acost) && (this -> sml_cost != 0)){
      this -> med_cost = 0;
      this -> lrg_cost = 0;
      cout << "(" << count << ") " << this -> name << " small cost: " << this -> sml_cost << " ingredients ";
      for(int i = 0;i < this -> num_ingr;i++)
        cout << ingredients[i] <<  " ";
      cout << endl;
    }else if (this -> sml_cost > acost || (this -> sml_cost == 0)){
      this -> sml_cost = 0;
      this -> med_cost = 0;
      this -> lrg_cost = 0;
    } 
} 

bool pizza::ingredients_include(string p_ingredient){
  for(int i = 0;i < num_ingr;i++){
    if((p_ingredient) == (ingredients[i]))
      return true;
  }
  return false;
}

bool pizza::ingredients_exclude(string* p_ingredients,int num){
  int k = 0;
  cout << p_ingredients[0] << endl;
  for(int i = 0;i < num_ingr;i++){
    for(int j = 0;j < num;j++){
      if(ingredients[i] == p_ingredients[j]){
        k++;
      }
    } 
  }
  if(k == 0)
    return true;
  else if(k >= 1)
    return false;
}

pizza::~pizza(){
  delete [] ingredients;
}
