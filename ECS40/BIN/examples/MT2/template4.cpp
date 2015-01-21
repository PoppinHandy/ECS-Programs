//
// template4.cpp
//
#include<iostream>
using namespace std;

class Value
{ 
  public:
    bool operator>(const Value& x) const
    {
      return i > x.i;
    }
    void print(void) { std::cout << i << std::endl; }
    void set(int x) { i = x; }
  private:
    int i;
};

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
  Value v1, v2, v3;
  v1.set(1);
  v2.set(2);
  v3.set(3);

  Value v = max(v1,v2,v3);
  v.print();
}
