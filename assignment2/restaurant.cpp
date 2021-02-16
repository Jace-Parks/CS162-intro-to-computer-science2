#include <iostream>
#include <fstream>
#include "menu.h"
#include "pizza.h"
#include "pizzalogin.h"
#include "restaurant.h"
#include "assemble.h"

using namespace std;
  
restaurant::restaurant(){
  this -> num_employs = get_lines();
  this -> employees = new employee[num_employs];
  this -> week = new hours[6];
  this -> num_order = (get_order() - 1);
  this -> orders = new order[num_order];
  this -> name = "NO NAME";
  this -> phone = "NO NUMBER";
  this -> address = "NO ADDRESS";
} 

void restaurant::load_data_employees(){
  string name = "employee.txt";
  ifstream file;

  file.open(name.c_str(),ifstream::in);

  if(file.is_open()){
    for(int i = 0;i < this -> num_employs;i++){
      file >> employees[i].id;
      file >> employees[i].password;
      file >> employees[i].first_name;
      file >> employees[i].last_name;    
    }
  }
  cout << "Employee data set" << endl;
}

void restaurant::load_data_restaurant(){
  string file_name = "restaurant_info.txt";
  ifstream file;

  file.open(file_name.c_str(),ifstream::in);

  if(file.is_open()){
    getline(file,name);
    getline(file,phone);
    getline(file,address);
    for(int i = 0;i < 6;i++){
      file >> week[i].day;
      file >> week[i].open_hour;
      file >> week[i].close_hour; 
    }
  }
  cout << "restaurant data set" << endl;  
}

void restaurant::load_menu(int argc,char** argv,bool var){
  int choice = 0;
 
  if(var == true){
    cout << "What would you like to do?" << endl;
    cout << "1. Change hours" << endl;
    cout << "2. View orders" << endl;
    cout << "3. Remove order" << endl;
    cout << "4. Add an item to menu" << endl;
    cout << "5. Remove item from menu" << endl;
    cout << "6. View Menu" << endl;
    cout << "7. View Hours" << endl;
    cout << "8. View Address" << endl;
    cout << "9. View Phone" << endl;
    cout << "10. Log out" << endl;
    cout << ": ";
    cin >> choice;
    if((choice > 0) && (choice <= 10)){
      choices(argc,argv,var,choice);
    }else
      error(argc,argv); 
 
  }else if(var == false){
    cout << "1. View menu" << endl;
    cout << "2. Search by cost" << endl;
    cout << "3. Search by ingredients" << endl;
    cout << "4. Place order" << endl;
    cout << "5. View hours" << endl;
    cout << "6. View address" << endl;
    cout << "7. View Phone" << endl;
    cout << "8. Log out" << endl;
    cout << ": ";
    cin >> choice;
    if((choice > 0) && (choice <= 8)){
      choices(argc,argv,var,choice);
    }else
      error(argc,argv);
  }   
}

void restaurant::choices(int argc,char** argv,bool var,int choi){
  int cost = 0;
  if(var == true){
    if(choi == 1){
      change_hours();     
    }else if(choi == 2){
      load_orders();
      view_orders();
    }else if(choi == 3){
      load_orders();
      remove_order();    
    }else if(choi == 4){
      menu menu1;
      menu1.load_file_add();
    }else if(choi == 5){
      menu menu1; 
      menu1.load_file_remove();
    }else if(choi == 6){
      menu menu1;
      menu1.display_menu();
    }else if(choi == 7){
      view_hours();
    }else if(choi == 8){
      cout << "The address is: " << address << endl;
    }else if(choi == 9){
      cout << "The phone number is: " << phone << endl;
    }else if(choi == 10)
    main(argc,argv);
  }else if(var == false){
    if(choi == 1){
      menu menu1;
      menu1.display_menu();
    }else if(choi == 2){
      cout  << "What is the most you would pay?: ";
      cin >> cost;
      menu menu1;
      menu1.search_cost(cost); 
    }else if(choi == 3){
      menu menu1; 
      menu1.search_ingredients();
    }else if(choi == 4){
      menu menu1;
      menu1.place_order();
    }else if(choi == 5){
      view_hours(); 
      load_menu(argc,argv,var);
    }else if(choi == 6){
      cout << "The address is: " << address << endl;
      cout << endl;
    }else if(choi == 7){
      cout << "Phone Number: " << phone << endl;
      cout << endl;
    }else if(choi == 8){
      main(argc,argv);
    }
  }
  load_menu(argc,argv,var);
}

void restaurant::view_hours(){
  cout << "The hours for the week are: " << endl;
  for(int i = 0;i < 6;i++){
     cout << week[i].day << " opens: " << week[i].open_hour << " closes: " << week[i].close_hour << endl;
  }
}

void restaurant::change_hours(){
  int choi = 0;
  string new_open;
  string new_close;
  for(int i = 0;i < 6;i++)
    cout << "(" << i << ") " << week[i].day << endl; 
  cout << "What day would You like to change?: ";
  cin >> choi;
  cout << "What is the open hour?: ";
  cin >> new_open;
  cout << "What is the close hour?: ";
  cin >> new_close;

  week[choi].open_hour = new_open;
  week[choi].close_hour = new_close;
}

void restaurant::load_orders(){
  ifstream file;
  int num = 0;
  string nada; 
  string names = "orders.txt";

  file.open(names.c_str(),ifstream::in);
  if(file.is_open()){
    for(int i = 0;i < num_order;i++){
      file >> orders[i].num; 
      file >> orders[i].name;
      file >> orders[i].CC;
      file >> orders[i].phone_num;
      getline(file,orders[i].ordered);
    }
  }
  file.close();
}

void restaurant::view_orders(){
  for(int i = 0;i < num_order;i++){
    if(orders[i].num == 0)
      ; // do nothing
    else{
      cout << "order number is: " << orders[i].num << " Name: " << orders[i].name << " CC: " << orders[i].CC;
      cout << " Phone number: " << orders[i].phone_num << endl;
      cout << "Order: " << orders[i].ordered << endl;
    }
  }
  
}

void restaurant::remove_order(){
  int choi = 0;  
  ofstream file;
 
  cout << "Which order would you like to remove?: ";
  cin >> choi;

  file.open(("orders.txt"));
  if(file.is_open()){
    for(int i = 0;i < num_order;i++){
      if(choi == i){
        orders[i].num = 0;
      }else{
        file << orders[i].num << " " << orders[i].name << " " << orders[i].CC << " " << orders[i].phone_num << " ";
        file << orders[i].ordered << endl;
      } 
   }
  }
  file.close(); 
}

restaurant::~restaurant(){
  delete [] employees;
  delete [] week;  
}
