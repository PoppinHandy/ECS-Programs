//
// LinkedList.h 
//
// Linked list for objects of type T
// The default constructor, operator= and operator<< must exist for type T

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>

template <typename T> 
class Node
{
  public:
    T val;
    Node *next;
};
    
template <typename T>
class LinkedList
{
  public:
    LinkedList<T>(void) { head = 0; }
    void add(T x) 
    { 
      Node<T> *tp = new Node<T>; 
      tp->val = x; 
      tp->next = head; 
      head = tp;
    }
    bool isEmpty(void) { return head==0; }
    void print(void)
    { 
      Node<T> *p = head;
      while(p!=0) 
      {
        std::cout << p->val << std::endl;
        p = p->next;
      }
    }
  private:
    Node<T> *head;
};
#endif
