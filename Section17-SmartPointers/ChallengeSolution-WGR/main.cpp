// Section 17
// Challenge 1
/***********************************************************************************************************
Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.
   
   This function will prompt the user to enter an integer, create a shared_ptr to a Test object 
   initialized to the entered integer and add that shared pointer to the vector.
   
3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object
   
4. The main driver should look as follows:

    int main() {
        std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
        vec_ptr = make();
        std::cout << "How many data points do you want to enter: ";
        int num;
        std::cin >> num;
        fill(*vec_ptr, num);
        display(*vec_ptr);
        return 0;
    }
    
Below is a sample run for the user entering 3 at the console:
    
How many data points do you want to enter: 3
Enter data point [1] : 10
        Test constructor (10)
Enter data point [2] : 20
        Test constructor (20)
Enter data point [3] : 30
        Test constructor (30)
Displaying vector data
=======================
10
20
30
=======================
        Test destructor (10)
        Test destructor (20)
        Test destructor (30)

- I am providing the function prototypes in the code. 
However, feel free to modify these as you wish
***********************************************************************************************************/
#include <iostream>
#include <memory>
#include <vector>

class Test 
{
private:
  int data;
public:
  // Default constructor
  Test() : data{0} 
  { 
    std::cout << "\tTest constructor (" << data << ")" << std::endl; 
  }

  // Override constructor
  Test(int data) : data {data} 
  { 
    std::cout << "\tTest constructor (" << data << ")" << std::endl; 
  }

  // Accessor Methods
  int get_data() const 
  {
    return data; 
  }

  // Destructor
  ~Test() 
  {
    std::cout << "\tTest destructor (" << data << ")" << std::endl; 
  }
};

// Functions
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
  auto ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
  // std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr {new std::vector<std::shared_ptr<Test>>()}; // Same as the line above
  return ptr;
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num) 
{
  int data {0};
  for (size_t i = 1; i <= num; i++)
  {
    std::cout << "Enter data point [" << i << "] : ";
    std::cin >> data;
    std::shared_ptr<Test> ptr = std::make_shared<Test> (data);
    // std::shared_ptr<Test> prt {new Test(data)}; // same as the line before
    vec.push_back(std::move(ptr));
  }
}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{
  for (const auto &element : vec)
  {
    std::cout << element->get_data()<< std::endl;
  }
}

int main() 
{
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  vec_ptr = make();

  std::cout << "\n--------------------------\n";
  std::cout << "How many data points do you want to enter: ";
  int num;
  std::cin >> num;
  fill(*vec_ptr, num);

  std::cout << "\n--------------------------\n";
  display(*vec_ptr);
  return 0;
}