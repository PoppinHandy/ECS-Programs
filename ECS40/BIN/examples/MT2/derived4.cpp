//
// derived4.cpp
//
// constructors and destructors in derived classes
// 
#include<iostream>
using namespace std;

class A
{
  public:
    // if the ctor A(int i) is not declared, a default ctor is
    // defined
    // A(int i) { val = i; }
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
  //A a(1);
  // use the default ctor
  A a;
  a.print();
  B b(2);
  b.print();
}
