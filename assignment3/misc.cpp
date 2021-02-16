#include <iostream>
#include <string>
#include "misc.h"
#include "assemble.h"

using namespace std;

void welcome(){
  cout << "--------------------" << endl;
  cout << "|  welcome to zoo  |" << endl;
  cout << "|      TYCOON!     |" << endl;
  cout << "____________________" << endl;
  cout << endl;
}

void lost(){
  cout << "READY TO PLAY AGAIN?" << endl;
  main();
}
