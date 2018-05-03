#include <iostream>
#include <sstream>
#include <stdexcept>
#include "fraction.h"

using namespace std;

// Default constructor
Fraction::Fraction(void)
{
       numerator = 0;
       denominator = 1;
}

// Constructor
Fraction::Fraction(int num, int den)
{
       if (den <= 0){
              throw std::invalid_argument("invalid denominator value");
       }
       numerator = num;
       denominator = den;
}

Fraction::~Fraction(void)
{
}

// Returns the greatest common divisor of two integers
int Fraction::gcd(int a, int b)const{
       while (b != 0){
       int temp = b;
       b = a % b;
       a = temp;
       }
       return a;
}

// Simplifies the calling fraction
void Fraction::simplify(){
       int factor = gcd(numerator, denominator);
       numerator = numerator / factor;
       denominator = denominator / factor;
}
 
std::ostream & operator<<( std::ostream & os, const Fraction & f){
       os << f.numerator << "/" << f.denominator;
       return os;
}

bool Fraction::operator==(const Fraction & f)const{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal == paramVal);
}

bool operator!=(const Fraction & f) const
{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal != paramVal);
}

bool operator<(const Fraction & f) const
{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal < paramVal);
}

bool operator<=(const Fraction & f) const
{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal <= paramVal);
}

bool operator>(const Fraction & f) const
{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal > paramVal);
}

bool operator>=(const Fraction & f) const
{
       int coVal = numerator * f.denominator;
       int paramVal = f.numerator * denominator;
       return (coVal >= paramVal);
}