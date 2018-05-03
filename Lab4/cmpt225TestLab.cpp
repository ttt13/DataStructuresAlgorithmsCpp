// cmpt225testLab.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;
 
void removeTest();
void removeTest1();
void removeTest2();
void removeTest3();
void removeTest4();
void removeTest5();
void removeTest6();

int main()
{
       //removeTest();
       removeTest6();
       return 0;
}
 
void removeTest()
{
       LinkedList list;
       int arr[] = { 1,3,5,7,3,5,7,9 };
       int n = 8;
       for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }
 
       cout << "remove 3s: " << list.remove(3) << endl;
       list.printForwards();
}

void removeTest1() // Wrong size
{
       LinkedList list;
       int arr[] = {1,2,3};
       int n = 3;
       for (int i = 0; i < n; i++){
              list.insertTail(arr[i]);
       }

       for (int j = 0; j < n; j++){
              list.remove(j);
       }

       cout << list.size() << endl;

}

void removeTest2() // Doesn't remove head
{
       LinkedList list;
       int arr[] = {1,2};
       int n = 2;
       for (int i = 0; i < n; i++){
              list.insertTail(arr[i]);
       }

       list.remove(1);

       list.printForwards();

}

void removeTest3() // Seg faults on trying to remove the tail
{
       LinkedList list;
       int arr[] = {1,2};
       int n = 2;
       for (int i = 0; i < n; i++){
              list.insertTail(arr[i]);
       }

       list.remove(2);

       list.printForwards();
}

void removeTest4() // Doesn't remove the tail
{
       LinkedList list;
       int arr[] = { 1,2,3,4,5,6,7,8};
       int n = 8;
       for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

       for (int j = 1; j < n; j++){
              list.remove(j);
       }

       list.printForwards();
}

void removeTest5() // It's supposed to remove both 2's (Consecutive numbers)
{
       LinkedList list;
       int arr[] = { 1,2,2,1};
       int n = 4;
       for (int i = 0; i < n; ++i) {
              list.insertTail(arr[i]);
       }

       list.remove(2);
       //cout << list.remove(2) << endl;

       list.printForwards();
}

void removeTest6() // Seg faults on an empty list
{
       LinkedList list;
       list.remove(1);
}