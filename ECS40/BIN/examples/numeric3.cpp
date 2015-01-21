//
// numeric3.cpp
//
#include <iostream>
using namespace std;

int main() 
{
  double a = 1.23456789;
  double b = 2014.0;
  double c = 1.0e-18;

  cout << "default:" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  cout << "equivalent of '%12.5f':" << endl;

  // choose fixed point representation
  cout.setf(ios_base::fixed,ios_base::floatfield);

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
