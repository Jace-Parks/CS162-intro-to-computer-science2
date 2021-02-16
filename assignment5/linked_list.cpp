#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

linked_list::linked_list(){
  this -> length = 0;
  this -> first = NULL;
  this -> copy = NULL;
  this -> current = NULL;
  this -> spare = NULL;
}

unsigned int linked_list::get_length(){
  return length;
}

void linked_list::add(int val){
  linked_list_node* new_node = new linked_list_node;
  new_node -> next = NULL;
  new_node -> value = val;

  if(first != NULL){
    current = first;
    while(current -> next != NULL){
      current = (current -> next);
    }
    current -> next = new_node; 
  }else if(first == NULL){
    first = new_node;
  }
  length++;
}

void linked_list::print(){
  if(first != NULL){
    if(current != first)
      current = first; 
    while(current -> next != NULL){
      cout << current -> value << ", ";
      current = (current -> next);
    }
    if(current -> next == NULL)
      cout << current -> value;
    cout << endl;
  }  
}

void linked_list::clear(){
  if(first != NULL){
    current = first;
    while(current != NULL){
      spare = (current -> next);    
      delete current;
      current = spare;
      length--;
    }
    first = NULL;
  }
}

int linked_list::get_int(int index){
  int i = 0;
  if((index == 0) && (first != NULL))
    return (first -> value);
  else if(first != NULL){
    current = first;
    while(i < index){
      current = (current -> next);
      i++;
    }
    return(current -> value);
  }else
    return 0;
    
}

unsigned int linked_list::push_front(int new_value){
  linked_list_node* new_node = new linked_list_node;
  new_node -> next = first;
  new_node -> value = new_value;

  first = new_node;

  length++;
  return length;
}  

unsigned int linked_list::push_back(int val){
  linked_list_node* new_node = new linked_list_node;
  new_node -> next = NULL;
  new_node -> value = val;

  if(first != NULL){
    current = first;
    while(current -> next != NULL){
      current = (current -> next);
    }
    current -> next = new_node;
  }else if(first == NULL){
    first = new_node;
  }

  length++; 
  return length;
}

unsigned int linked_list::insert(int new_value, unsigned int index){
  int i = 0;
  if((first != NULL) && (index <= length)){
    current = first;
    while(i < index){
      current = (current -> next);
      i++;
    }
    current -> value = new_value;
  } 
return length;
}

void linked_list::sort_descending(){
  mergesort(&first);
  reverse();
}

void linked_list::sort_ascending(){
  mergesort(&first);
}

void linked_list::mergesort(linked_list_node** headref){
  linked_list_node* head = *headref;
  linked_list_node* a;
  linked_list_node* b;

  if((head == NULL) || (head->next == NULL)){
    return;
  }
  
  split(head,&a,&b);
  mergesort(&a);
  mergesort(&b);

  *headref = merge(a,b); 
  
}

linked_list_node* linked_list::merge(linked_list_node* a, linked_list_node* b){
  linked_list_node* result = NULL;
    
  if(a == NULL)
    return (b);
  else if (b == NULL)
    return (a);

  if(a->value <= b->value){
    result = a;
    result->next = merge(a->next,b);
  }else{
    result = b;
    result->next = merge(a,b->next);
  }
  return (result);
}  

void linked_list::split(linked_list_node* source,linked_list_node** frontref,linked_list_node** backref){
  linked_list_node* fast;
  linked_list_node* slow;
  slow = source; 
  fast = source -> next;

  while(fast != NULL){
    fast = fast -> next;
    if(fast != NULL){
      slow = slow -> next;
      fast = fast -> next;
    }
  }
  *frontref = source;
  *backref = slow -> next;
  slow -> next = NULL;
}

void linked_list::reverse(){
  current = first;
  spare = NULL;
  copy = NULL;

  while(current != NULL){
    copy = current -> next;
    current -> next = spare;
    spare = current;
    current = copy;
  }
  first = spare;
}

void linked_list::print_prime(){
  int prime = 0;
  int count = 0;
  current = first;
  while(current != NULL){
    count = 0;
    if(current -> value == 0)
      prime++;
    else{
      for(int i = 2;i < current->value;i++){
        if((current -> value % i) == 0)
          count++;
      }
      if(count > 1)
      ;
      else
        prime++;
      current = current -> next;
    }
  }
  cout << "The are " << prime << " prime numbers" << endl;
}

linked_list::~linked_list(){
  if(first != NULL)
    delete first; 
  if(current != NULL)
    delete current;
  if(spare != NULL)
    delete spare;
  if(copy != NULL)
    delete copy;
}
