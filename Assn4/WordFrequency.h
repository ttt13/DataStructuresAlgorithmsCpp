// Peter Tran
// CMPT 225
// Assignment 4

#include <string>
using namespace std;

class WordFrequency
{
public:
	
	// Default constructor
	WordFrequency();

	// Constructor
	WordFrequency(string word);

	// POST: Increments freqency
	void increment();

	// POST: Returns frequency
	int getFrequency();

	// POST: Returns word
	string getWord();

private:

	string word;

	// Counts number of same word inserted
	int frequency;
	
};