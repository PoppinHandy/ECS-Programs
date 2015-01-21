//
// find1.cpp
//

#include<list>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
  list<int> l;
  l.push_back(55);
  l.push_back(3);
  l.push_back(72);
  l.push_back(14);
  l.push_back(9);
  l.push_back(22);
  l.push_back(47);

  list<int>::iterator it;
  for ( it = l.begin(); it != l.end(); it++ )
    cout << *it << " ";
  cout << endl;

  if ( (it = find(l.begin(),l.end(),14)) != l.end() )
    cout << 14 << " was found" << endl;
  else
    cout << 14 << " was not found" << endl;

  if ( (it = find(l.begin(),l.end(),99)) != l.end() )
    cout << 99 << " was found" << endl;
  else
    cout << 99 << " was not found" << endl;
}
