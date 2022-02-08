// Section 14
// Overloading copy assignment
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() 
{
  // overloaded constructor
  Mystring a {"Hello"};

  // no-args contructor                
  Mystring b;

  // copy assignment b.operator=(a)                             
  b = a;                                      
 
  // b.operator=("This is a test");
  b = "This is a test";                 

  // no-args constructor
  Mystring empty;

  // overloaded constructor                      
  Mystring larry("Larry");

  // Deep copy constructor             
  Mystring stooge {larry};

  // no-args constructor             
  Mystring stooges;                   
  
  // copy assignment operator
  empty = stooge;                     
  
  // Larry : 5
  empty.display();

  // Larry : 5                      
  larry.display();

  // Larry : 5
  stooge.display();

  // Larry : 5
  empty.display();                      
  
  stooges = "Larry, Moe, and Curly";

  // Larry, Moe, and Curly : 21  
  stooges.display();                              
  
  vector<Mystring> stooges_vec;
  stooges_vec.push_back("Larry");
  stooges_vec.push_back("Moe");
  stooges_vec.push_back("Curly");
  
  cout << "\n=== Loop 1 ==================" << endl;
  // Larry, Moe, and Curly
  for (const Mystring &s: stooges_vec) 
      s.display();

  cout << "\n=== Loop 2 ==================" << endl;
  // copy assignment
  for (Mystring &s: stooges_vec)
      s = "Changed";                              
      
  cout << "\n=== Loop 3 ================" << endl;
  // Changed, Changed, Changed
  for (const Mystring &s: stooges_vec) 
      s.display();                                     
  
  return 0;
}

