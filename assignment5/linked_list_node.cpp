#include <iostream>
#include <string>
#include "linked_list_node.h"

linked_list_node::linked_list_node(){
  int value = 0;
  next = NULL;
}

linked_list_node::~linked_list_node(){
  if(next != NULL)
    delete next;
}
