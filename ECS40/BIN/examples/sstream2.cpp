//
// sstream2.cpp
//
// using string streams

#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

int main()
{
  double x,y;
  string s;
  getline(cin,s);

  istringstream is(s);

  is >> x >> y;

  cout << "x= " << x << endl;
  cout << "y= " << y << endl;
}
