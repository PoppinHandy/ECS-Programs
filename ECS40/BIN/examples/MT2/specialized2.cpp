//
// specialized2.cpp
//
// implement a specialized member function in a derived class
// passing a derived object to a function 
#include<iostream>
using namespace std;

class A
{
  public:
    A(int i) : val(i) {}
    int val;
    void print(void)
    {
      cout << "Value printed using A::print: " << val << endl;
    }
};

class B : public A
{
  public:
    B(int i) : A(i) {}
    void print(void)
    {
      cout << "Value printed using B::print: " << val << endl;
    }
};

void f(A a)
{
  a.print();
}

int main()
{
  A a(1);
  f(a);
  B b(2);
  f(b); // ok, B is a kind of A
}
