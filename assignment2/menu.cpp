#include <iostream>
#include <fstream>
#include <string>
#include "pizza.h" 
#include "menu.h"
#include "pizzalogin.h"

using namespace std;
    
    menu::menu(){
      this -> num_pizzas = get_line();
      pizzas = new pizza[num_pizzas];
    }  
    
    menu::menu(int num){
      this -> num_pizzas = num;
      pizzas = new pizza[num_pizzas];
    }

   void menu::display_menu(){
     pizza p1;
 
     for(int i = 0;i < p1.get_num_pizzas();i++){
       p1.set_from_file(i);
       p1.display();
     }     
   } 
 
   menu menu::search_cost(int acost){
     pizza p1;
     menu m1;
     int choi = 0;

     cout << "Here are the pizzas you can afford" << endl;
     for(int i = 0;i < (num_pizzas - 1);i++){
       p1.set_from_file(i);
       p1.acost(acost,i);
     }
     cout << "Would you like to buy one or more of these pizzas?" << endl;
     cout << "Press 1 to buy press 2 to go to menu: ";
     cin >> choi;
     if(choi == 1){
       load_file();
     }
     return m1;
   }

   void menu::get_order_user(string& size,int& quan,int& num){
     int quanitity = 0;
     cout << "What size is the pizza?: "; 
     cin >> size;
     cout << "How many do you want?: ";
     cin >> quan;
     cout << "What pizza from the menu want: ";
     cin >> num;
   } 

   void menu::get_info(string& c_name,int& CC,int& phone_num){
     int phone = 0;
     cout << "Please enter your fullname using underscore: ";
     cin >> c_name;
     cout << "Please enter your credit card: ";
     cin >> CC;
     cout << "What is your phone number: " << endl;
     cin >> phone_num;
   }

   void menu::load_file(){
     int order_num = get_order();
     string* orders; 
     orders = new string[order_num];
     ifstream file;
     file.open("orders.txt");
     if(file.is_open()){
       for(int i = 0;i < order_num;i++){
         getline(file,orders[i]);
       }
     }
     file.close();
     upload_order(orders,order_num);
   }

   void menu::upload_order(string* array,int num){
     string c_name;
     string p_name;
     int CC = 0;
     int phone = 0;
     int number = 0;
     int quan = 0;
     int choi = 0;
     string size;
     pizza p1; 
     ofstream file;
     file.open("orders.txt");
     if(file.is_open()){
       for(int i = 0;i < num;i++){
         file << array[i] << endl;
       }
       get_info(c_name,CC,phone);
       
         file << (num++) << " " << c_name << " " << CC << " " << phone << " ";  
      for(;;){
         get_order_user(size,quan,number);
         p1.set_from_file(number);
         p_name = p1.get_name(); 
         file << p_name << " " << size << " " << quan << " ";
         cout << "press 1 to add, press 2 to go to menu: ";
         cin >> choi;
         if(choi == 1)
            ;
         else if(choi == 2)
           break; 
       }
     file.close();
     }
   }

   void menu::load_file_add(){
     pizza p1;

     for(int i = 0;i < num_pizzas;i++){
       p1.set_from_file(i);
       pizzas[i] = p1;
     }
     p1.add_menu(pizzas,num_pizzas);
   }

   void menu::place_order(){
     load_file(); 
   }

   void menu::load_file_remove(){
     pizza p1; 
     
     for(int i = 0;i < num_pizzas;i++){
       p1.set_from_file(i);
       pizzas[i] = p1;
     }
     p1.remove_menu(pizzas,num_pizzas);
   } 

   void menu::search_ingredients(){
     int choi = 0;
     int num = 0;
     cout << "Would you like to include or exclude ingredients? Press 1 for include, press 2 to exclude: ";
     cin >> choi;
     if(choi == 1)
       include_ingredients();
     else if(choi == 2)
       exclude_ingredients();
     else
     ;
   } 

   void menu::include_ingredients(){
     int num = 0;
     cout << "how many ingredient: ";
     cin >> num;
     string* array;
     array = new string[num];

     for(int i = 0;i < num;i++){
       cout << "For ingredient " << i << " what would you like?: ";
       cin >> array[i];
     }
  
     compare_ingredients(array,num);   
 
     delete [] array;
   }

   void menu::compare_ingredients(string* array,int num){
       pizza p1;
       int k = 0;
       for(int i = 0;i < num_pizzas;i++){
         p1.set_from_file(i);
         k = 0;
         for(int j = 0;j < num;j++){
           if((p1.ingredients_include(array[j])) == true)
             k++;
           else
            ;
           }
       if(k == num)
         p1.display();
       else
         ;
      }
     }

   void menu::exclude_ingredients(){
     int num = 0;
     cout << "How many ingredients: ";
     cin >> num;
     string* array; 
     array = new string[num];

     for(int i = 0;i < num;i++){
       cout << "For ingredient " << i << " what would you like?: ";
       cin >> array[i];
     }
     exclude(array,num);

     delete [] array;
   }

   void menu::exclude(string* array,int num){
     pizza p1;
     for(int i = 0;i < num_pizzas;i++){
       p1.set_from_file(i);
         if((p1.ingredients_exclude(array,num)) == true)
           p1.display();
     }
   }

   menu::~menu(){
      delete [] pizzas; 
    }
 
     
    

