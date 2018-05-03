#include <iostream>
#include "fraction.h"

using namespace std;

int main ( void )
{
	Fraction f1(3,4);

	Fraction f2(3,4);

	cout << f1 << " == " << f2 << ": " << (f1==f2) << endl;

	return 0;
} 