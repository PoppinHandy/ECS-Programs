//
// sort2.cpp
//
// sorting using predefined binary predicates

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
  int array[] = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
  // note initialization of vector using assign member function
  vector<int> v;
  v.assign(array,array+sizeof(array)/sizeof(int));

  for ( int i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;

  sort(v.begin(), v.end(), less<int>());

  cout << "after sort using less<int>:" << endl;
  for ( int i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;

  sort(v.begin(), v.end(), greater<int>());
  cout << "after sort using greater<int>:" << endl;
  for ( int i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;
}
