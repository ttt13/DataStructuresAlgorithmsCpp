// Peter Tran
// CMPT 225
// Assignment 4

#include <iostream>
#include "WordFrequency.h"
 
WordFrequency::WordFrequency()
{
	word = "\0";
	frequency = 1;
}

WordFrequency::WordFrequency(string str)
{

	word = str;
	frequency = 1;
}
/*
WordFrequency::~WordFrequency()
{

}*/

void WordFrequency::increment()
{
	frequency++;
}

int WordFrequency::getFrequency()
{
	return frequency;
}

string WordFrequency::getWord()
{
	return word;
}