#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include "pizzalogin.h"
#include "assemble.h"

using namespace std;

void welcome(int argc,char** argv){
  cout << "      Welcome!" << endl;
  cout << "---------------------" << endl;
  cout << "| Pizza bytes menu  |" << endl;
  cout << "---------------------" << endl;
  cout << endl;
}

bool prompt(int argc,char** argv){
  char in;
  cout << "Are you a customer or employee?" << endl;
  cout << "Press 'Q' to quit  press 'C' for customer or 'E' for employee: ";
  cin >> in; 
  
  if(in == 'E'){
    cout << "You have chosen employee" << endl;
    return true;
  }else if(in == 'C'){
    cout << "You have chosen customer" << endl;
    return false;
  }else if(in == 'Q'){
    cout << "Quitting" << endl;
    exit(0);
  }else
    error(argc,argv);
}

void error(int argc,char** argv){
  char in;

  cout << "You have encountered an error" << endl;
  cout << "Press 'Q' to quit" << endl;
  cout << "Press 'W' to restart: ";
  cin >> in;

  if(in == 'Q')
    exit(0);
  else if(in == 'W')
    main(argc,argv);
  else
    exit(0);
}

employee* login(int argc,char** argv,bool em,int& num){

  if(em == true){
    num = get_lines();
    employee* em_array;
    em_array = new employee[num];
    
    get_employee(argc,argv,em_array,num);
    cout << "What is you i.d?: ";
    compare(argc,argv,em_array,num);
    return em_array;
  }else if(em == false)
    return NULL;
  else
    error(argc,argv);
}

void get_employee(int argc,char** argv,employee* em_array,int& num){
  string name = "employee.txt";
  string nada;
  ifstream file;  

  file.open(name.c_str(),ifstream::in);

  if(file.is_open()){
    for(int i = 0;i < num;i++){
      file >> em_array[i].id;
      file >> em_array[i].password;
      file >> em_array[i].first_name;
      file >> em_array[i].last_name;
    }
  }else{
    error(argc,argv);
  }
}

void compare(int arg,char** argv,employee* em_array,int& num){
  int id = 0;
  int count = 0;
  string password;

  cin >> id;
  cout << "What is your password?: ";
  cin >> password;
 
  for(int i = 0;i < num;i++){
    if((id == em_array[i].id) && (password == em_array[i].password)){
      count++;
      num = i;
      break;
      
    }
  }
  if(count < 1){
    cout << "You have entered an incorrect password or id!" << endl;
    cout << "What is your i.d?: ";
    compare(arg,argv,em_array,num);
  }else if(count == 1)
  ;
}
 

void login_welcome(bool var,employee* array,int num){
  if(var == true)
    cout << "Welcome " << array[num].first_name << " " << array[num].last_name << endl;
   if (var == false) 
    cout << "Welcome customer!" << endl;
}

int get_lines(){
  ifstream file;
  string nada;  
  int count = 0;

  file.open(("employee.txt"));
  
  if(file.is_open()){ 
    while(!file.eof()){
      getline(file,nada);
      count++;
    }
  }
  file.close();
  return count;
}

int get_line(){
  ifstream file;
  string nada;
  int num = 0;
  
  file.open(("menu.txt"));

  if(file.is_open()){
    while(!file.eof()){
      getline(file,nada);
      num++;  
    }
  }
  file.close();
  return num;
}

int get_order(){
  ifstream file;
  string nada;
  int num = 0;

  file.open(("orders.txt"));

  if(file.is_open()){
    while(!file.eof()){
      getline(file,nada);
      num++;
    }
    file.close();
    return num;
  }
}

