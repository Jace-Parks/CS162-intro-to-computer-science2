#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <vector>

using namespace std;

class event{
  private:
    string name;
  public:
    virtual void detect();
    virtual int action();
};
#endif
