//
// numeric2.cpp
//
#include <iostream>
using namespace std;

int main() 
{
  double a = 3.141592653;
  double b = 2014.0;
  double c = 1.0e-18;

  cout << "default:" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  cout << "using cout.precision(5) and cout.width(12)" << endl;

  // cout.precision() affects all following operations
  cout.precision(5);

  // cout.width() only affects the next operation. Must be repeated.
  cout.width(12);
  cout << a << endl;

  cout.width(12);
  cout << b << endl;

  cout.width(12);
  cout << c << endl;
}
