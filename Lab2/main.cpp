#include <iostream>
#include <stdexcept>
#include "ArrayClass.h"

using namespace std;

int main ( void )
{

	ArrayClass test;

	for (int i = 0; i <= 10; i++){
		test.insert(i);
	}	


	try{
		test.set(15, 123);
	}

	catch(std::out_of_range oor){
		cout << oor.what() << endl;
	}


	return 0;
}