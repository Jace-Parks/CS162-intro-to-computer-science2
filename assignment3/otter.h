#ifndef OTTER_H
#define OTTER_H
#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class otter: public animal{
  private:
  protected:
  public:
    otter();
    otter& operator=(const otter& old_otter);
};

#endif
