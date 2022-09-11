// Section 20
// Stack
#include <iostream>
#include <stack>
#include <vector>
#include <list>

// This function displays a stack of 
// by repeatedly topping and popping the stack
// Note that the stack is passed in by value so we
// don't affect the passed in stack.

template <typename T>
void display(std::stack<T> s) 
{
  std::cout << "[ ";
  while (!s.empty()) 
  {
    T elem = s.top();
    s.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main() 
{
  // Instantiate a stack from a deque by default
  std::stack<int> s;

  // Instantiate a stack from a vector
  std::stack<int, std::vector<int>> s1;

  // Instantiate a stack from a list
  std::stack<int, std::list<int>> s2;

  // Instantiate a stack explicitly from a deque
  std::stack<int, std::deque<int>> s3;
    
  for (int i: {1,2,3,4,5})
  {
    s.push(i);
  }  
  display(s); // [ 5 4 3 2 1 ]

  s.push(100);
  display(s); // [ 100 5 4 3 2 1 ]
  
  s.pop();
  s.pop();
  display(s); // [ 4 3 2 1 ]
  
  while (!s.empty())
  {
    s.pop();
  }
  display(s); //[ ]
  
  std::cout << "Size: " << s.size() << std::endl; // Size: 0
  
  s.push(10); 
  display(s); // [ 10 ] 
  
  s.top() = 100; // .top() is a reference and can be used to modified the top value
  display(s); // [ 100 ]
  return 0;
}

