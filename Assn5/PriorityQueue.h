// PriorityQueue.h
// Assignment 5
// CMPT 225
// Peter Tran

#include <stdexcept>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue
{
public:

	// Default constructor
	PriorityQueue();

	// Constructor
	PriorityQueue(T* copyArr, int n);

	// Copy Constructor
	PriorityQueue(const PriorityQueue & PQ);

	// Destructor
	~PriorityQueue();

	// Overloaded assignment operator - Creates deep copies
	PriorityQueue & operator=(const PriorityQueue & PQ);

	// PARAM: Item to be inserted.
	// POST: Inserts item into end of array, calls heapify to maintain
	//		 heap properties.
	void insert(T n);

	// PRE: The array must not be empty.
	// POST: Removes highest priority item (Located at arr[0]).
	//		 Then bubbles down to maintain heap properties.
	T remove();

	// PRE: Nonempty array.
	// POST: Returns item with highest priority.
	T peek();

	// POST: Returns number of current items in the heap.
	int size();

	// POST: Returns the maximum size of the heap.
	int maxSize();

	// POST: True if queue is empty. False otherwise.
	bool empty();

	// PARAM: Array to be sorted, size of the array.
	// POST: Sorts the array using heapsort.
	void sort(T* arrSort, int n);

	// POST: For looking at the private array.
	T* contents();

private:

	// Array of variables of the template type.
	T* arr;

	// Maximum size of the array.
	int max;

	// Number of current items in the array.
	int current;

	// Helper method
	// USAGE: Constructor and sort methods.
	// PARAM: Array to be heapified, size of array, index to begin from
	// POST: Satisfies heap properties for the array by bubbling down
	void heapify(T* arrSort, int n, int bubble);

	// Helper method
	// USAGE: Constructor, overloaded assignment operator
	// PARAM: PriorityQueue to be deep copied.
	// POST: Deep copies PriorityQueues. 
	void deepcopy(const PriorityQueue & PQ);

	// Helper method
	// USAGE: Destructor, overloaded assignment operator
	// POST: Destroys PriorityQueue
	void destroyPQ();

	// Helper method
	// USAGE: Insert, remove, sort, heapify
	// PARAM: Items to be swapped.
	// POST: Swaps items.
	void swap(T *x, T *y);

	// Helper method
	// USAGE: Heapify
	// PARAM: Array, three nodes to be compared, size of array.
	// POST: Returns index of highest priority element of the three.
	int compare(T* arrSort, int leftChild, int rightChild, int parent, int n);

};

// --------------- IMPLEMENTATION --------------- //

// Default constructor
template <class T>
PriorityQueue<T>::PriorityQueue()
{
	// Default size 4, current 0.
	arr = new T[4];
	max = 4;
	current = 0;
}

// Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(T* copyArr, int n)
{
	// Array size n.
	arr = new T[n];

	// Move everything over.
	for(int i = 0; i < n; i++){
		arr[i] = copyArr[i];
	}

	// Current and max should be the same.
	current = n;
	max = n;

	// Maintain heap properties.
	int size = n / 2 - 1;

	while (size >= 0){

		// Bubble down
		heapify(arr, n, size);
		size--;
	}

}

// Copy constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue & PQ)
{
	deepcopy(PQ);
}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	destroyPQ();
}

// Overloaded assignment operator - creates deep copies.
template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue & PQ)
{
	// Make sure it doesn't copy itself.
	if(this != &PQ){
		destroyPQ();
		deepcopy(PQ);
	}

	return *this;
}

// PARAM: Item to be inserted.
// POST: Inserts item into end of array, calls heapify to maintain
//		 heap properties.
template <class T>
void PriorityQueue<T>::insert(T n)
{
	// Create larger array if necessary.
	if(current == max){

		// Make temp array, store items there
		T *temp = new T [current];

		for(int i = 0; i < current; i++){
			temp[i] = arr[i];
		}

		max *= 2;

		// Make more space.
		arr = new T[max];

		// Move items back to original.
		for(int j = 0; j < current; j++){
			arr[j] = temp[j];
		}

		delete[] temp;
	}

	// Insert into leftmost available space.
	arr[current] = n;

	// Bubble up process.
	int parent = (current - 1)/2;
	int bubble = current;
	int temporary;

	// If item has more priority, swap it with its parent.
	// This happens until either it is the root, or its parent has
	// more priority than it does.
	while(arr[parent] < arr[bubble] && bubble > 0){

		swap(&arr[parent], &arr[bubble]);

		// Continue to bubble up
		bubble = parent;
		parent = (parent - 1)/2;
	}

	//Increment current
	current++;
}

