#ifndef PIZZALOGIN_H
#define PIZZALOGIN_H

#include <iostream>
#include <string>


using namespace std;

struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours {
  string day;
  string open_hour;
  string close_hour;
};

struct order{
  int num;
  string name;
  string CC;
  string phone_num;
  string ordered;
};

void welcome(int argc,char** argv);
bool prompt(int,char**);
void error(int,char**);
employee* login(int,char**,bool,int&);
void get_employee(int,char**,employee*,int&);
void compare(int,char**,employee*,int&);
void login_welcome(bool,employee*,int);
int get_lines();
int get_line();
int get_order();
#endif
