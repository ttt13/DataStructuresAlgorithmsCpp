#include <iostream>
#include "HashTable.h"
#include <string>
#include <cstdlib>

int main (void)
{
	cout << "--- HashTable Test ---" << endl;

	// Empty hashtable test
	cout << "Creating empty HT Test..." << endl;
	//HashTable test1();
	HashTable test1 = HashTable();
	cout << "Test1 size 101: " << test1.maxSize() << " Current = 0: " << test1.size() << endl;

	// Prime hashtable test
	cout << "Creating HT with n = 6..." << endl;
	HashTable test2(3); //= HashTable(3);
	cout << "Test2 size 7: " << test2.maxSize() << " Current = 0: " << test2.size() << endl;

	// Deep copy test
	cout << "Deep copy test... test1 = test2..." << endl << endl;
	test1 = test2;
	cout << "Test1 size 7: " << test1.maxSize() << " Current = 0: " << test1.size() << endl;

	// Testing insertion on test1. At 5/7 it should double in size.
	test1.insert("peter");
	test1.insert("peter");
	test1.insert("peter");
	test1.insert("petertran");
	test1.insert("areyousfu");
	test1.insert("computingscience");
	test1.insert("johnedgar");
	test1.insert("switchsizes");
	cout << "Test1 size 17: " << test1.maxSize() << " Current = 6: " << test1.size() << endl;
	cout << test1.search("peter") << "<----3" << endl;
	cout << test1.loadFactor() << "<---loadfactor" << endl;
	cout << endl;
	//Deep copy 2
	cout << "Deep copy test2 = test1..." << endl << endl;
	test2 = test1;
	cout << test2.maxSize() << "<-- MaxSize" << endl;
	cout << test2.size() << "<-- current size" << endl;
	cout << test2.search("peter") << "Search for peter" << endl;
	cout << test2.search("computingscience") << "search for CS" << endl;
	cout << test2.loadFactor() << "<-- loadfactor" << endl;	

	cout << endl;

	cout << "Dump tests..." << endl;
	//WordFrequency* test3 = test2.dump();

	/*for(int i = 0; i < test2.size(); i++){
		cout << (test3[i]).getWord() << endl;
		cout << (test3[i]).getFrequency() << "< Freq" << endl;
	}*/
return 0;
}