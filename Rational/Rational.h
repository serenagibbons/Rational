#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Rational {
	// Declaration of overloaded stream insertion operator
	friend ostream & operator << (ostream &, Rational r);
	friend int gcf(int a, int b);

public:
	// Declaration of overloaded addition operator
	Rational operator+ (const Rational &r);

	// Declaration of overloaded addition operator
	Rational operator- (const Rational &r);

	// Declaration of overloaded multiplication operator
	Rational operator* (const Rational &r);

	// Declaration of overloaded division operator
	Rational operator/ (const Rational &r);

private:
	int numerator, denominator;
public:
	// Default constructor
	Rational() {
		numerator = 0;
		denominator = 0;
	}
	// Constructor builds a rational number n/d
	Rational(int n, int d) :numerator(n), denominator(d) {
		reduce();
	}
private:
	void reduce();
};

#endif // !RATIONAL_H
