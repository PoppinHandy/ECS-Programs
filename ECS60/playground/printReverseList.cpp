#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(){
	List <int> list1;
	ListItr <int> itr = list1.zeroth();
	cout << "enter a number: " << endl;
	int num;
	int numCount = 0;
	cin >> num;	
	while(num != 0){
		list1.insert(num, itr);
		cout << "inserted: " << num;
		numCount++;
		cin >> num;
	}//end while

	//Puts iterator at the end of the list	
	while (!itr.isPastEnd()){
		itr.advance();
	}//end while loop
	for(int i = 0; i < numCount; i++){
		cout << itr.retrieve() << " ";	
		itr.remove(itr.retrieve());
	}//end for loop 
	
