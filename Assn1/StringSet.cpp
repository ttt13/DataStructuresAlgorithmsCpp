// Assignment 1
// Peter Tran
// 19 September 2017

#include "StringSet.hpp"
#include <iostream>

// Default constructor
StringSet::StringSet()
{
	current = 0;
	maximum = 2;
	charSet = new string[maximum];
}

// Deep copy constructor
StringSet::StringSet(const StringSet & duplicate)
{
	// Copy over the sizes
	current = duplicate.current;
	maximum = duplicate.maximum;

	charSet = new string[maximum];
	// Copy over the strings
	for (int i = 0; i < current; i++){
		charSet[i] = duplicate.charSet[i];
	}

}

// Destructor
StringSet::~StringSet()
{
	delete[] charSet;
}

// PRE:
// PARAM: Value entered must be a string
// POST: String inserted at the end of the string set
bool StringSet::insert(std::string strEntry)
{
	// Don't insert duplicates.
	for(int x = 0; x < current; x++){
		if(strEntry == charSet[x]){
			return false;
		}
	}

	// Create new space if necessary.
	if(current >= maximum){
		string* temp = new string[maximum];
		for (int i = 0; i < maximum; i++){
			temp[i] = charSet[i];
		}

		maximum = maximum * 2;

		charSet = new string[maximum];

		// Copy over the contents
		for (int x = 0; x < current; x++){
			charSet[x] = temp[x];
		}

		delete[] temp;
	}

	// Insert the string.
	charSet[current++] = strEntry;
	return true;
}

// PRE:
// PARAM: String to be removed
// POST: String is removed, or returns false if string is not in set.
bool StringSet::remove(std::string strEntry)
{
	// If the StringSet is empty.
	if(current == 0){
		return false;
	}

	// Find the string, swap it out.
	for(int x = 0; x < current; x++){
		if(strEntry == charSet[x]){
			charSet[x] = charSet[current-1];
			current--;
			return true;
		}
	}
	return false;
}

// PRE:
// PARAM: String to be found
// POST: Returns index of the string location, or -1 if string was not found.
int StringSet::find(std::string strEntry) const
{
	for (int x = 0; x < current; x++){
		if (charSet[x] == strEntry){
			return x;
		}
	}
	return -1;
}

// POST: Returns the size of the string set
int StringSet::size() const
{
	return current;
}

// PRE:
// PARAM: StringSet to be added
// POST: Returns a StringSet that contains all elements of both StringSets, without duplicates.
StringSet StringSet::unions( const StringSet & singleStr ) const
{
	StringSet combined(singleStr);

	int len = current;

	// Insert strings only if they do not already exist in the StringSet.
	for( int i = 0; i < len; i++ ){
		if (combined.find(charSet[i]) == -1){
			combined.insert(charSet[i]);
		}
	}
	return combined;
}

// PRE:
// PARAM: StringSet to be compared
// POST: Returns a StringSet that contains elements which appear in both StringSets.
StringSet StringSet::intersection(const StringSet & singleStr) const
{
	StringSet combined(*this);


	int len = current;

	// If the string appears only in one StringSet, remove it from the combined.
	for (int i = 0; i < len; i++){
		if (singleStr.find(charSet[i]) < 0){
			combined.remove(charSet[i]);
		}
	}
	return combined;
}

// PRE:
// PARAM: StringSet to subtract from.
// POST: Returns a StringSet that contains elements which do not appear in the parameter StringSet.
StringSet StringSet::difference(const StringSet & singleStr) const
{
	StringSet combined(*this);

	int len = current;

	// If the string appears in both StringSets, remove it from the combined.
	for (int i = 0; i < len; i++){
		if (singleStr.find(charSet[i]) >= 0){
			combined.remove(charSet[i]);
		}
	}
	return combined;
}