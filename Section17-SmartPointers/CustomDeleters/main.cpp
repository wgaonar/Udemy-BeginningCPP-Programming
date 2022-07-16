// Section 17
// Custom deleters
#include <iostream>
#include <memory>

class Test 
{
private:
  int data;
public:
  // Default constructor
  Test() : data{0} 
  { 
    std::cout << "Test constructor (" << data << ")" << std::endl; 
  }

  // Override constructor
  Test(int data) : data {data} 
  { 
    std::cout << "Test constructor (" << data << ")" << std::endl; 
  }

  // Accessor Methods
  int get_data() const 
  {
    return data; 
  }

  // Destructor
  ~Test() 
  {
    std::cout << "Test destructor (" << data << ")" << std::endl; 
  }
};

void my_deleter(Test *ptr) 
{
  std::cout << "\tUsing my custom function deleter" << std::endl;
  delete ptr;
}

int main() 
{
  // Artificial Scope to ensure ptr1 is deleted inside this scope
  std::cout << "\n--------------------------\n";
  {
    // Using a function 
    std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter };
  }

  std::cout << "\n--------------------------\n";
  {
    // Using a Lambda expression
    std::shared_ptr<Test> ptr2 (new Test{1000}, 
        [] (Test *ptr)  
        {
          std::cout << "\tUsing my custom lambda deleter" << std::endl;
          delete ptr;
        });
  }
  
  return 0;
}