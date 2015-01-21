/*
Name: Andy Pham
Student ID: 997942129
Fraction.cpp
*/

#include <iostream>
#include "Fraction.h"
#include <stdexcept>

using namespace std;

Fraction::Fraction(void){
	num = 0;
	denom = 1;	
}//end default constr.

Fraction::Fraction(int a, int b){
	num = a;
	denom = b;
}//end Fraction (int, int)

/*
TASK:
Scans fraction to see if denominator is 0 and to move the 
negative sign to the numerator if denom < 0.
Returns: Nothing
Arguments: Reference to variable of type Fraction.
*/
void Fraction::scanFraction(Fraction &frac){
	if (frac.denom == 0){
		throw invalid_argument("division by zero");
	}else if (frac.denom < 0){
		frac.num*= -1;
		frac.denom*=-1;
	}//end else if
}//end scanFraction

/*
TASK:
Takes two fractions and finds their gcd using
Euclid's algorithm
Returns: an integer
Arguments: 2 constant Fraction variables
*/
int Fraction::get_gcd (const Fraction n1, const Fraction n2){
	int gcd, remainder, n1_denom, n2_denom;
	n1_denom = n1.denom;
	n2_denom = n2.denom;
	/* Euclid's algorithm */
	remainder = n1_denom % n2_denom;
	while ( remainder != 0 )
	{
		n1_denom = n2_denom;
		n2_denom = remainder;
		remainder = n1_denom % n2_denom;
	}//end while
	gcd = n2_denom;
	return gcd;
}//end get_gcd

/*
TASK:
Overloads the output stream
to print a fraction in integer/postive integer
format. Also accounts for fractions that are 
over 1 or can be represented as a whole number.
*/
ostream& operator<<( ostream &output, const Fraction &frac){
	if (frac.denom == 1){		//if fraction is over 1
		output << frac.num ;
	}else if (frac.denom == frac.num){	//if fraction is the same 2 integers
		output << '1';
	}else if (frac.num % frac.denom == 0){	//Reduces fraction to whole number if possible
		output << frac.num/frac.denom ;
	}else{
		output << frac.num << "/" << frac.denom ;
	}//end else
	return output;		
}//end operator<<

/*
TASK:
Overloads the input stream to accept
2 integers and assign them to a
Fraction data member.
*/
istream& operator>>( istream &input, Fraction &frac){
	char slash;	//ignore the fraction /
	int numerator, denominator;
	input >> numerator >> slash >> denominator; 
	frac.setFraction(numerator, denominator);
	frac.scanFraction(frac);
	return input;
}//end operator>>

/*
TASK:
Adds two fractions together and then reduces them
through the function reduceFraction.
*/
Fraction operator+(const Fraction &n1, const Fraction &n2){
	Fraction fractmp;
	int gcd, common_denom;
	gcd = fractmp.get_gcd(n1, n2);
	common_denom = n1.getDenominator()*n2.getDenominator();
	fractmp.setFraction((n1.getNumerator()*n2.getDenominator() + n2.getNumerator()*n1.getDenominator()), common_denom); //adding fractions
	return fractmp.reduceFraction(fractmp, gcd);	
}//end operator+

/*
TASK:
Subtracts two fractions and then 
reduces them through the function reduceFraction.
*/
Fraction operator-(const Fraction &n1, const Fraction &n2){
	Fraction fractmp;
	int gcd, common_denom;
	gcd = fractmp.get_gcd(n1,n2);
	common_denom = n1.getDenominator()*n2.getDenominator();
	fractmp.setFraction((n1.getNumerator()*n2.getDenominator() - n2.getNumerator()*n1.getDenominator()), common_denom); //subtracting fractions
	fractmp = fractmp.reduceFraction(fractmp, gcd);
	return fractmp;
}//end operator+

/*
TASK:
Overloading equals to make sure
all data assigns over correctly
*/
const Fraction& Fraction::operator=(const Fraction& rhs){
	if (&rhs == this){
		return *this;
	}//end if
	num = rhs.num;
	denom = rhs.denom;
	return *this;
}//end operator=

int Fraction::getNumerator() const{
	return num;
}//end getNumerator

int Fraction::getDenominator() const{
	return denom;
}//end getDenominator

/*
TASK:
Uses the gcd in the argument to
reduce the fraction and return it.
*/
Fraction Fraction::reduceFraction(Fraction &frac, int gcd){
	frac.num = frac.num/gcd;
	frac.denom = frac.denom/gcd;	
	return frac;
}//end reduceFraction

void Fraction::setFraction(int n, int d){
	num = n;
	denom = d;
}//end setFraction

