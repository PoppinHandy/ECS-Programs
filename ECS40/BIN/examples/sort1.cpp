//
// sort1.cpp
//

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
  int array[] = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
  vector<int> v(array,array+sizeof(array)/sizeof(int));

  for ( int i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;

  sort(v.begin(),v.end());

  for ( int i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;
}
