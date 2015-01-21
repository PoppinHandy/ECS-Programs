//
// testarg2.cpp
//
// read an int from argv[1]

#include<iostream>
#include<sstream>
#include<cassert>
using namespace std;

int main(int argc, char **argv)
{
  // check that there are two arguments
  // argv[0] = program name
  // argv[1] = first command line argument
  assert(argc==2);

  // read an int from argv[1]
  istringstream is(argv[1]);

  int x;

  // check that all data was used in the conversion to int
  if ( is >> x  && is.eof() )
  {
    cout << " conversion successful, x=" << x << endl;
  }
  else
  {
    cout << " could not convert argv[1]" << endl;
  }
}
