//
// useLinkedList.cpp
//

#include "LinkedList.h"
#include<string>
using namespace std;

int main()
{
  LinkedList<int> ilist;
  ilist.add(1);
  ilist.add(2);
  ilist.add(3);

  ilist.print();

  LinkedList<string> slist;
  slist.add("you");
  slist.add("with");
  slist.add("be");
  slist.add("force");
  slist.add("the");
  slist.add("may");

  slist.print();
}
