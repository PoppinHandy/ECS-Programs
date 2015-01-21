//
// linked1.cpp
//
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

int main()
{
  LinkedList<int> ilist;

  ilist.add(42);
  ilist.add(355);
  ilist.add(113);

  ilist.print();
}
