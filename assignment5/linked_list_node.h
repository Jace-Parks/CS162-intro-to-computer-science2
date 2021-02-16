#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
#include <iostream>

class linked_list_node{
  public:
    int value;
    linked_list_node* next; 
    linked_list_node();
    ~linked_list_node();
};

#endif
