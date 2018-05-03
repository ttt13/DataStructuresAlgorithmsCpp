// Peter Tran
// CMPT 225
// Assignment 4

#include "WordFrequency.h"
#include <string>
using namespace std;

class HashTable
{
public:

	// Default Constructor
	HashTable();

	// PRE: Size entered is greater than 1.
	HashTable(int n);

	// Deep copy constructor 
	HashTable(const HashTable & HashT);

	// Destructor
	~HashTable();

	// Overloaded assignment operation - for deep copies.
	HashTable & operator=(const HashTable & HashT);

	// PRE:
	// PARAM: Word to be inserted.
	// POST: Increments the frequency if the word is already in hash
	//       table, or inserts WordFrequency object into table.
	void insert(string word);

	// PRE:
	// PARAM: Word to be searched.
	// POST: Returns the frequency if the word in the table, or 0 if
	//		 the word is not in the hash table. 
	int search(string word);

	// POST: Returns the current number of items in the hash table.
	//		 NOTE: Doesn't count duplicates (frequencies)
	int size();

	// POST: Returns the size of the hash table.
	int maxSize();

	// POST: Returns how full the hash table is (current/max)
	float loadfactor();

	// POST: Returns a pointer to an array of WordFrequency objects, 
	//       containing the contents of the hash table
	WordFrequency* dump();

private:
	// An array of pointers to WordFrequency Objects.
	WordFrequency** arr;

	// Max size of the Hash Table
	int max;

	// Current number of items in Hash Table
	int current;

	// Helper method 
	// POST: Finds closest prime number larger than n.
	int findPrime(int n);

	// Helper method
	// POST: Creates deep copy of Hash Table
	void deepCopy(const HashTable & HashT);

	// Helper method
	// POST: Creates hash key for string parameter
	int hash(string word);

	// Helper method
	// POST: Destroys hash table
	void destroyHash();

	// Helper method
	// POST: Probes hashtable using quadratic probing, inserts word
	//		 in appropriate location.
	void probeInsert(string inWord);
	
};
