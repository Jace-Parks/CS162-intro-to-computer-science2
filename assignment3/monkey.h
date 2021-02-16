#ifndef MONKEY_H
#define MONKEY_H
#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class monkey: public animal{
 
  public:
    monkey();
    monkey& operator=(const monkey&); 
};


#endif 
