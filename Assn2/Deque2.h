# pragma once
# include <stdexcept>
# include <vector>
# include <cstdlib>
# include <iostream>
using namespace std;


template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
	
	// constructor

	Node (T value)
	{
		data = value;
		next = NULL;
		prev = NULL;
	}
};

template <class T>
class Deque
{
private:
	int items;
	Node<T>* front;
	Node<T>* back;
	
public:
	// constructor
	// creates an empty Deque
	Deque ();
	
	// copy constructor
	// creates deep copy of parameter
	Deque (const Deque &dq);
	
	// destructor
	// deallocate memory allocated for Deque
	~Deque ();
	
	// overloaded assignment operator
	// overloads the assignment operator for Deque
	// deallocate any memory associated w/ original contents of calling object
	// deep copies its paramter into calling object
	// if calling object is the same as paramter, do not copy
	// return a reference to calling object
	Deque &operator= (const Deque &dq);
	
	// insert parameter at front of Deque
	void insertFront (T value);
	
	// insert paramter at back of Deque
	void insertBack (T value);
	
	// if Deque is empty, throw a runtime_error
	// remove and return front item
	T removeFront ();
	
	// if Deque is empty, throw a runtime_error
	// remove and return back item
	T removeBack ();
	
	// if Deque is empty, throw a runtime_error
	// return front item
	T peekFront ();
	
	// if Deque is empty, throw a runtime_error
	// return back item
	T peekBack ();
	
	// if Deque is empty, return true
	// return false
	bool empty ();
	
	// return number of items stored in Deque
	int size ();
	
	// creates a deep copy of the parameter object
	void deepCopy (const Deque &dq);
	// delete the Deque object
	void deleteObject ();
};

// Deque implementation

template <class T>
Deque<T>:: Deque ()
{
	front = NULL;
	back = NULL;
	items = 0;
}

template <class T>
Deque<T>:: Deque (const Deque &dq)
{
	deepCopy (dq);
}

template <class T>
Deque<T>:: ~Deque ()
{
	deleteObject ();
}

template <class T>
Deque<T> &Deque<T>:: operator= (const Deque &dq)
{
	if (this != &dq)
	{
		deleteObject ();
		deepCopy (dq);
	}
	
	return *this;
}

template <class T>
void Deque<T>:: insertFront (T value)
{
	// create new Node object with data = value
	Node<T>* temp = new Node<T> (value);
	
	// newly introduced Node's next ptr points to current front
	temp->next = front;
	
	// newly introduced Node's prev ptr points to NULL (for safety)
	temp->prev = NULL;
	// if Deque was not empty, current front's previous ptr points to newly introduced Node
	if (items > 0)
	{
		front->prev = temp;
	}
	
	// if Deque was empty, newly inserted Node is also the back
	else
	{
		back = temp;
	}
	
	// newly introduced Node is now the front
	front = temp;
	
	// increment items
	items++;
}
template <class T>
void Deque<T>:: insertBack (T value)
{
	// create new Node object with data = value
	Node<T>* temp = new Node<T> (value);
	
	// newly introduced Node's prev ptr points to current back
	temp->prev = back;
	
	// newly introduced Node's next ptr points to NULL (for safety)
	temp->next = NULL;
	
	// if Deque was not empty, current back's next ptr points to newly introduced Node
	if (items > 0)
	{
		back->next = temp;
	}
	
	// if Deque was empty, newly inserted Node is also the front
	else
	{
		front = temp;
	}
	
	// newly introduced Node is now the back
	back = temp;
	
	// increment items
	items++;
}
template <class T>
T Deque<T>:: removeFront ()
{
	try
	{	
		// exception: if Deque is already empty
		if (items <= 0)
		{
			throw -1;
		}
		
		// store to be removed Node's memory address
		Node<T>* removedPtr = front;

		// store to be removed Node's data
		T removedValue = front->data;

		// front is now the next Node
		front = front->next;

		// decrement items
		items--;

		// if Deque became empty, set front and back to NULL
		if (items <= 0)
		{
			front = NULL;
			back = NULL;
		}
		
		// if only one item remains, back is also the front
		else if (items == 1)
		{
			back = front;
		}

		// free memory at original front's memory address
		delete removedPtr;

		// return the data of the removed Node
		return removedValue;
	}
	
	// output error if one is caught
	catch (int x)
	{
		cout << "runtime_error: no items in Deque" << endl;
	}
}

