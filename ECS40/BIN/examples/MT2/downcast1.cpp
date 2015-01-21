//
// downcast1.cpp
//
// Use of downcasting with dynamic_cast

#include<iostream>
using namespace std;

class Shape
{
  public:
    virtual void draw(void) = 0;
};

class Square : public Shape
{
  public:
    virtual void draw(void) { cout << "Square::draw" << endl; }
};

class Circle: public Shape
{
  public:
    virtual void draw(void) { cout << "Circle::draw" << endl; }
};

void drawSquares(Shape **p, int size)
{
  Square *sp;
  for ( int i = 0; i < size; i++ )
  {
    cout << "drawSquares: element " << i << ": ";
    sp = dynamic_cast<Square*>(p[i]);
    if ( sp )
      sp->draw();
    else
      cout << " is not a Square" << endl;
  }
}

int main()
{
  Shape *shapes[4]; // array of pointers to shapes
  shapes[0] = new Square;
  shapes[1] = new Circle;
  shapes[2] = new Circle;
  shapes[3] = new Square;

  drawSquares(shapes,sizeof(shapes)/sizeof(Shape*));
}
