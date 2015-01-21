//
// heap.cpp
//
// from cplusplus.com

#include <iostream>  // std::cout
#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>    // std::vector
using namespace std;

void print(const vector<int>& v)
{
  for (int i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  cout << endl;
}

int main() 
{
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  cout << "initial vector: " << endl; print(v);

  make_heap(v.begin(),v.end());
  cout << endl << "after make_heap: " << endl; print(v);

  pop_heap (v.begin(),v.end()); 
  cout << endl << "after pop_heap: " << endl; print(v);

  v.pop_back();
  cout << endl << "after pop_back: " << endl; print(v);

  v.push_back(99); 
  cout << endl << "after push_back(99): " << endl; print(v);

  push_heap(v.begin(),v.end());
  cout << endl << "after push_heap: " << endl; print(v);

  sort_heap (v.begin(),v.end());
  cout << endl << "after sort_heap: " << endl; print(v);
}
