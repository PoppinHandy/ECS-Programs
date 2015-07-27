#include <iostream>
#include <cstring>
#include <string>
using namespace std;


void hexToBinary(string &str1, string &str2)
{
  int n = 0;
  const char *master_list = "0123456789abcdef";
  char * cstr = new char [str1.length()+1];
  strcpy (cstr, str1.c_str());
  for (int i = str1.length() - 1; i >= 0; i--)
    {
      for (int j = 0; j< 17; j++)
	{
	  if (cstr[i] == master_list[j])
	    {
	      n = j;
	      //cout << cstr[i] << " is " << n << endl;
	    }
	}//end inner for
      for (int a = 0; a < 4; a++)
	{
	  str2 = (n%2 == 0 ? "0": "1") + str2;
	  n/= 2;
	}//end for
      cout << str2 << endl;
      //str2 = " " + str2;
    } //end outer for
  delete [] cstr;
}

void binaryToDecimal(char *input1)
{
}
void binaryToBase(string &str1, string &str2)
{
  const char master_list = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  
  
}

int main()
{
  string hexamel;
  string binaryTime;
  cout << "Enter a string in hex: ";
  cin >> hexamel;
  hexToBinary(hexamel, binaryTime);
  

}
