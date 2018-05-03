// Assignment 2
// Peter Tran
// 7 October 2017
#include <cstdlib>
#include <stdexcept>

// --------------- NODES ---------------- //
template <class T>
class Node{
public:
	// Default constructor
	Node();

	// Copy constructor
	Node(T value);

	// Destructor
	~Node();

	T data;
	Node<T>* next;
	Node<T>* prev;
};

// Default node constructor
template <class T>
Node<T>::Node()
{
	data;
	next = NULL;
	prev = NULL;
}

// Copy constructor 
template <class T>
Node<T>::Node(T value)
{
	data = value;
	next = NULL;
	prev = NULL; 
}

// Destructor
template <class T>
Node<T>::~Node()
{
}
// --------------- NODES --------------- //

// --------------- DEQUES --------------- //
template <class T>
class Deque{
public:

	// Default constructor
	Deque();

	// Deep copy constructor
	Deque(const Deque & De);

	// Destructor
	~Deque();

	// Overloaded Assignment Operator - For deep copies.
	Deque & operator=(const Deque & De);

	// PRE: Parameter is of the same type as the deque.
	// PARAM: Element to be inserted
	// POST: Inserts element into the head of the deque.
	void insertFront(T value);

	// PRE: Parameter is of the same type as the deque.
	// PARAM: ELement to be inserted
	// POST: Inserts element into the tail of the deque.
	void insertBack(T value);

	// PRE: There must be at least one element.
	// PARAM: 
	// POST: Removes the element that is at the head of the deque.
	T removeFront();

	// PRE: There must be at least one element.
	// PARAM:
	// POST: Removes the element that is at the tail of the deque.
	T removeBack();

	// PRE: There must be at least one element.
	// PARAM:
	// POST: Returns the element at the head of the deque.
	T peekFront();

	// PRE: There must be at least one element.
	// PARAM:
	// POST: Returns the element at the tail of the deque.
	T peekBack();

	// PRE:
	// PARAM:
	// POST: Returns true (1) if the deque is empty, false (0) otherwise
	bool empty();

	// PRE:
	// PARAM:
	// POST: Returns the length of the deque.
	int size();
	
private:
	//Front of the deque
	Node<T>* head;

	//Back of the deque
	Node<T>* tail;

	//Keep track of size
	int length;

	// Helper method - makes deep copies.
	void copyDeque(const Deque & De);

	// Helper method - deletes deques.
	void deleteDeque();
};

// Default Constructor
template <class T>
Deque<T>::Deque()
{
	head = NULL;
	tail = NULL;
	length = 0;
}

// Copy Constructor - Makes deep copies.
template <class T>
Deque<T>::Deque(const Deque & De)
{
	// Call helper method - Makes deep copy
	copyDeque(De);
}

template <class T>
Deque<T>::~Deque()
{
	// Call helper method. Deletes deque.
	deleteDeque();
}

// Overloaded Assignment Operator - For deep copies.
template <class T>
Deque<T>& Deque<T>::operator=(const Deque & De)
{
	// Don't make a copy of itself.
	if(this != & De){
		deleteDeque();
		copyDeque(De);
	}

	return *this;
}

// PRE: Parameter is of the same type as the deque.
// PARAM: Element to be inserted
// POST: Inserts element into the head of the deque.
template <class T>
void Deque<T>::insertFront(T value)
{
	// Create a new node.
	Node<T>* newNode = new Node<T>(value);

	// If deque is empty, tail and head point to the same node.
	if(tail == NULL || length == 0){
		tail = newNode;
	}

	if(head != NULL){
		newNode->next = head;
		head->prev = newNode;
	}

	// Change the new node to be the head.
	head = newNode;
	length++;
}

