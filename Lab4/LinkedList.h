#pragma once
 
#include<stdexcept>
#include <iostream>
using namespace std;
 
class Node
{
public:
       int data;
       Node* previous;
       Node* next;
       Node(int val, Node* nd1, Node* nd2) : data(val), previous(nd1), next(nd2) {};
       Node(int val) : data(val), previous(NULL), next(NULL) {};
};
 
class LinkedList
{
public:
       LinkedList();
       LinkedList(const LinkedList & dq);
       LinkedList & operator=(const LinkedList & dq);
       ~LinkedList();
 
       void insertHead(int val);
       void insertTail(int val);
 
       int remove(int x);
 
       void printForwards() const;
       void printBackwards() const;
 
 
       int size() const;
       bool empty() const;
 
private:
       int n;
       Node* head;
       Node* tail;
 
       void copyList(const LinkedList & list);
       void removeAll();
};