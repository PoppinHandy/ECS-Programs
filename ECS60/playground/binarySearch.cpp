#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int binarySearch (vector<int> &a, int x){

	int low = 0;
	int high = a.size() - 1;
	while (low <= high ){
		int mid = (low + high)/2;
		if(a[mid] > x){
			high = mid - 1;
			cout << "high is " << high << endl;
		}else if (a[mid] < x){
			low = mid + 1;
			cout << "low is " << low << endl;
		}else{
			return mid;
		}
	}//end while
	return -1;
}//end binarySearch

int main(){
	int intArray[] = {1, 2, 3 ,4, 5, 6};
	vector <int> a(intArray, intArray + sizeof(intArray)/ sizeof(int));
	int num = binarySearch (a, 2);
	cout << num << endl;	
	return 0;
}
