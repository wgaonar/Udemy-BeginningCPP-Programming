// Section 12
// Return Pointer
#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0) 
{
  int *new_storage {nullptr};
  new_storage = new int[size];   
  for (size_t i{0}; i < size; ++i)
  {
    *(new_storage + i) = init_value;
  }
  return new_storage;
}

void display(const int *const array, size_t size) 
{
  for (size_t i{0}; i < size; ++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int *largest (int *int_ptr1, int *int_ptr2)
{
  if (*int_ptr1 > *int_ptr2)
  {
    return int_ptr1;
  }
  else
  {
    return int_ptr2;
  }
}
int main() 
{
  cout << "\nHow many integers would you like to allocate? ";
  size_t size {};
  cin >> size;

  cout << "What value would you like them initialized to? ";
  int init_value {};
  cin >> init_value;
  
  int *my_array {nullptr};
  my_array = create_array(size, init_value);
  cout << "\n--------------------------------------" << endl;
  display(my_array, size);
  delete [] my_array;

  int a{100};
  int b{200};
  int *largest_int {nullptr};
  largest_int = largest (&a, &b);
  cout << "\n---------------------------------------" << endl;
  cout << "The largest int is: " << *largest_int << endl;
  return 0;
}