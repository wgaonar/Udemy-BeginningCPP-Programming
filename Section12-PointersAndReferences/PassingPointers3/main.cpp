// Section 12
// Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display( const vector<string> *const  v) 
{
  //(*v).at(0) = "Funny"; // Not allowed by the first const
  for (auto str: *v)
      cout << str << " ";
  cout << endl;
  //v = nullptr;          // Not allowed by the second const
}

void display(int *array, int sentinel) 
{
  while (*array != sentinel)
    cout << *array++ << " ";
  cout << endl;
}

void display(int array[], size_t size, int sentinel) 
{
  for (size_t i{0}; i < size; ++i)
  {
    if (array[i] == sentinel)
    {
      break;
    }
    cout << array[i] << " ";
  }   
  cout << endl;
}

int main() 
{
  cout << "Pointer to a vector-----------------------------" << endl;
  vector<string> stooges {"Larry", "Moe", "Curly"};
  display(&stooges);
  
  cout << "\nPointer to an array-----------------------------" << endl;
  int scores[] {100,98,97,79,85,-1};
  display(scores, -1);

  cout << "\nReference to an array-----------------------------" << endl;
  display(scores, 6, -1);
  
  cout  << endl;
  return 0;
}

