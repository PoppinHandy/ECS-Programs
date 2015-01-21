//
// sstream1.cpp
//
// using string streams

#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

int main()
{
  ostringstream os;

  double a = 355.0;
  double b = 113.0;

  os << setprecision(7) << setw(12) << a;
  os << setprecision(7) << setw(12) << b;
  os << setprecision(7) << setw(12) << a/b;
  os << endl;

  cout << os.str();

  // erase os
  os.str("");

  os << " a = " << a;
  os << " b = " << b;
  os << endl;

  cout << os.str();
}
