// Section 14
// Overloading move constructor and move assignment operator
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() 
{
  // Overloaded constructor
  Mystring a{"Hello"};

  // Overloaded constructor then move assignment
  a = Mystring{"Hola"};              
  
  // Overloaded constructor then move assignment
  a = "Bonjour";                         

/*
  // no-args constructor
  Mystring empty;

  // overloaded constructor
  Mystring larry {"Larry"};

  // copy constructor 
  Mystring stooge {larry};

  // no-args constructor
  Mystring stooges;                   
  
  // copy assignment operator stooge is an l-value
  empty = stooge;                     
  
  // move assignment operator "Funny" is an r-value
  empty = "Funny";                    

  // Funny : 5 
  empty.display();

  // Larry : 5
  larry.display();
  
  // Larry : 5
  stooge.display();
  
  // Funny : 5 
  empty.display();
    
  stooges = "Larry, Moe, and Curly";
  // Larry, Moe, and Curly : 21   
  stooges.display();
    
  vector<Mystring> stooges_vec;
  stooges_vec.push_back("Larry");                
  stooges_vec.push_back("Moe");                
  stooges_vec.push_back("Curly");           
    
  cout << "=== Loop 1 ==================" << endl;
  // Larry, Moe, and Curly
  for (const Mystring &s: stooges_vec) 
      s.display();
        
  cout << "=== Loop 2 ==================" << endl;
  // move assignment
  for (Mystring &s: stooges_vec)
      s = "Changed";                                      
        
  cout << "=== Loop 3 ==================" << endl;
  // Changed, Changed, Changed
  for (const Mystring &s: stooges_vec) 
      s.display();

*/        
  return 0;
}

