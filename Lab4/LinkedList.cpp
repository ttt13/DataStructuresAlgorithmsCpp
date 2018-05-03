#include "LinkedList.h"
 
// Default constructor
// POST: creates an empty list
LinkedList::LinkedList()
{
       head = tail = NULL;
       n = 0;
}
 
// Copy constructor
// PARAM: list = list to be copied
// POST: creates a copy of list
LinkedList::LinkedList(const LinkedList & list)
{
       copyList(list);
}
 
// Overloaded assignment operator
// PARAM: list = list to be copied
// POST: assigns the values stored in list to the calling object,
//       returns a reference to the calling object,
//       deallocates memory associated with original calling object
LinkedList & LinkedList::operator=(const LinkedList & list)
{
       if (this != &list) {
              removeAll();
              copyList(list);
       }
       return *this;
}
 
// Destructor
// POST: deallocates dynamic memory associated with calling object
LinkedList::~LinkedList()
{
       removeAll();
}
 
// PARAM: val = value to be inserted
// POST: val is inserted at the head of the list
void LinkedList::insertHead(int val)
{
       // List is empty
       if (tail == NULL) {
              head = new Node(val, NULL, head);
              tail = head;
       }
       else {
              head->previous = new Node(val, NULL, head);
              head = head->previous;
       }
       n++;
}
 
// PARAM: val = value to be inserted
// POST: val is inserted at the tail of the list
void LinkedList::insertTail(int val)
{
       // List is empty
       if (tail == NULL) {
              tail = new Node(val);
              head = tail;
       }
       else {
              tail->next = new Node(val, tail, NULL);
              tail = tail->next;
       }
       n++;
}
 
// PRE:
// PARAM: x specifies the value to be removed from the list
// POST: the calling object will not contain any values, x
//       returns the number of nodes removed from the list
int LinkedList::remove(int x)
{
       int count = 0;
       Node* temp = head;
       while (temp->next != NULL) {
              // Splice out target node
              if (temp->next->data == x) {
                     Node* target = temp->next;
                     temp->next = temp->next->next;
                     delete target;
                     count++;
              }
              temp = temp->next;
       }
 
       return count;
}
 
// POST: prints contents of calling object from head to tail
void LinkedList::printForwards() const
{
       Node* temp = head;
       while (temp != NULL) {
              cout << temp->data << endl;
              temp = temp->next;
       }
}
 
// POST: prints contents of calling object from tail to head
void LinkedList::printBackwards() const
{
       Node* temp = tail;
       while (temp != NULL) {
              cout << temp->data << endl;
              temp = temp->previous;
       }
}
 
// POST: returns number of values stored in list
int LinkedList::size() const
{
       return n;
}
 
// POST: returns true iff list is empty
bool LinkedList::empty() const
{
       return head == NULL && tail == NULL;
}
 
// Helper function for copy constructor and overloaded assignment operator
// PRE: calling object is empty (or memory leak results)
// PARAM: list = list to be copied
// POST: copies list into calling object
void LinkedList::copyList(const LinkedList & list)
{
       if (list.head != NULL) {
              // Copy front
              Node* original = list.head;
              head = new Node(original->data);
              tail = head;
              original = original->next;
              Node* temp = head;
 
              // Copy rest of list
              while (original != NULL) {
                     temp->next = new Node(original->data, temp, NULL);
                     original = original->next;
                     temp = temp->next;
                     tail = temp;
              }
       }
       n = list.n;
}
 
// Helper function for overloaded assignment operator
// POST: removes all nodes from calling object, deallocating memory
void LinkedList::removeAll()
{
       Node* temp = head;
       while (head != NULL) {
              head = temp->next;
              delete temp;
              temp = head;
       }
       n = 0;
       head = tail = NULL;
}