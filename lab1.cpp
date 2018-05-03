#include <iostream> // for cout
#include "ArrayClass.h"
 
using namespace std;
 
// Function Prototype
void arrayClassTest();
 
// Main function that is called when the program is executed
int main(){
       arrayClassTest();
       return 0;
}
 
void arrayClassTest()
{
       ArrayClass ac;
       ac.insert(1);
       ac.insert(2);
 
       cout << "ac.size()  = "<< ac.size() << endl;
 
       // Insert the values 1 to 7 in ac1
       for(int i=3; i <= 40; ++i){
              ac.insert(i);
       }
 
       cout << "ac.size()  = "<< ac.size() << endl;

       cout << "ac.sum() = "<< ac.sum() << endl;
}