// PRE: The array must not be empty.
// POST: Removes highest priority item (Located at arr[0]).
//		 Then bubbles down to maintain heap properties.
template <class T>
T PriorityQueue<T>::remove()
{
	// Make sure the PriorityQueue isn't empty.
	if (current == 0){
		throw std::runtime_error("Remove error: PriorityQueue is empty.");
	}

	// For returning the highest priority item.
	T retValue = arr[0];

	// Replace highest priority item with whatever is at the end of
	// the array.
	arr[0] = arr[current - 1];

	// Bubble down process
	int traverse = 0;
	int rightChild = 2*traverse + 1;
	int leftChild = 2*traverse + 2;

	current--;

	// As long as the item's children have more priority, swap it down
	// the PriorityQueue.
	while( (arr[traverse] < arr[rightChild] || arr[traverse] < arr[leftChild] ) && (rightChild < current || leftChild < current) ){
			
		if(arr[rightChild] > arr[leftChild]){
		
			swap(&arr[traverse], &arr[rightChild]);

			// traverse down 
			traverse = rightChild;
		}

		else if(arr[leftChild] >= arr[rightChild]){
			
			swap(&arr[traverse], &arr[leftChild]);
			// traverse down
			traverse = leftChild;
		}

		// Find the next node's children.
		rightChild = 2 * traverse + 1;
		leftChild = 2 * traverse + 2;
	}

	return retValue;

}

// PRE: Nonempty array.
// POST: Returns item with highest priority.
template <class T>
T PriorityQueue<T>::peek()
{

	// Make sure there is something to look at. 
	if (current == 0){
		throw std::runtime_error("Peek error: PriorityQueue is empty.");
	}

	// Arr[0] should be the highest priority item.
	return arr[0];
}

// POST: Returns number of current items in the heap.
template <class T>
int PriorityQueue<T>::size()
{
	return current;
}

// POST: Returns the maximum size of the heap.
template <class T>
int PriorityQueue<T>::maxSize()
{
	return max;
}

// POST: True if queue is empty. False otherwise.
template <class T>
bool PriorityQueue<T>::empty()
{
	return (current == 0);
}

// PARAM: Array to be sorted, size of the array.
// POST: Sorts the array using heapsort.
template <class T>
void PriorityQueue<T>::sort(T* arrSort, int n)
{ 
	// Because we don't have to look at leaves.
	int intLeaves = n/2 - 1;

	// For swap and heapifying smaller heaps.
    int counter = n - 1;
	
  	while (intLeaves >= 0){
    	heapify(arr, n, intLeaves);

    	intLeaves--;
    }
    // One by one extract an element from heap

    while (counter >= 0){

    	// Swap the highest priority item to the end of the list
    	swap(&arr[0], &arr[counter]);
 
        // Recursive call of heapify on smaller heap.
        heapify(arr, counter, 0);

        // Decrement
        counter--;
    }
}

// POST: For looking at the private array.
template <class T>
T* PriorityQueue<T>::contents()
{
	return arr;
}

// Helper method
// USAGE: Constructor, overloaded assignment operator
// PARAM: PriorityQueue to be deep copied.
// POST: Deep copies PriorityQueues. 
template <class T>
//Helper method
void PriorityQueue<T>::deepcopy(const PriorityQueue & PQ)
{
	max = PQ.max;
	current = PQ.current;

	arr = new T[max];

	// Move everything over.
	for(int i = 0; i < max; i++){
		arr[i] = PQ.arr[i];
	}
}

// Helper method
// USAGE: Destructor, overloaded assignment operator
// POST: Destroys PriorityQueue
template <class T>
void PriorityQueue<T>::destroyPQ()
{
	max = 0; 
	current = 0;
	delete[] arr;
}

// Helper method
// USAGE: Insert, remove, sort, heapify
// PARAM: Items to be swapped.
// POST: Swaps items.
template <class T>
void PriorityQueue<T>::swap(T *x, T *y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

// Helper method
// USAGE: Heapify
// PARAM: Array, three nodes to be compared, size of array.
// POST: Returns index of highest priority element of the three.
template<class T>
int PriorityQueue<T>::compare(T* arrSort, int leftChild, int rightChild, int parent, int n)
{
	int largestChild = parent;

// If leftChild or rightChild is within boundaries of heap
	if (leftChild < n || rightChild < n){

		// If one of the two children are greater than the parent.
		if(arrSort[leftChild] > arrSort[largestChild] || arrSort[rightChild] > arrSort[largestChild]){

			// If it is leftChild and is within boundary,
			if (arrSort[leftChild] > arrSort[largestChild] && leftChild < n){
			    largestChild = leftChild;
			}

			// If right child is larger than the larger (left or parent)
			if (arrSort[rightChild] > arrSort[largestChild] && rightChild < n){
			    largestChild = rightChild;
			}

			// Return index of highest priority
			return largestChild;
		}
	}

// Return index of highest priority
return largestChild;
}


// Helper method
// USAGE: Constructor and sort methods.
// PARAM: Array to be heapified, size of array.
// POST: Satisfies heap properties for the array.
template <class T>
void PriorityQueue<T>::heapify(T* arrSort, int n, int bubble)
{

	int leftChild = 2 * bubble + 1;
	int rightChild = 2 * bubble + 2;

	// Parent of the two children above
	int parent = bubble;

	// Largest of the parent and two children. 
	// Assumed to be the parent unless otherwise.
	int larger = bubble;

	// Check which of the three have most priority
	int largerChild = compare(arrSort, leftChild, rightChild, bubble, n);

	// If largest has changed, subtrees may be affected. Swap and reheapify.
	if (arrSort[largerChild] > arrSort[parent] && largerChild != parent){

	    swap(&arrSort[bubble], &arrSort[largerChild]);

	    // Recursive heapify on subtree.
	    heapify(arrSort, n, largerChild);
	}

}

