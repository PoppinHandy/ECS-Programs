//
// heap2.cpp
//
// heap using a priority_queue

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
  priority_queue<int> q;
  q.push(65);
  q.push(25);
  q.push(47);
  q.push(11);
  q.push(82);
  q.push(43);
  q.push(77);

  cout << "q.top(): " << q.top() << endl;

  cout << "pop all elements:" << endl;
  while ( !q.empty() )
  {
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;
}
