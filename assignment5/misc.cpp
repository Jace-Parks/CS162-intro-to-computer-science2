#include <iostream>
#include <string>
#include <cstdlib>
#include "linked_list.h"

using namespace std;

bool check_int(string check);

void go();

int main(){

  while(true){
    go();
  }

return 0;
}

void go(){

  int error = 0;
  int val = 0;
  string input;
  char choi;


  linked_list list;

  while(true){
    while(true){
      cout << "enter a number: ";
      cin >> input;
        if(check_int(input) == true){
          val = atoi(input.c_str());
          break;
        }
      }
      list.add(val);
      while(true){
        cout << "would you like to enter another number? (y or n): ";
        cin >> choi;
        if((choi == 'y') || (choi == 'n') || (choi == 'Y') || (choi == 'N'))
          break;
      }
      if((choi == 'n') || (choi == 'N')) 
        break;
    }
 
    while(true){
      cout << "Press 1 to sort descending or press 2 for ascending: ";
      cin >> input;
      if(check_int(input) == true){
        val = atoi(input.c_str());
        if((val == 1) || (val == 2))
          break;
      }
    }
    cout << "Stuck" << endl;
    if(val == 1){
      list.sort_descending();
      cout << "hell" << endl;
      list.print(); 
    }else if(val == 2){
      list.sort_ascending();
      cout << "here" << endl;
      list.print();
    }
    cout << "here" << endl;
    list.print_prime();
    cout << "here" << endl;
    list.clear();
 
    while(true){
      cout << "would you like to play again?" << endl;
      cout << "press 1 to play press 2 to quit: ";
      cin >> input;
      if(check_int(input) == true){
        val = atoi(input.c_str());
        if((val == 1) || (val == 2))
          break;
      }
    }
    if(val == 1){ 
      list.clear();
    }else if(val == 2)
      exit(0);
}

bool check_int(string check){
  int checked = 0;
  for(int i = 0;i < check.length();i++){
    if(isalpha(check[i]))
      return false;
  }
  return true;
}

