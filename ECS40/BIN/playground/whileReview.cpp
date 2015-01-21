#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int x;
	istringstream is(str);
	while (!is.eof()){
		if (is >> x){
			cout << x << " ";
		}//end if	
	}//end while
	cout << endl;
}//end main