// PRE: Parameter is of the same type as the deque.
// PARAM: ELement to be inserted
// POST: Inserts element into the tail of the deque.
template <class T>
void Deque<T>::insertBack(T value)
{
	// Create a new node.
	Node<T>* newNode = new Node<T>(value);

	// Attach the tail (and the rest of the deque) to prev of the new node.
	if(tail != NULL){
		tail->next = newNode;
		newNode->prev = tail;
	}

	// If the deque is empty, head and tail point to the same node.
	if(head == NULL){
		head = newNode;
	}

	// Make sure the new node's next is NULL.
	newNode->next = NULL;

	// Set tail to be the new node.
	tail = newNode;
	length++;
}

// PRE: There must be at least one element.
// PARAM: 
// POST: Removes the element that is at the head of the deque.
template <class T>
T Deque<T>::removeFront()
{

	// Make sure there is something to remove.
	if (length == 0){
		throw std::runtime_error("Deque is empty.");
	}

	// For returning the data, as we will delete the head node later.
	T ret = head->data;
	Node<T>* temp = head;

	// Move the head if you can
	if(head->next != NULL){
		head = head->next;
		head->prev = NULL;
	}

	// If deque is length 1, head = NULL.
	else{
		head = NULL;
	}

	// Delete the head
	delete temp;
	length--;

	return ret;
}

// PRE: There must be at least one element.
// PARAM: 
// POST: Removes the element that is at the back of the deque.
template <class T>
T Deque<T>::removeBack()
{
	// Make sure there's something to remove.
	if(length == 0){
		throw std::runtime_error("Deque is empty.");
	}

	// For returning data, as we will delete tail later.
	T ret = tail->data;
	Node<T>* temp = tail;

	// Move the tail if possible.
	if(tail->prev != NULL){
		tail = tail->prev;
		tail->next = NULL;
	}

	// If deque is length 1, set tail to NULL.
	else{
		tail = NULL;
	}

	// Delete the original tail.
	delete temp;
	length--;
	return ret;
}

// PRE: There must be at least one element.
// PARAM:
// POST: Returns the element at the head of the deque.
template <class T>
T Deque<T>::peekFront()
{
	// Make sure there's something to peek at
	if (length == 0){
		throw std::runtime_error("peekFront Error: Deque is empty. Nothing to peek at.");
	}

	// Return front of deque if it exists.
	return head->data;
}

// PRE: There must be at least one element.
// PARAM:
// POST: Returns the element at the tail of the deque.
template <class T>
T Deque<T>::peekBack()
{
	// Make sure there's something to peek at.
	if (length == 0){
		throw std::runtime_error("peekBack Error: Deque is empty. Nothing to peek at.");
	}
	
	// Return back of deque if it exists.
	return tail->data;
}

// PRE:
// PARAM:
// POST: Returns true (1) if the deque is empty, false (0) otherwise
template <class T>
bool Deque<T>::empty()
{
	if (head == NULL){
		return true;
	}
	return false;
}

// PRE:
// PARAM:
// POST: Returns the length of the deque.
template <class T>
int Deque<T>::size()
{
	return length;
}

// Helper Method
// POST: Deletes all nodes in the deque.
template <class T>
void Deque<T>::deleteDeque()
{
	Node<T>* temp = head;

	// Go through the deque , deleting each node.
	while(head != NULL){
		head = head->next;
		delete temp;
		temp = head;
	}

	head = NULL;
	tail = NULL;
}

// Helper method
// PARAM: The deque that will be copied from.
// POST: Returns the deep copied deque.
template <class T>
void Deque<T>::copyDeque(const Deque & De)
{
	head = NULL;

	if (De.head != NULL){
		// Create the head.
		head = new Node<T>(De.head->data);
		Node<T>* original = De.head->next;
		Node<T>* duplicate = head;

		// Go through the deque, copying the same data over.
		while(original != NULL){
			Node<T>* newNode = new Node<T>(original->data);
			duplicate->next = newNode;
			// Make sure prev points backwards to ensure doubly linked list.
			duplicate->prev = duplicate;
			duplicate = duplicate->next;
			original = original->next;
		}
		tail = duplicate;
		length = De.length;
	}
}