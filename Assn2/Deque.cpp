#include <cstdlib>
#include <stdexcept>
#include "Deque.h"

// Move this back into the .h file //////////////
/*template <class T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
	prev = NULL;
}

Node<T>::Node(T value)
{
	data = value;
	next = NULL;
	prev = NULL; 
}

Node<T>::~Node()
{
}*/

/////////////////////////////////////////////////////
template <class T>
Deque<T>::Deque()
{
	head = NULL;
	tail = NULL;
	length = 0;
}

template <class T>
Deque<T>::Deque(const Deque & De)
{
	copyDeque(De);
}

template <class T>
Deque<T>::~Deque()
{
	deleteDeque();
}

template <class T>
Deque<T>& Deque<T>::operator=(const Deque & De)
{
	if(this != & De){
		deleteDeque();
		copyDeque(De);
	}

	return *this;
}

template <class T>
void Deque<T>::insertFront(T value)
{
	T* newNode = new T(value);
	if(tail == NULL){
		tail = newNode;
	}

	if(head != NULL){
		newNode->next = head;
		head->prev = newNode;
	}

	head = newNode;
	length++;
}

template <class T>
void Deque<T>::insertBack(T value)
{
	T* newNode = new T(value);
	if(tail != NULL){
		tail->next = newNode;
		newNode->prev = tail;
	}

	if(head == NULL){
		head = newNode;
	}

	newNode->next = NULL;
	tail = newNode;
	length++;
}

template <class T>
T Deque<T>::removeFront()
{
	// Add throw later
	if (length == 0){
		throw std::runtime_error("Deque is empty.");
	}

	T* temp = head;

	if(head->next){
		head = head->next;
	}

	if(head->next == NULL){
		head = NULL;
		tail = NULL;
	}
	delete temp;
	length--;
}

template <class T>
T Deque<T>::removeBack()
{
	// Add throw
	if(length == 0){
		throw std::runtime_error("Deque is empty.");
	}

	T* temp = tail;

	if(tail->prev != NULL){
		tail = tail->prev;
	}
	if(tail->prev == NULL){
		head = NULL;
		tail = NULL;
	}

	delete temp;
	length--;
}

template <class T>
T Deque<T>::peekFront()
{
	// Add throw
	if (length == 0){
		throw std::runtime_error("Deque is empty. Nothing to peek at.");
	}
	return head->data;
}

template <class T>
T Deque<T>::peekBack()
{
	// Add throw
	if (length == 0){
		throw std::runtime_error("Deque is empty. Nothing to peek at.");
	}
	return tail->data;
}

template <class T>
bool Deque<T>::empty()
{
	if (head == NULL){
		return true;
	}
	//if (length == 0){
	//	return true;
	//}
	return false;
}

template <class T>
int Deque<T>::size()
{
	return length;
}

template <class T>
void Deque<T>::deleteDeque()
{
	T* temp = head;

	while(head != NULL){
		head = head->next;
		delete temp;
		temp = head;
	}

	head = NULL;
	tail = NULL;
}

template <class T>
void Deque<T>::copyDeque(const Deque & De)
{
	head = NULL;

	if (De.head != NULL){
		head = new T(De.head->data);
		T* original = De.head->next;
		T* duplicate = head;

		while(original != NULL){
			T* newNode = new T(original->data);
			duplicate->next = newNode;
			duplicate->prev = duplicate;
			duplicate = duplicate->next;
			original = original->next;
		}
		tail = duplicate;
		length = De.length;
	}
}