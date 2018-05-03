#include <iostream>


using namespace std;

int main ( void )
{
	int size = 0;
	int counter = 0;
	int *array = NULL;
	int temp = 0;
	int runningSum = 0;

	cout << "Please enter the number of values to be summed: ";
	cin >> size;
	array = new int [size];

	while( counter < size ){
		cout << "Please enter an integer: ";
		cin >> temp;
		runningSum += temp;
		array[counter] = temp;
		counter++;
	}
	cout << "The total is " << runningSum << endl; 

	return 0;
}