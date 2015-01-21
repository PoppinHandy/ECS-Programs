/*
Name: Andy Pham
Student ID: 997942129
Ship.cpp
*/

#include <iostream>
#include "Ship.h"
#include <stdexcept>
#include <cmath>
using namespace std;

int Ship::getX(int i) const{
	if (i == size()-1){
		return x2;
	}else if (x1 == x2){
		return x1;
	}else if (x1 > x2){
		return x1 - i;
	}else{
		return x1 + i;
	}//end else		
}//end getX

int Ship::getY(int i) const{
	if (i == size()-1){
		return y2;
	}else if (y1 == y2){
		return y1;
	}else if (y1 > y2){
		return y1 - i;
	}else{
		return y1 + i;
	}//end else
}//end getY

void Ship::print(void) const{
	cout << name() << " from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
}//end print

bool Ship::includes (int x, int y){
	if ((x>=x1 && x<=x2) || (x>=x2 && x<=x1)){	//x is between x1 and x2
		if (( abs(y2-y1) < size())){	//in the case where x1 is equal to x2, and the y coordinates are less than the ship's size
			if ( (y >= y1 && y <= y2) || (y >= y2 && y <= y1) ){
				return true;
			}else{
				return false;
			}//end else
		}else{
			return true;
		}//end else
	}else if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)){
		if (( abs(x2-x1) < size())){
			if( (x >= x1 && x <= x2) || ( x >= x2 && x <= x1)){
				return true;
			}else {
				return false;
			}//end else
		}else{
			return false;
		}//end else
	}else{
		return false;
	}//end else 
}//end includes

int Ship::level(void) const{
	return lev;
}//end level

void Ship::decreaseLevel(void){
	if (lev > 0){	
		lev = lev - 1;
	}//end if
}//end decreaseLevel

Ship *Ship::makeShip(char ch, int x1, int y1, int x2, int y2){
	Ship *shipPtr = NULL;
	if (ch == 'A'){
		shipPtr = new AircraftCarrier(x1, y1, x2, y2);
		shipPtr -> lev = shipPtr -> size();
		return shipPtr;
	}else if (ch == 'B'){
		shipPtr = new BattleShip(x1, y1, x2, y2);
		shipPtr -> lev = shipPtr -> size();
		return shipPtr;
	}else if(ch == 'C'){
		shipPtr = new Cruiser(x1, y1, x2, y2);	
		shipPtr -> lev = shipPtr -> size();
		return shipPtr;
	}else if(ch == 'D'){
		shipPtr =  new Destroyer(x1, y1, x2, y2);
		shipPtr -> lev = shipPtr -> size();
		return shipPtr;
	}else{
		throw invalid_argument("invalid configuration");			
	}//end else
}//end makeShip

void Ship::setPos(int x1, int y1, int x2, int y2){
	bool check = checkConfig(x1, y1, x2, y2);
	if (check == true){
		this->x1 = x1;
		this->y1 = y1;	
		this->x2 = x2;
		this->y2 = y2;
	}else{
		throw invalid_argument("invalid configuration");
	}//end else
}//end setPos

bool Ship::checkConfig(int x1, int y1, int x2, int y2){
	if ((x1 == x2) && (abs(y2 - y1) < size())){	//if x1 and x2 are in the same row and the y values are less than the ship's length
		return true;	
	}else if ((y1 == y2) && (abs(x2 - x1)) < size()){
		return true;
	}else{
		return false;
	}//end else
}//end checkConfig

//end Ship class ============================================================= 

//begin Aircraft Carrier ======================================================

AircraftCarrier::AircraftCarrier(int x1, int y1, int x2, int y2){
	lev = size();
	setPos(x1, y1 ,x2, y2);
}//end constructor 

const char* AircraftCarrier::name(void) const{
	static const char name[] = "AircraftCarrier";
	return name;
}//end name

int AircraftCarrier::size(void) const{
	int size = 5;
	return size;
}//end size()

//end AircraftCarrier ==========================================================

//begin BattleShip ==============================================================

BattleShip::BattleShip(int x1, int y1, int x2, int y2){
	lev = size();
	setPos(x1, y1, x2, y2);
}//end constructor

const char* BattleShip::name(void) const{
	static const char name[] = "BattleShip";
	return name;
}//end name

int BattleShip::size(void) const{
	int size = 4;
	return size;
}//end size()

//end BattleShip ================================================================

//begin Cruiser =================================================================

Cruiser::Cruiser(int x1, int y1, int x2, int y2){
	lev = size();
	setPos(x1,y1,x2,y2);
}//end constructor

const char* Cruiser::name(void) const{
	static const char name[] = "Cruiser";
	return name;
}//end name

int Cruiser::size(void) const{
	int size = 3;
	return size;
}//end size()

//end Cruiser ===================================================================

//begin Destroyer ===============================================================

Destroyer::Destroyer(int x1, int y1, int x2, int y2){
	lev = size();
	setPos(x1,y1,x2,y2);
}//end constructor

const char* Destroyer::name(void) const{
	static const char name[] = "Destroyer";
	return name;
}//end Destroyer

int Destroyer::size(void) const{
	int size = 2;
	return size;
}//end size()

//end Destroyer =================================================================
