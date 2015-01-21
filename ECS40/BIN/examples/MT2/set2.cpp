//
// set2.cpp
//
// inserting duplicate elements into a set

#include<iostream>
#include<set>
using namespace std;

int main()
{
  char msg[] = "the quick brown fox jumps over the lazy dog";
  cout << endl << msg << endl << endl;

  // store characters of msg[] into a set<char>
  set<char> s;
  for ( int i = 0; i < sizeof(msg)/sizeof(char); i++ )
    s.insert(msg[i]);

  for ( set<char>::iterator i = s.begin(); i != s.end(); i++ )
    cout << *i;
  cout << endl << endl;
}
