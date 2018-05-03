#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;
 
class BST
{
public:
       // Default Constructor
       // PRE:
       // POST: root set to NULL
       BST();
 
       // De-allocates dynamic memory associated with tree
       // PRE:
       // POST: All dynamic memory associated with tree is deleted
       ~BST();
 
       // Inserts value in tree maintaining BST property
       // PRE:
       // PARAM: value = value to be inserted
       // POST: inserts value in correct leaf position
       void insert(int value);

       bool remove(int value);

       bool search(int value);
 
       // Prints contents of tree in order
       // PRE:
       // POST: Prints contents of tree using inorder traversal
       void print();
 
private:
       // Node class
       class Node
       {
       public:
              int data;
              Node* left;
              Node* right;
              Node(int value) : data(value), left(NULL), right(NULL) {};
       };
 
       Node* root;
 
 	   void deleteTree(Node* nd);
       // Performs an in-order traversal of tree
       // PRE:
       // POST: Prints contents of tree in order
       void inOrderPrint(Node* nd);
};