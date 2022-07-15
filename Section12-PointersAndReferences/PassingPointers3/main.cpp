// Section 12
// Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display( const vector<string> *const v) 
{
  //(*v).at(0) = "Funny"; // Not allowed by the first const
  for (auto str: *v)
      cout << str << " ";
  cout << endl;
  //v = nullptr;          // Not allowed by the second const
}

// Passing an array through a pointer
void display(int *array, size_t size, int sentinel) 
{
  // Working with subscript notation
  for (size_t i{0}; i < size; ++i)
  {
    if (array[i] == sentinel)
    {
      break;
    }
    cout << array[i] << " ";
  }
  cout << endl;

  // Working with offset notation   
  while (*array != sentinel)
    cout << *array++ << " ";
  cout << endl;
}

// Passing and array in a classic way via a reference
void display2(int array[], size_t size, int sentinel) 
{
  // Working with subscript notation
  for (size_t i{0}; i < size; ++i)
  {
    if (array[i] == sentinel)
    {
      break;
    }
    cout << array[i] << " ";
  }
  cout << endl;

  // Working with offset notation   
  while (*array != sentinel)
    cout << *array++ << " ";
  cout << endl;
}

int main() 
{
  cout << "Pointer to a vector-----------------------------" << endl;
  vector<string> stooges {"Larry", "Moe", "Curly"};
  display(&stooges);
  
  int scores[] {100,98,97,79,85,-1};
  cout << "\nPointer to an array-----------------------------" << endl;
  display(scores, 6, -1);

  cout << "\nReference to an array-----------------------------" << endl;
  display2(scores, 6, -1);
  
  cout  << endl;
  return 0;
}

