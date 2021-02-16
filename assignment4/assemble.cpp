#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "misc.h"
#include "grid.h"

using namespace std;

int main(int argc,char** argv){
  int height = 0;
  int length = 0;
  string heightstr;
  string lengthstr;
  string clearence;

  if(argc >= 4){
    heightstr = argv[1];
    lengthstr = argv[2];
    clearence = argv[3];
    height = check_int(heightstr);
    length = check_int(lengthstr);
    if((height > 0) && (length > 0)){
      if((clearence == "false") || (clearence == "False")){
        game(height,length);
      }else if((clearence == "true") || (clearence == "True"))
        debug(height,length);
    }else
      cout << "the heigt and or length is incorrect" << endl; 
  }else{
    cout << "you have entered an incorrect command line argument" << endl;
  }

}

