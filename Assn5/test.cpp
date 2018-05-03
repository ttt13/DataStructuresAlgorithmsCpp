#include "PriorityQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	
	cout << "Testing default constructor for strings..." << endl;

	PriorityQueue<string> test1;
	//test1.peek(); // Should throw error.
	//test1.remove(); // Throws error - success!
	cout << "Size: " << test1.size() << endl;
	cout << "Testing insert..." << endl;
	test1.insert("peter");
	test1.insert("mark");
	test1.insert("micah");
	test1.insert("john");
	test1.insert("edgar");
	test1.insert("sfu");
	test1.insert("zebra");
	test1.insert("blah");
	test1.insert("advark");
	cout << "Size: " << test1.size() << " Max size: " << test1.maxSize() << endl;
	cout << "Peek -> " << test1.peek() << endl;
	cout << endl << "Content test..." << endl;

	/*for (int a = 0; a < 8; a++){
		cout << "Removed: " << test1.remove() << endl;
		//cout << "New root: " << test1.peek() << endl;
	}*/
	
	//cout << endl << "Contents retest... " << endl;
	
	string* outputTest = test1.contents();
	
	for (int i = 0; i < test1.size(); i++){
		cout << outputTest[i] << endl;
	}

	

	cout << "Size ---> " << test1.size() << endl;
	cout << endl << "Sort outputTest array..." << endl;
	test1.sort(outputTest, test1.size());
	//cout << endl << "Test case: Sort it twice: " << endl;
	//test1.sort(outputTest, test1.size());
	for (int k = 0; k < test1.size(); k++){
		cout << outputTest[k] << endl;
	}


	cout << endl << "Deep copy tests... " << endl;
	PriorityQueue<string> test2(outputTest, test1.size());

	for (int a = 0; a < 8; a++){
		cout << "Removed: " << test1.remove() << endl;
		//cout << "New root: " << test1.peek() << endl;
	}

	string* outputTest2 = test2.contents();

	for (int k = 0; k < test2.size(); k++){
		cout << outputTest2[k] << endl;
	}

	/*cout << endl << "Removal test..." << endl;
	cout << test1.size() << "<< Size" << endl;
	for (int j = 0; j < 9; j++){
		cout << j << endl;
		test1.remove();
	}
	//test1.remove(); throw success!
	cout << "Size: " << test1.size() << " Max size: " << test1.maxSize() << endl;
	*/
/*
	PriorityQueue<string> testInt;
	for(int x = 0; x < 1000; x++){
		testInt.insert("peterpeterpeterpeterpetera");
		testInt.insert("peterpeterpeterpeterpeterb");
	}

	string* testCont = testInt.contents();
	
	testInt.sort(testCont, 2000);
	for(int j = 0; j < 2000; j++){
		cout << testCont[j] << endl;
	}*/
	return 0;
}