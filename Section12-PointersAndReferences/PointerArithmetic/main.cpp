// Section 12
// Pointer Arithmetic

#include <iostream>

using namespace std;

int main() 
{
    
  int scores[] {100, 95, 89, 68, -1};
  int *score_ptr {scores};
  
  cout << "\nDisplaying the array with pointers option 1-------------------------" << endl;
  while (*score_ptr != -1) 
  {
    cout << *score_ptr << endl;
    score_ptr++;
  }
    
  cout << "\nDisplaying the array with pointers option 2-------------------------" << endl;
  score_ptr = scores;
  while (*score_ptr != -1)
  {
    cout << *score_ptr++ << endl;
  }

  cout << "\n-------------------------" << endl;
  string s1 {"Frank"};
  string s2 {"Frank"};
  string s3 {"James"};

  string *p1 {&s1};		
  string *p2 {&s2};
  string *p3 {&s1};

  cout << boolalpha;
  cout << p1 << "==" << p2 << ": " << (p1 == p2) << endl;		// false
  cout << p1 << "==" << p3 << ": " << (p1 == p3) << endl;		// true

  cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << endl;		// true
  cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// true
  
  p3 = &s3;   // point to James
  cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// false
  

  cout << "\n-------------------------" << endl;
  char name[]  {"Frank"};
  
  char *char_ptr {nullptr};
  char *char_ptr0 {nullptr};
  char_ptr = name;
  char_ptr0 = &name[0];   // Same as char_ptr = name, points to 'F' but contains "Frank"

  // With char arrays instead of address, C++ display de string contents from the element to the last array element
  cout << "Value of name: " << name << endl;
  cout << "Value of *name: " << *name << endl;
  
  cout << "\nValue of char_ptr: " << char_ptr << endl;
  cout << "Value of *char_ptr: " << *char_ptr << endl;

  cout  << "\nValue of char_ptr0: " << char_ptr0 << endl;
  cout  << "Value of *char_ptr0: " << *char_ptr0 << endl;

  // In C++ pointing to char array's element contains the rest of the C-style string
  char *char_ptr1{nullptr};
  char *char_ptr2{nullptr};
  char_ptr1 = &name[1];   // points to 'r', but contains "rank" instead its address
  char_ptr2 = &name[2];   // Points to 'a', but contains "ank" instead its address


  cout << "\n-------------------------" << endl;
  cout  << "Value of char_ptr1: " << char_ptr1 << endl;
  cout  << "Value of *char_ptr1: " << *char_ptr1 << endl; 
  cout  << "\nValue of char_ptr2: " << char_ptr2 << endl;
  cout  << "Value of *char_ptr2: " << *char_ptr2 << endl; 

  cout << "\nIn the string " << name << ", the character '" << *char_ptr2 << "' is " << (char_ptr2 - char_ptr0) << " characters away from " <<  *char_ptr0  << endl;

  cout << endl;
  return 0;
}

