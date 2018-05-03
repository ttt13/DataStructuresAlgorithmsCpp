
// --------------- PUT THIS BACK IN .H LATER ---------------//
#include <stdexcept>
#include "PriorityQueue.h"
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
PriorityQueue<T>::PriorityQueue()
{
	arr = new T[4];
	max = 4;
	current = 0;
}

template <class T>
// Where x the arr that is to be inserted, n is size
PriorityQueue<T>::PriorityQueue(T* copyArr, int n)
{
	arr = new T[n];

	for(int i = 0; i < n; i++){
		arr[i] = copyArr[i];
	}

	current = n;
	max = n;

	heapify(arr, n);

//	cout << arr[0] << "In cons" << endl;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue & PQ)
{
	deepcopy(PQ);
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	destroyPQ();
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue & PQ)
{
	if(this != &PQ){
		destroyPQ();
		deepcopy(PQ);
	}

	return *this;
}

template <class T>
void PriorityQueue<T>::insert(T n)
{
	// Create larger array.
	if(current == max){
		T *temp = new T [current];

		for(int i = 0; i < current; i++){
			temp[i] = arr[i];
		}

		max *= 2;

		arr = new T[max];

		for(int j = 0; j < current; j++){
			arr[j] = temp[j];
		}

		delete[] temp;
	}

	// Insert into leftmost available space.
	arr[current] = n;

	int parent = (current - 1)/2;
	int bubble = current;
	int temporary;

	while(arr[parent] < arr[bubble] && bubble > 0){

		swap(&arr[parent], &arr[bubble]);

		// Bubble up
		bubble = parent;
		parent = (parent - 1)/2;
	}

	//Increment current
	current++;
}

template <class T>
T PriorityQueue<T>::remove()
{
	if (current == 0){
		throw std::runtime_error("Remove error: PriorityQueue is empty.");
	}

	T retValue = arr[0];

	arr[0] = arr[current - 1];
	arr[current - 1] = -1;

	int traverse = 0;
	int rightChild = 2*traverse + 1;
	int leftChild = 2*traverse + 2;

	while( (arr[traverse] < arr[rightChild] || arr[traverse] < arr[leftChild] ) && (rightChild < current || leftChild < current) ){
			
		if(arr[rightChild] > arr[leftChild]){
			//swap
			swap(&arr[traverse], &arr[rightChild]);
			// traverse down 
			traverse = rightChild;
		}

		else if(arr[leftChild] >= arr[rightChild]){
			//swap
			swap(&arr[traverse], &arr[leftChild]);
			// traverse down
			traverse = leftChild;
		}

		rightChild = 2*traverse + 1;
		leftChild = 2*traverse + 2;
	}

	current--;

	return retValue;
}

template <class T>
T PriorityQueue<T>::peek()
{
	if (current == 0){
		throw std::runtime_error("Peek error: PriorityQueue is empty.");
	}

	return arr[0];
}

template <class T>
int PriorityQueue<T>::size()
{
	return current;
}

template <class T>
int PriorityQueue<T>::maxSize()
{
	return max;
}

template <class T>
bool PriorityQueue<T>::empty()
{
	return (current == 0);
}

template <class T>
void PriorityQueue<T>::sort(T* arrSort, int n)
{ 
	/*
	cout << arrSort[0] << "In sort" << endl;
	cout << n << "Size" << endl;
	heapify(arrSort, n);
	swap(&arrSort[0], &arrSort[n-1]);

	cout << "**************" << endl;

	heapify(arrSort, n-1);
	//cout << arrSort[0] << " Should be 100" << endl;
	swap(&arrSort[0], &arrSort[n-2]);
	*/

	int counter = (n-1);
	for (int i = n; i >= 1; i--){
		heapify(arrSort, i);
		//cout << arrSort[0] << endl;
		swap(&arrSort[0], &arrSort[counter]);
		counter--;
	} 

	
}

template <class T>
int* PriorityQueue<T>::contents()
{
	return arr;
}

template <class T>
//Helper method
void PriorityQueue<T>::deepcopy(const PriorityQueue & PQ)
{
	max = PQ.max;
	current = PQ.current;

	arr = new T[max];

	for(int i = 0; i < max; i++){
		arr[i] = PQ.arr[i];
	}
}

template <class T>
//Helper method
void PriorityQueue<T>::destroyPQ()
{
	max = 0; 
	current = 0;
	delete[] arr;
}

template <class T>
//Helper method
void PriorityQueue<T>::swap(T *x, T *y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

template <class T>
void PriorityQueue<T>::heapify(T* arrSort, int n)
{
	int bubble = n/2 - 1;
	int leftChild = 2*bubble + 1;
	int rightChild = 2*bubble + 2;

	//cout << bubble << " <bubble " << leftChild << " <LC " << rightChild << " <RC " << endl;

	while (bubble >= 0){ //&& leftChild < n && rightChild < n){

		leftChild = 2*bubble + 1;
		rightChild = 2*bubble + 2;

		//cout << bubble << " <bubble " << leftChild << " <LC " << rightChild << " <RC " << endl;
		if(arrSort[leftChild] > arrSort[bubble] || arrSort[rightChild] > arrSort[bubble] ){
			
			if(arrSort[leftChild] >= arrSort[rightChild] && leftChild < n){
				swap(&arrSort[leftChild], &arrSort[bubble]);

				//cout << "Swap left and bubble" << endl;
			}

			else if(arrSort[rightChild] > arrSort[leftChild] && rightChild < n){
				swap(&arrSort[rightChild], &arrSort[bubble]);
				//cout << "Swap right and bubble" << endl;
			}
		}

		bubble--;
	}
}




/*
	// No need to check the children of the leaves.
	int bubble = n/2 - 1;
	int leftChild = 2*bubble + 1;
	int rightChild = 2*bubble + 2;

	cout << bubble << " <bubble " << leftChild << " <LC " << rightChild << " <RC " << endl;

	// Move up.
	while (bubble >= 0){ //&& leftChild < n && rightChild < n){

		leftChild = 2*bubble + 1;
		rightChild = 2*bubble + 2;

		//cout << bubble << " <bubble " << leftChild << " <LC " << rightChild << " <RC " << endl;
		// If the children are larger than the parent
		if(arrSort[leftChild] > arrSort[bubble] || arrSort[rightChild] > arrSort[bubble] ){
			
			// If the left child is larger than right child, swap parent with left.
			if(arrSort[leftChild] >= arrSort[rightChild] && leftChild < n){
				swap(&arrSort[leftChild], &arrSort[bubble]);

				cout << leftChild << " & " << bubble << endl;
			}
			// If right child is larger than left child, swap parent with right.
			else if(arrSort[rightChild] > arrSort[leftChild] && rightChild < n){
				swap(&arrSort[rightChild], &arrSort[bubble]);
				cout << rightChild << " & " << bubble << endl;
			}
		}
		// Move up the levels.
		bubble--;
	} */

	/*
	cout << arrSort[0] << "In sort" << endl;
	cout << n << "Size" << endl;
	heapify(arrSort, n);
	swap(&arrSort[0], &arrSort[n-1]);

	cout << "**************" << endl;

	heapify(arrSort, n-1);
	//cout << arrSort[0] << " Should be 100" << endl;
	swap(&arrSort[0], &arrSort[n-2]);
	*/

	// Repeatedly heapify, then the highest priority should appear 
	// at the front of the array. Then continuously swap and lessen
	// the section that is heapified, resulting in a sorted array.
	/*int counter = (n-1);
	for (int i = n; i >= 1; i--){
		heapify(arrSort, i);
		cout << arrSort[0] << " <<-Top of heap" << endl;
		swap(&arrSort[0], &arrSort[counter]);
		counter--;
	} */



/*
	// If leftChild or rightChild is within boundaries of heap
	if (leftChild < n || rightChild < n){

		// If one of the two children are greater than the parent.
		if(arrSort[leftChild] > arrSort[larger] || arrSort[rightChild] > arrSort[larger]){

			// If it is leftChild and is within boundary,
			if (arrSort[leftChild] > arrSort[larger] && leftChild < n){
			    larger = leftChild;
			}

			// If right child is larger than the larger (left or parent)
			if (arrSort[rightChild] > arrSort[larger] && rightChild < n){
			    larger = rightChild;
			}

		}

		// Otherwise, the parent is still larger
		else{
			larger = parent;
		}
	}

	// Otherwise, the parent is still larger
	else{
		larger = parent;
	}
*/