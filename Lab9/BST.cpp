#include "BST.h"
 
// Default Constructor
// PRE:
// POST: root set to NULL
BST::BST()
{
       root = NULL;
}
 
// De-allocates dynamic memory associated with tree
// PRE:
// POST: Value is inserted, in order, in tree
BST::~BST()
{
       deleteTree(root);
}
 
// Insert value in tree maintaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: Value is inserted, in order, in tree
void BST::insert(int value)
{
       // TO DO
       Node* newNode = new Node(value);
       if(root == NULL){
              root = newNode;
       }

       else{
              Node* parent = root;
              Node* current = root;
              bool isLeft = false;

              // Go down the BST
              while (current){

                     parent = current;
                     if(value < current->data){
                            current = current->left;
                            isLeft = true;
                     }
                     else{
                            current = current->right;
                            isLeft = false;
                     }
              } //while
       
              if(isLeft){
                     parent->left = newNode;
              }
              else{
                     parent->right = newNode;
              }
       }
}

bool BST::searchIterative(int value)
{
       if(root == NULL){
              return false;
       }

       else{
              Node* current = root;

              while (current){
                     if (current->data == value){
                            return true;
                     }

                     if(value < current->data){
                            current = current->left;
                     }

                     else{
                            current = current->right;
                     }
              }

              return false;
       }
} 

bool BST::searchRecursive(Node* nd, int value)
{
       if(nd == NULL){
              return false; 
       }
       else if(value == nd->data){
              return true;
       }
       else if(value < nd->data){
              return searchRecursive(nd->left, value);
       }
       else{
              return searchRecursive(nd->right, value);
       }
}

bool BST::remove(int value)
{
       if(root == NULL){
              return false;
       }

       // Find the value, if it exists
       Node* parent = root;
       Node* current = root;
       bool isLeft = false;

       while (current->data != value){
              if(current == NULL){
                     return false;
              }

              parent = current;

              if(value < current->data){
                     current = current->left;
                     isLeft = true;
              }

              else{
                     current = current->right;
                     isLeft = false;
              }
       }

       // Case: 2 children
       if(current->left && current->right){
              Node* predecessor = current->left;
              Node* preParent = current->left;

              while(predecessor->right){

                     preParent = predecessor;
                     predecessor = predecessor->right;
              }

              Node* newNode = new Node(predecessor->data);
              if(isLeft){
                     parent->left = newNode;
              }
              else{
                     parent->right = newNode;
              }

              newNode->left = current->left;
              newNode->right = current->right;

              if(predecessor->left){
                     preParent->right = predecessor->left;
              }

              delete predecessor;

       } // end Case 2

       // Case: 1 child
       else if(current->left && !(current->right) || current->right && !(current->left)){
              if(current->left){
                     if(isLeft){
                            parent->left = current->left;
                     }
                     else{
                            parent->right = current->left;
                     }
              }
              else{
                     if(isLeft){
                            parent->left = current->right;
                     }
                     else{
                            parent->right = current->right;
                     }
              }
       }

       delete current;
       return true;
}
// Prints contents of tree in order
// PRE:
// POST: Prints contents of tree in order
void BST::print()
{
       inOrderPrint(root);
}
 
// Performs an in-order traversal of tree
// PRE:
// POST: Prints contents of tree in order
void BST::inOrderPrint(Node* nd)
{
       if(nd != NULL){
              inOrderPrint(nd->left);
              cout << nd->data << " ";
              inOrderPrint(nd->right);
       }
}
 
// Deletes all the nodes in the tree
// PRE:
// POST: Deletes all nodes, de-allocating dynamic memory
void BST::deleteTree(Node* nd)
{
       if(nd != NULL){
              deleteTree(nd->left);
              deleteTree(nd->right);
              delete(nd);
       }
}