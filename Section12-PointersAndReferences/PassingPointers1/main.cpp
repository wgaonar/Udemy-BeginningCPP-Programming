// Section 12
// Passing Pointers 1
#include <iostream>

using namespace std;


void double_data(int *int_ptr) 
{
  *int_ptr *= 2;	
}

int main() 
{
  int value {10};
  cout << "Value: " << value << endl;   // Value = 10

  cout << "-----------------------------" << endl;
  double_data(&value);
  cout << "Value: " << value << endl;    // Value = 20

  cout << "-----------------------------" << endl;
  int *int_ptr {nullptr};
  int_ptr = &value;
  double_data(int_ptr);
  cout << "Value: " << value << endl;   // Value = 40

  cout  << endl;
  return 0;
}