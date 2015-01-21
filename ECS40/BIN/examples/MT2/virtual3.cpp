//
// virtual3.cpp
//
// use a virtual member function
// passing a derived object to a function by reference
#include<iostream>
using namespace std;

class A
{
  public:
    A(int i) : val(i) {}
    int val;
    virtual void print(void)
    {
      cout << "Value printed using A::print: " << val << endl;
    }
};

class B : public A
{
  public:
    B(int i) : A(i) {}
    virtual void print(void)
    {
      cout << "Value printed using B::print: " << val << endl;
    }
};

void f(A& a)
{
  a.print();
}

int main()
{
  A a(1);
  f(a);
  B b(2);
  f(b); // ok, b is a kind of A, uses B::print()
}
