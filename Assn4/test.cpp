
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include "HashTable.h"

using namespace std;

vector<string> readFile(string infile);
vector<string> readWords(string infile);
void stringsToWords(vector<string> & vec);
void clean(string & s);

// Opens a file and reads the contents into a vector removing punctuation
// PARAM: infile = name of the file to be opened
// PRE: the file contains words separated by white space
// POST: returns a vector containing the contents of infile cleaned of
//       punctuation and with uppercase converted to lowercase
vector<string> readWords(string infile)
{
	vector<string> result = readFile(infile);
	stringsToWords(result);
	return result;
}


// Opens a file and reads the contents into a vector
// PARAM: infile = name of the file to be opened
// PRE: the file contains words separated by white space
// POST: returns a vector containing the contents of infile
vector<string> readFile(string infile)
{
	ifstream ist(infile.c_str());
	if (ist.fail())
		throw runtime_error(infile + " not found");
	istream_iterator<string> start(ist), end;
	vector<string> result(start, end);

	// DEBUG PRINT
	//for (unsigned int i = 0; i < result.size(); ++i) {
	//	cout << result[i] << endl;
	//}

	ist.close();
	return result;
}

// Removes non alpha characters, empty string and converts to lowercase
// PARAM: vec = vector to be cleaned (in place)
// POST: non-alpha character and empty string removed from vec,
//       all uppercase characters converted to lowercase
void stringsToWords(vector<string> & vec)
{
	// Remove non alpha characters and empty strings
	for (unsigned int i = 0; i < vec.size(); ++i) {
		clean(vec[i]); //removes non-alpha and converts uc to lc

					   // Remove empty strings
		if (vec[i].size() == 0) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}

	// DEBUG PRINT
	//for (unsigned int i = 0; i < vec.size(); ++i) {
	//	cout << vec[i] << endl;
	//}
}

// Removes non alpha characters and converts uppercase to lowercase
// PARAM: s = string to be cleaned (in place)
// POST: non-alpha characters removed from s, UC to LC
void clean(string & s)
{
	unsigned int i = 0;
	while (i < s.size()) {
		// Remove non-alpha
		if (!isalpha(s[i])) {
			s.erase(i, 1);
		}
		// Convert uppercase to lowercase
		else if (isupper(s[i])) {
			s[i] = tolower(s[i]);
			i++;
		}
		else {
			i++;
		}
	}
}


int main( void )
{
	vector<string> words = readWords("a3test3.txt");
	HashTable ht1(words.size());
	for (unsigned int i = 0; i < words.size(); ++i) {
	       ht1.insert(words[i]);
	}

	WordFrequency* ht1WF = ht1.dump();
/*
	for ( int k = 0; k < words.size(); k++ ){
		cout << ht1WF[k].getWord() << endl;
	}*/

	//HashTable ht2(ht1);
	HashTable ht2 = ht1;
	WordFrequency* ht2WF = ht2.dump();

	for ( int k = 0; k < words.size(); k++ ){
		if( ht1WF[k].getWord() != ht2WF[k].getWord() ){
			cout << "not equal" << endl;
		} 
	}

	cout << ht1.size() << ht1.maxSize() << endl;
	cout << ht2.size() << ht2.maxSize() << endl;
return 0;
}