#include "PriorityQueue.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main( void )
{

	PriorityQueue test1;
	//cout << test1.size() << " Current" << test1.maxSize() << " Max" << endl;
	//test1.remove(); // Throw passed!
	//test1.peek(); // Throw passed!
	test1.insert(100);
	test1.insert(25);
	test1.insert(50);
	test1.insert(5);
	test1.insert(200);
	test1.insert(75);
	test1.insert(35);

	test1.remove();

	//PriorityQueue test2 = test1; //Assn Operator test

	PriorityQueue test2(test1); // Copy constructor test

	for(int y = 0; y < 6; y++){
		test1.remove();
	}



	int* trav = test2.contents();
/*
	for(int x = 0; x < 6; x++){
		cout << trav[x] << endl;
	}*/

	cout << "-----" << endl;

	int testArr[7] = {100, 25, 50, 5, 200, 75, 35};

	PriorityQueue test3(testArr, 7);
	//test3.insert(456);
	int* trav3 = test3.contents();
	for(int x = 0; x < 7; x++){
		cout << trav3[x] << endl;
	}

	test3.sort(testArr, 7);

	cout << "~~~~~~~~~~~~~~" << endl;
	for(int x = 0; x < 7; x++){
		cout << testArr[x] << endl;
	}

	cout << "----------" << endl;
	


	/*
	for(int i = 0; i < 50; i++){
		test1.insert(i);
	}
	test1.insert(23);
	test1.insert(250);
	test1.insert(234);

	for(int k = 60; k < 100; k++){
		test1.insert(k);
	}

	test1.remove();

	cout << test1.peek() << endl;
	cout << test1.size() << " Current" << test1.maxSize() << " Max" << endl;
	*/

	return 0;

}