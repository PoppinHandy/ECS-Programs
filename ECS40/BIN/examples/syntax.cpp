//
// syntax.cpp
//
// read a line consisting of three ints
// test correct syntax of the line

#include<iostream>
#include<sstream>
using namespace std;

int main()
{
  int x,y,z;
  string str;
  getline(cin,str);
  istringstream is(str);
  
  is >> x >> y >> z;
  if ( !is )
  {
    cout << "syntax error" << endl;
  }
  else
  {
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
  }
}
