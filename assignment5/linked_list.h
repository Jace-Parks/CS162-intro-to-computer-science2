#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <string>
#include "linked_list_node.h"

using namespace std;

class linked_list {
private:
   unsigned int length; // the number of nodes contained in the list
   linked_list_node *first; // a pointer to the first node in the list
   linked_list_node *copy;
   linked_list_node *current;
   linked_list_node *spare;
  public:
    linked_list();
    unsigned int get_length();  // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
    void add(int); //adds node to the end and inserts value
    void print(); // output a list of all integers contained within the list
    void clear(); // delete the entire list (remove all nodes and reset length to 0)
    int get_int(int index);
    unsigned int push_front(int); //insert a new value at the front of list return new length
    unsigned int push_back(int);  //insert a new value at the end of the list and return length
    unsigned int insert(int val, unsigned int index);
    void sort_ascending(); // sort the nodes in descending order
    void sort_descending();
    void mergesort(linked_list_node**);
    linked_list_node* merge(linked_list_node*,linked_list_node*);
    void split(linked_list_node*,linked_list_node**,linked_list_node**);
    void reverse();
    void print_prime();
    ~linked_list();
};
#endif
