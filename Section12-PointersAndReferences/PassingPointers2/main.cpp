// Section 12
// Passing Pointers 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Performs the swap without using temp.
void swap2(int *a, int *b) 
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}


int main() 
{
  int x {100}, y {200};
  cout << "\nx: " << x <<  endl;    // 100
  cout << "y: " << y <<  endl;      // 200
  
  swap2(&x, &y);
  
  cout << "\nx: " << x <<  endl;    // 100
  cout << "y: " << y <<  endl;      // 200
  
  cout  << endl;
  return 0;
}

