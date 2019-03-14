#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include "Rational.h"
using namespace std;

int main() {
	cout << "Reduced form: " << Rational(6, -12) << endl;
	cout << endl;

	// Declare objects
	Rational obj1(1, 5), obj2(2, 3), obj3(2, 5);

	// Perform rational 
	cout << "Multiplication:\n";
	cout << obj1 << " * " << obj2 << " = " << obj1.operator*(obj2) << endl << endl;

	cout << "Division:\n";
	cout << obj1 << " / " << obj2 << " = " << obj1.operator/(obj2) << endl << endl;

	cout << "Addition:\n";
	cout << obj1 << " + " << obj3 << " = " << obj1 + obj3 << endl; // addition: same denominator
	cout << obj1 << " + " << obj2 << " = " << obj1 + obj2 << endl << endl; // addition: diff denominators

	cout << "Subtraction:\n";
	cout << obj3 << " - " << obj1 << " = " << obj3 - obj1 << endl; // subtraction: same denominator
	cout << obj2 << " - " << obj1 << " = " << obj2 - obj1 << endl << endl; // subtraction: diff denominator

	system("pause");
	return 0;