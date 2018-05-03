// Peter Tran
// CMPT 225
// Assignment 4

#include <iostream>
#include "HashTable.h"
#include <cstdlib>

// Default constructor
// POST: Creates a hash table of default size: 101; 
//		 sets all array elements to NULL.
HashTable::HashTable()
{
	arr = new WordFrequency * [101];

	for (int i = 0; i < 101; i++){
		arr[i] = NULL;
	}

	max = 101;
	current = 0;
}

// Constructor 
// PRE: n is greater than 0.
// PARAM: n - Desired size of HashTable
// POST: Creates a hash table to store n items. 
// 		 Size is smallest prime number greater than 2n; 
// 		 Sets all array elements to NULL.
HashTable::HashTable(int n)
{
	int prime = findPrime(n);
	max = prime;
	current = 0;
	arr = new WordFrequency * [prime];

	for (int i = 0; i < prime; i++){
		arr[i] = NULL;
	}
}

// Copy constructor
// PARAM: HashTable
// POST: Creates deep copy of HashTable.
HashTable::HashTable(const HashTable & HashT)
{
	deepCopy(HashT);
}

// Destructor
HashTable::~HashTable()
{
	destroyHash();
}

// Overloaded assignment operator
// PARAM: HashTable
// POST: Creates deep copy of HashTable.
HashTable & HashTable::operator=(const HashTable & HashT)
{
	// Deep copy only if it isn't copying itself.
	if(this != &HashT){
		destroyHash();
		deepCopy(HashT);
	}

	return *this;
}

void HashTable::insert(string word)
{
	// Make sure it returns a decimal, not an integer.
	float load = (float)current/(float)max;
	
	// If HashTable is over 67% full, make a bigger HashTable. 
	if( load >= 0.67){

		// Set current items to 0 - This will prevent overcounting later.
		current = 0;

		// Make a temp pointer arrary, store contents in there.
		WordFrequency** temp = new WordFrequency* [max];
		
		for(int i = 0; i < max; i++){
			// If there was no object in the original array index, set same index in temp to be NULL.
			if(arr[i] == NULL){
				temp[i] = NULL;
			}

			// If there is an object:
			else if(arr[i] != NULL){

				// Get its frequency
				int getFreq = (arr[i])->getFrequency();	

				// Create the WF object		
				temp[i] = new WordFrequency( (arr[i])->getWord() );
				
				// Note that WF object already has freq 1 by default.
				if(getFreq > 1){

					// Increment as necessary.
					for(int x = 1; x < getFreq; x++){
						(temp[i])->increment();
					}
				}
			}
		} //For

		// Find the new size. 
		int newSize = findPrime(max);

		//Max size of temp array
		int tempMax = max;
		max = newSize;

		arr = new WordFrequency* [newSize];

		// Set everything to null
		for (int j = 0; j < newSize; j++){
			arr[j] = NULL;
		}

		string inWord = "\0";

		// Move things back into the array with new size.
		for (int k = 0; k < tempMax; k++){

			if(temp[k] != NULL){
				inWord = (temp[k])->getWord();
				int getFreq2 = (temp[k])->getFrequency();

				// Reinsert using quadratic probing. 
				// Note that this helper method will increment current back to its original state.
				for (int a = 0; a < getFreq2; a++){
					probeInsert(inWord);
				}
			}
		}

		// Destroy temp array
		for( int m = 0; m < tempMax; m++ ){
			delete temp[m];
			temp[m] = NULL;
		}
	} // If

	//----- Actual insertion section. -----
	// Use quadratic probing.
	// Note that this method also increments current.
	probeInsert(word); 
}

// PARAM: String to be searched for
// POST: Returns the frequency if the word in the table, or 0 if
//		 the word is not in the hash table.
int HashTable::search(string word)
{
	int probe = 0;

	int getIndex = 0;

	// Get the hash key
	int hashIndex = hash(word);

	bool foundWord = false;

	while(!foundWord){

		// Quadratic probing.
		getIndex = hashIndex + (probe*probe);

		//Word isn't there, probe lands on NULL, return 0.
		if( arr[getIndex] == NULL){
			return 0;
		}

		// If you find it, return frequency
		if ( (arr[getIndex])->getWord() == word ){
			return (arr[getIndex])->getFrequency();
		}

		// Increment probe, have another go
		probe++;
	}	
}

// POST: Returns the current number of items in the hash table.
//		 NOTE: Doesn't count duplicates (frequencies)
int HashTable::size()
{
	return current;
}

// POST: Returns the size of the hash table.
int HashTable::maxSize()
{
	return max;
}

// POST: Returns how full the hash table is (current/max)
float HashTable::loadfactor()
{
	// Make sure these are floats. 
	float load = (float)current/(float)max;
	return load;
}

