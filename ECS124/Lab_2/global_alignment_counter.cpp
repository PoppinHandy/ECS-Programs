#include <iostream>
using namespace std;

double factorial (double c)
{
  if (c == 0)
    {
      return 0;
    }
  else if (c == 1)
    {
      return 1;
    }
  else
    {
      return c * factorial (c - 1);
    }

}

int main()
{
  int total = 0;
  int n = 11;
  int i = 11;
  for (int r = 0; r <= i; r++)
    {
      if (r == 0 || n - r == 0)
	{
	  total += 1;
	  //cout << "Adding 1, total is: " << total << endl;
	}
      else
	{
	  //cout << "Total before: " << total << endl;
	  //cout << "r is: " << r << endl;
	  //int testnum = (factorial(n + r))/(factorial(r)*factorial(r)*factorial(n - r));
	  total += (factorial(n + r))/(factorial(r)*factorial(r)*factorial(n - r));
	  //cout << "testnum: " << testnum << endl;
	  //cout << "Total after: " << total << endl;
	}
  }//end for
  cout << "Total is: " << total << endl;
}//end main
