#include <iostream>
#include "Deque.h"

using namespace std;

int main( void )
{



/*
       Deque<int> dq1;
       cout << dq1.empty() << " - 1" << endl;
 
       dq1.insertFront(42);
       dq1.insertBack(216);
 
       cout << dq1.peekFront() << " - 42" << endl;
       cout << dq1.peekBack() << " - 216" << endl;
       cout << dq1.size() << " - 2" << endl;
 
       Deque<int> dq2(dq1);
       Deque<int> dq3;
       dq3 = dq1;
 
       cout << dq1.removeFront() << " - 42" << endl;
       cout << dq1.size() << " - 1" << endl;
       cout << dq1.removeBack() << " - 216" << endl;
 
       cout << dq2.peekFront() << " - 42" << endl;
       cout << dq2.peekBack() << " - 216" << endl;
 
       cout << dq3.peekFront() << " - 42" << endl;
       cout << dq3.peekBack() << " - 216" << endl;
 
       return 0;
       */

Deque<int> test;


cout << "Should be empty: " << test.empty() << endl;
for(int i = 0; i < 5; i++){
	test.insertFront(i);
	cout << "Inserted " << i << " into test. Size is now: " << test.size() << endl;
}
cout << "Should be not empty: " << test.empty() << endl;

cout << "Peek front should be 4: " << test.peekFront() << endl;
cout << "Peek back should be 0: " << test.peekBack() << endl << endl;

Deque<int> copyConstruct(test); 
test.removeFront();
test.removeBack();

cout << "Peek front should be 3: " << test.peekFront() << endl;
cout << "Peek back should be 1: " << test.peekBack() << endl;


for(int x = 0; x < 3; x++){
	test.removeFront();
}
cout << "Size is now: " << test.size() << endl;
cout << "empty again: " << test.empty() << endl;

cout << "--- Copy and Overload tests ---" << endl << endl;

cout << "Peek front should be 4: " << copyConstruct.peekFront() << endl;
cout << "Peek back should be 0: " << copyConstruct.peekBack() << endl << endl;
cout << "Size Should be 5: " << copyConstruct.size() << endl;

cout << "...using overload and destroying copy..." << endl << endl;

Deque<int> overloaded = copyConstruct;
//delete test;

cout << "Peek front should be 4: " << overloaded.peekFront() << endl;
cout << "Peek back should be 0: " << overloaded.peekBack() << endl << endl;
cout << "Size Should be 5: " << overloaded.size() << endl;

cout << "--- Testing with strings ---" << endl << endl;

Deque<string> test2;
cout << "Should be empty: " << test2.empty() << endl;

test2.insertFront("Peter");
test2.insertFront("Tran");
test2.insertBack("SFU");
cout << "Size should be 3: " << test2.size() << endl;
cout << "Tran: " << test2.peekFront() << endl;
cout << "SFU: " << test2.peekBack() << endl;
cout << "...Removing Tran, SFU..." << endl;
test2.removeFront();
test2.removeBack();
cout << "Size should be 1: " << test2.size() << endl;
cout << "peekFront and Back should be Peter: " << test2.peekFront() << test2.peekBack() << endl;

return 0; 
//test.peekFront();
/*test.peekBack();
test.removeFront();
test.removeBack();
*/
return 0;
}