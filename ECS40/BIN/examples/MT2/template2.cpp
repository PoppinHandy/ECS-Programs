//
// template2.cpp
//
// attempt to use mixed types
#include<iostream>
using namespace std;

template< typename T >
T max( T v1, T v2, T v3 )
{
  T m = v1;
  if ( v2 > m ) m = v2;
  if ( v3 > m ) m = v3;
  return m;
}

int main()
{
  int i1 = 1, i2 = 2, i3 = 3;
  cout << max(i1,i2,i3) << endl;

  double d1 = 1.0, d2 = 2.0, d3 = 3.0;
  cout << max(d1, d2, d3) << endl;

  float f1 = 1.0f, f2 = 2.0f, f3 = 3.0f;
  cout << max(f1, f2, f3) << endl;

  // using mixed types
  cout << max(i1,f2,i3);
}
