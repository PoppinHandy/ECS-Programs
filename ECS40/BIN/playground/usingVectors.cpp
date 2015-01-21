#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <int> v;
	vector <int>::iterator iter;
	for (int i = 1; i < 6; i++){
		v.push_back(i);
	}//end for
	
	v.insert(v.begin() + 3, 6);
	for(iter = v.begin(); iter != v.end(); ++iter){
		cout << *iter;
	}//end iteration 	
	cout << endl;
}//end main
