//
// multimap1.cpp
//

#include<iostream>
#include<map>
using namespace std;

int main()
{
  multimap<string,int> ratings;

  ratings.insert(pair<string,int>("banana",8));
  ratings.insert(pair<string,int>("chocolate",9));
  ratings.insert(pair<string,int>("vanilla",5));
  ratings.insert(pair<string,int>("chocolate",3));
  ratings.insert(pair<string,int>("banana",7));
  ratings.insert(pair<string,int>("vanilla",7));
  ratings.insert(pair<string,int>("banana",8));

  for ( multimap<string,int>::iterator i = ratings.begin(); 
        i != ratings.end(); i++ )
    cout << i->first << " " << i->second << endl;
}