template <class T>
T Deque<T>:: removeBack ()
{
	try
	{	
		// exception: if Deque is already empty
		if (items <= 0)
		{
			throw -1;
		}
		
		// store to be removed Node's memory address
		Node<T>* removedPtr = back;
		// store to be removed Node's data
		T removedValue = back->data;
		
		// back is now the previous Node
		back = back->prev;
		
		// decrement items
		items--;
		
		// if Deque became empty, set front and back to NULL
		if (items <= 0)
		{
			front = NULL;
			back = NULL;
		}
		
		// if only one item remains, front is also the back
		else if (items == 1)
		{
			front = back;
		}
		
		// free memory at original back's memory address
		delete removedPtr;
		
		// return the data of the removed Node
		return removedValue;
	}
	
	// output error if one is caught
	catch (int x)
	{
		cout << "runtime_error: no items in Deque" << endl;
	}
}

template <class T>
T Deque<T>:: peekFront ()
{
	try
	{	
		// exception: if Deque is already empty
		if (items <= 0)
		{
			throw -1;
		}
		
		if (items > 0)
		{
			return front->data;
		}
	}
	
	// output error if one is caught
	catch (int x)
	{
		cout << "runtime_error: no items in Deque" << endl;
	}
}

template <class T>
T Deque<T>:: peekBack ()
{
	try
	{	
		// exception: if Deque is already empty
		if (items <= 0)
		{
			throw -1;
		}
		
		if (items > 0)
		{
			return back->data;
		}
	}
	
	// output error if one is caught
	catch (int x)
	{
		cout << "runtime_error: no items in Deque" << endl;
	}
}

template <class T>
bool Deque<T>:: empty ()
{
	if (items <= 0)
	{
		return true;
	}
	
	return false;
}

template <class T>
int Deque<T>:: size ()
{
	return items;
}

template <class T>
void Deque<T>:: deepCopy (const Deque &dq)
{
	// default Deque values
	front = NULL;
	back = NULL;
	items = 0;
	
	// if parameter Deque is not empty...
	if (dq.items > 0)
	{
		// make a Node pointer for traversing the Deque, prevents changes to dq
		// make a Node pointer to create new items in the Deque
		// first item has no items before it, prev = NULL
		// increment items
		Node<T>* temp = dq.front;
		Node<T>* newDequeCreator = new Node<T> (temp->data);
		newDequeCreator->prev = NULL;
		items++;
	
		// make the front point to the first item
		// move temp to the next item
		front = newDequeCreator;
		temp = temp->next;
	
		// while there are still items in Deque...
		while (temp != NULL)
		{
			// create a new Node with the same value as the temp Deque
			// current memory location of newDequeCreator is the prev memory location of the next
			newDequeCreator->next = new Node<T> (temp->data);
			newDequeCreator->next->prev = newDequeCreator;
		
			// increment size
			items++;
		
			// iterate both Deques
			temp = temp->next;
			newDequeCreator = newDequeCreator->next;
		}
	
		// last inserted item is the back
		back = newDequeCreator;
	}
}

template <class T>
void Deque<T>:: deleteObject ()
{
	// temp variable that also points to the front
	Node<T>* temp = front;
	
	// traverse the list
	// delete Node object on each iteration
	while (temp != NULL)
	{
		temp = front->next; // move temp forward down the list
		delete front; // deallocate the Node object that front is pointing to
		front = temp; // move front forward down the list
		}
	
	front = NULL;
	back = NULL;
	items = 0;
}