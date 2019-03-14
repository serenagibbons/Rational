#include "Rational.h"

int gcf(int a, int b) {
	if (b == 0)
		return a;
	return gcf(b, a%b);
}

// This member function transforms a rational number into 
// reduced form where the numerator and denominator have 1
// as greatest common factor
void Rational::reduce() {
	bool negative = (numerator < 0) != (denominator < 0);
	numerator = abs(numerator);
	denominator = abs(denominator);

	int factor = 2;
	while (factor <= min(numerator, denominator)) {
		if (numerator % factor == 0 && denominator % factor == 0) {
			numerator = numerator / factor;
			denominator = denominator / factor;
			continue;
		}
		factor++;
	}
	if (negative)
		numerator = -numerator;
}

// Overloaded stream insertion operator
ostream & operator << (ostream &out, Rational r) {
	out << r.numerator << "/" << r.denominator;
	return out;
}

// Overloaded addition operator
Rational Rational::operator + (const Rational &r) {
	Rational temp;
	if (this->denominator == r.denominator) {
		temp.numerator = this->numerator + r.numerator;
		temp.denominator = r.denominator;
		return temp;
	}
	else {
		int lcm;	// find least common denominator
		lcm = (this->denominator * r.denominator) / gcf(this->denominator, r.denominator);

		// multiply each fraction numerator so denominator is equal to the lcm
		temp.numerator = this->numerator * (lcm / this->denominator) + r.numerator * (lcm / r.denominator);
		temp.denominator = this->denominator * (lcm / this->denominator);
		return temp;
	}
}

// Overloaded subtraction operator
Rational Rational::operator- (const Rational &r) {
	Rational temp;
	if (this->denominator == r.denominator) {
		temp.numerator = this->numerator - r.numerator;
		temp.denominator = r.denominator;
		return temp;
	}
	else {
		int lcm;	// find least common denominator
		lcm = (this->denominator * r.denominator) / gcf(this->denominator, r.denominator);

		// multiply each fraction numerator so denominator is equal to the lcm
		temp.numerator = this->numerator * (lcm / this->denominator) - r.numerator * (lcm / r.denominator);
		temp.denominator = this->denominator * (lcm / this->denominator);
		return temp;
	}
}

// Overloaded multiplication operator
Rational Rational::operator*(const Rational &r) {
	Rational temp;
	temp.numerator = this->numerator * r.numerator;
	temp.denominator = this->denominator * r.denominator;
	return temp;
}

// Overloaded division operator
Rational Rational::operator/ (const Rational &r) {
	Rational temp;
	temp.numerator = this->numerator * r.denominator;
	temp.denominator = this->denominator * r.numerator;
	return temp;
}