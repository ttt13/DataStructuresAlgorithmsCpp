#pragma once
#include <iostream>

class Fraction
{
public:
       // Constructors and Destructor
       Fraction();
       Fraction(int n, int d);
       ~Fraction();
 
       // PRE: 
       // POST: Fraction is simplified, e.g. 3/9, simplifies to 1/3
       void simplify();
       
       // Overloaded comparison operators
       // ==, !=, <, <=, >, >=
       bool operator==(const Fraction & f) const;

       bool operator!=(const Fraction & f) const;

       bool operator<(const Fraction & f) const;

       bool operator<=(const Fraction & f) const;

       bool operator>(const Fraction & f) const;

       bool operator>=(const Fraction & f) const;

       

private:
       int numerator; //the "top" of the fraction
       int denominator; //the "bottom" of the fraction

       // PRE:
       // POST: Returns the greatest common divisor of a and b
       int gcd(int a, int b)const;
 
       friend std::ostream & operator<<(std::ostream & os, const Fraction & f);
};