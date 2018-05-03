#include "ArrayClass.h"
 
// Default constructor
// POST: Creates an ArrayClass object with an array of size 2
// PARAM:
ArrayClass::ArrayClass()
{
       arrSize = 2;
       arr = new int[arrSize];
       n = 0;
}
 
// Destructor
// POST: De-allocates dynamic memory associated with object
ArrayClass::~ArrayClass()
{
       delete[] arr;
}
 
// Returns the number of elements stored in the array
// PRE: Creates an ArrayClass object with an array of size 2
// POST: Retruns n
int ArrayClass::size()
{
       return n;
}

void ArrayClass::insert(int value)
{
	if (n == arrSize){

		int *temp = new int[arrSize];
		for (int i = 0; i < arrSize; i++){
			temp[i] = arr[i];
		}

		arrSize = arrSize * 2;

		arr = new int[arrSize];

		for (int x = 0; x < n; x++){
			arr[x] = temp[x];
		}

		delete[] temp;

	}
	arr[n++] = value;

}
 

int ArrayClass::sum()
{
	int runningSum = 0;

	for (int x = 0; x < n; x++){
		runningSum += arr[x];
	}

return runningSum;
}