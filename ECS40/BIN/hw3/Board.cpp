/*
Name: Andy Pham
Student ID: 997942129
Board.cpp
*/

#include <iostream>
#include <vector>
#include "Board.h"
#include <stdexcept>
using namespace std;

Board::Board(void){
	//initialize the scoreboard
	for (int row = 0; row < 10; row++){
		for (int col = 0; col < 10; col++){
			score [row][col] = ' ';
		}//end inner for
	}//end outer for
	
}//end board constructor

//Use makeShip in Ship.cpp in order to initialize ships
void Board::addShip(char type, int x1, int y1, int x2, int y2){
	Ship *shipPtr;
	if(shipList.size() < 11){
		shipList.push_back(shipPtr -> makeShip(type, x1, y1, x2, y2));
	}else{
		cout << "No new ship will be added" << endl;
	}//end else
	
}//end addShip

void Board::print(void){
	cout << "   a b c d e f g h i j" << endl;
	cout << "  +-------------------+"<< endl;
	for (int row = 0; row < 10; row++){
		cout << " " << row << "|";
		for (int col = 0; col < 10; col ++){
			if (col == 9){ 
				cout << score[row][col]; 
			}else{
				cout << score[row][col] << " ";
			}//end else
		}//end inner for
		cout << "|" << endl;
	}//end outer for
	cout << "  +-------------------+" << endl;
}//end print

int Board::level (void){
	int sum = 0;
	vector <Ship *>::iterator iter;
	//Go through all the ships and add their levels together
	for (iter = shipList.begin(); iter != shipList.end(); ++iter){
		sum += (*iter)->level();
	//	cout << "adding " << (*iter)->level() << " current sum is: " << sum << endl; 
	}//end for	
	//cout << sum << " is sum" << endl;
	return sum;
}//end level

Ship* Board::shipAt(int x, int y){
	vector <Ship *>::iterator iter;
	Ship *shipPtr = NULL;
	for (iter = shipList.begin(); iter != shipList.end(); ++iter){
		if ((*iter)->includes(x,y) == true){ //includes detects whether a ship is there or not
			shipPtr = *iter;
			//cout << "This ship is " << shipPtr -> name() << endl;
			//shipPtr -> print();
			return shipPtr;
		}//end if
	}//end for
	return shipPtr;
}//end shipAt

void Board::hit(char c, int i){
	Ship *shipPtr;
	int xCoor = (int)c - 97;
	//cout << xCoor << " is the x coordinate put in" << endl;
	//if invalid combination
	if ((xCoor < 0 || xCoor > 9 ) || ( i < 0 || i > 9 )){
		throw invalid_argument("invalid input");
	}else{
		//if hit
		if (shipAt(xCoor, i) != NULL){
			shipPtr = shipAt(xCoor, i);
			shipPtr->decreaseLevel();	
			//cout << shipPtr -> name() << " is now level" << shipPtr -> level() << endl;
			score [i][xCoor] = '*'; 
			if (shipPtr -> level() == 0){
				cout << shipPtr -> name() << " sunk" << endl;
			}//end inner if
		}else{
			score [i][xCoor] = 'x';	
		}//end inner else
	}//end outer else
}//end hit
