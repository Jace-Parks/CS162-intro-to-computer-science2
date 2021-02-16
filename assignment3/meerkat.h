#ifndef MEERKAT_H
#define MEERKAT_H
#include "animal.h"
#include <iostream>
#include <string>

using namespace std;

class meerkat: public animal{
  private:
  protected:
  public:
    meerkat();
    meerkat& operator=(const meerkat&);
    ~meerkat();
};

#endif
