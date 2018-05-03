// Assignment 1
// Peter Tran
// 19 September 2017

#ifndef STRINGSET_H
#define STRINGSET_H
#include <string>
using std::string;

class StringSet
{
public:

	// Default constructor
	StringSet();

	// Deep copy constructor 
	StringSet(const StringSet & duplicate);

	// Destructor
	~StringSet();

	// PRE:
	// PARAM: Value entered must be a string
	// POST: String inserted at the end of the string set
	bool insert(string strEntry);

	// PRE:
	// PARAM: String to be removed
	// POST: String is removed, or returns false if string is not in set.
	bool remove(string strEntry);

	// PRE:
	// PARAM: String to be found
	// POST: Returns index of the string location, or -1 if string was not found.
	int find( string strEntry) const;

	// POST: Returns the size of the string set
	int size() const;

	// PRE:
	// PARAM: StringSet to be added
	// POST: Returns a StringSet that contains all elements of both StringSets, without duplicates.
	StringSet unions(const StringSet & singleStr) const;

	// PRE:
	// PARAM: StringSet to be compared
	// POST: Returns a StringSet that contains elements which appear in both StringSets.
	StringSet intersection(const StringSet & singleStr) const;
	
	// PRE:
	// PARAM: StringSet to subtract from.
	// POST: Returns a StringSet that contains elements which do not appear in the parameter StringSet.
	StringSet difference(const StringSet & singleStr) const;
	
private:
	//For the current index 
	int current;

	// Array of strings
	string* charSet;

	// The size of the string array
	int maximum;
};

#endif