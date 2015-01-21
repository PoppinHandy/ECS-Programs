//
// derived2.cpp
//
// constructors and destructors in derived classes
// 
#include<iostream>
using namespace std;

class A
{
  public:
    A(int i) { val = i; }
    void print(void) { cout << val << endl; }
  private:
    int val;
};

class B : public A
{
  public:
    B(int i) {}
};

int main()
{
  A a(1);
  a.print();
  B b(2);
  b.print();
}
