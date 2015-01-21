//
// set1.cpp
//

#include<iostream>
#include<set>
using namespace std;

int main()
{
  set<int> s;

  s.insert(78);
  s.insert(12);
  s.insert(90);
  s.insert(56);
  s.insert(34);

  for ( set<int>::iterator i = s.begin(); i != s.end(); i++ )
    cout << *i << " ";
  cout << endl;
}
