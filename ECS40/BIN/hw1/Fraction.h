/*
Name: Andy Pham
Student ID: 997942129
Fraction.h
*/

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction
{
	friend ostream& operator<<(ostream &, const Fraction &);
	friend istream& operator>>(istream &, Fraction &);
	friend Fraction operator+(const Fraction &, const Fraction &);
	friend Fraction operator-(const Fraction &, const Fraction &);
public:
	Fraction(); //default constr
	Fraction(int, int); //custom constr
	const Fraction& operator=(const Fraction &);
	Fraction reduceFraction(Fraction &, int);	//uses gcd to reduce fraction to lowest irreducible form
	void setFraction(int, int);
	void scanFraction(Fraction &);			//tests to see if fraction denom is negative/not zero
	int get_gcd (const Fraction, const Fraction);
	int getNumerator() const;
	int getDenominator() const;
private:
	int num;
	int denom;
};//end class Fraction
#endif



