/*
Name: Andy Pham
Student ID: 997942129
rpn.cpp
*/

#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

int main(){
	stack <double> calcStack;
	string str;
	getline (cin, str);
	string str2 = str;
	//char * tokens;
	//tokens = strtok(str, " ");
	istringstream is(str);	//for integers
	istringstream cs(str2);	//for characters (operators)
	double x;
	char operand;
	double result;

	while (!is.eof() && !cs.eof()){
		if(is >> x){
			if (!is){
				cout << "invalid input" << endl;
				exit (EXIT_FAILURE);
			}//end inner if
			cout << "Adding " << x << endl;
			calcStack.push(x);
		}else if( cs >> operand){
			cout << "Operand is: " << int(operand) << endl;
			if (int(operand) > 47 && int (operand) < 58){
				continue;
			}else{
				switch (operand){
					case '-':
						result = calcStack.top();
						calcStack.pop();
						result -= calcStack.top();
						calcStack.push(result);
						break;
					case '*':
						result = calcStack.top();
						calcStack.pop();
						result *= calcStack.top();
						calcStack.push(result);
						break;
					case '+':
						result = calcStack.top();
						calcStack.pop();
						result += calcStack.top();
						calcStack.push(result);
						break;
					case '/':
						result = calcStack.top();
						calcStack.pop();
						result /= calcStack.top();
						calcStack.push(result);
						break;
					default:
						cout << "invalid input" << endl;
						exit(EXIT_FAILURE);
						break;
				}//end switch
			}//end else
			cout << "detected operator" << endl;
		}//end else if
	}//end while
	
	while (!calcStack.empty()){
		cout << ' ' << calcStack.top();
		calcStack.pop();
	}
	cout << endl;
}//end main	
