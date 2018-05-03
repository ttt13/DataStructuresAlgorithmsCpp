#pragma once
class ArrayClass
{
public:
       // Constructors and Destructors
 
       // Default constructor
       // POST: Creates an ArrayClass object with an array of size 2
       // PARAM:
       ArrayClass();
 
       // Destructor
       // POST: De-allocates dynamic memory associated with object
       ~ArrayClass();
 
       // Accessors (getters) and mutators (setters)
 
       // Sets the value of the next free element
       // PRE:
       // POST: Sets index n to value, doubles size of arr if n == arrSize, increments n
       // PARAM: value = value to be set
       void insert(int value);
 
       // Returns the sum of the values stored in the array
       // PRE:
       // POST: Returns sum of the first n elements of arr
       int sum();
 
       // Returns the number of elements stored in the array
       // PRE:
       // POST: Returns n
       int size();
 
private:
       int* arr;
       int arrSize;
       int n;
};