// POST: Returns a pointer to an array of WordFrequency objects, 
//       containing the contents of the hash table
WordFrequency* HashTable::dump()
{
	WordFrequency* newArr = new WordFrequency[current];
	int counter = 0;
	int getFreq;

	// Copy over only WordFrequency Objects.
	for (int i = 0; i < max; i++){
		if (arr[i] != NULL){
			newArr[counter] = *arr[i];
			counter++;
		}
	}
	return newArr;
}

/* --------------- HASHTABLE HELPER METHODS --------------- */

// Used by constructor and insert
// PARAM: n - Desired size
// POST: Returns smallest prime number greater than 2*n.
int HashTable::findPrime(int n)
{
	int prime;
	int primeSearch = (2*n);
	bool found = false;
	bool isPrime = true;
	int counter = 2;

	// While a prime number isn't found yet
	while(found == false){

		// Check if the number is divisible by any numbers [2 to number/2].
		for ( int i = 2; i < primeSearch/2; i++ ){
			
			// If the number is divisible, it is not prime.
			if (primeSearch % i == 0){
				isPrime = false;
			}
		}
		// If it iterates through the for loop and stays true, it is prime.
		if(isPrime == true){
			return primeSearch;
		}

		// Otherwise, increment the primesearch, go again.
		else{
			primeSearch++;
			isPrime = true;
		}
	}

return prime; 
}

// USAGE: Copy constructor and overloaded assignment operator
// PARAM: Hashtable reference
// POST: Creates deep copy of Hashtable 
void HashTable::deepCopy(const HashTable & HashT)
{
	max = HashT.max;
	current = HashT.current;
	arr = new WordFrequency * [max];
	int i = 0;
	int getFreq;
	
	for(int i = 0; i < max; i++){

		// Make same indices NULL.
		if(HashT.arr[i] == NULL){
			arr[i] = NULL;
		}

		// Get the word and frequency, and reincrement frequency.
		else if(HashT.arr[i] != NULL){		
			arr[i] = new WordFrequency( (HashT.arr[i])->getWord() );
			getFreq = (HashT.arr[i])->getFrequency();

			for (int y = 1; y < getFreq; y++){
				arr[i]->increment();
			}
		}
	} // For
}

// USAGE: Probe insertion (which in turn is used for insertion)
// PARAM: String to be hashed
// POST: Returns hash key for specific string using Horner's method.
int HashTable::hash(string word)
{
	int i = 0;
	int getAscii = 0;
	int total = 0;
	bool lastWord = false;

	// Iterate through the whole string
	while(word[i] != '\0' && lastWord == false){

		// Convert ASCII to 1 to 26, a to z.
		getAscii = word[i] - 96;

		if (i == 0){
			total += getAscii * 32;

			if(word[i+1] != '\0'){
				total += (word[i+1] - 96);
			}
		}

		// If i isn't the first char, and the next char exists
		if (i > 0 && word[i+1] != '\0'){
			// Multiply by 32, add the next char
			total = (total * 32 + (word[i+1] - 96));
		}

		// Do not multiply the last char by 32.
		if (word[i+1] == '\0'){
			lastWord = true;
		}

		// Apply modulus on chars except for the last char
		if(lastWord != true){
			total = total % max;
		}

		i++;
	}
	return total;
}

// USAGE: Destructor and overloaded assignment operator
// POST: Destroys HashTable
void HashTable::destroyHash()
{
	// Delete all WordFrequency objects, set each index back to NULL
	for(int i = 0; i < max; i++){
		delete arr[i];
		arr[i] = NULL;
	}

	// Then delete the pointer array, set max and current to 0.
	delete[] arr;
	max = 0;
	current = 0;
}

// USAGE: Insertion
// PARAM: Word to be inserted
// POST: Uses quadratic probing to insert word.
void HashTable::probeInsert(string word)
{
	int probe = 0;
	int getIndex = 0;

	// Find the appropriate index.
	int hashIndex = hash(word);
	bool foundInsert = false;

	// Probe the hashtable beginning from the hashIndex.
	while(!foundInsert){

		// In first iteration, probe is 0.
		getIndex = hashIndex + (probe * probe);

		// If it finds an empty space in the array, insert the object.
		if( arr[getIndex] == NULL ){
			WordFrequency* newWord = new WordFrequency(word);
			arr[getIndex] = newWord;
			current++;
			foundInsert = true; 		
		}

		// If it finds the same word, increment frequency.
		else if ( (arr[getIndex])->getWord() == word ){
			(arr[getIndex])->increment();
			foundInsert = true;
		}

		// Otherwise, continue quadratic probing.
		else{
			probe++;
		}
	} //while
}


