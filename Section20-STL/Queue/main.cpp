// Section 20
// Queue
#include <iostream>
#include <queue> // A FIFO data structure which access elements at the front and at the Back

// This function displays a queue of 
// by repeatedly removing elements from the front
// Note that the queue is passed in by value so we
// don't affect the passed in queue.

template <typename T>
void display(std::queue<T> q) 
{
  std::cout << "[ ";
  while (!q.empty()) 
  {
    T elem = q.front();
    q.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main() 
{
  // Instantiate a queue from a deque by default
  std::queue<int> q;
  
  for (int i: {1,2,3,4,5})
  { 
    q.push(i);
  }
  display(q); // [ 1 2 3 4 5 ]

  std::cout << "Front: " << q.front() << std::endl; // Front: 1
  std::cout << "Back:  " << q.back() << std::endl;  // Back: 5

  q.push(100);
  display(q); // [ 1 2 3 4 5 100 ]

  q.pop();
  q.pop();
  display(q); // [ 3 4 5 100 ]
  
  while (!q.empty())
  {
    q.pop();
  }
  display(q); // [ ]

  std::cout << "Size: " << q.size() << std::endl; // Size: 0
  
  q.push(10);
  q.push(100);
  q.push(1000);
  display(q); // [ 10 100 1000 ]
  
  std::cout << "Front: " << q.front() << std::endl; // Front: 10
  std::cout << "Back:  " << q.back() << std::endl;  // Back: 1000
  
  q.front() = 5;
  q.back() = 5000;
  display(q); // [ 5 100 5000 ]
  std::cout << "Front: " << q.front() << std::endl; // Front: 5
  std::cout << "Back:  " << q.back() << std::endl;  // Back: 5000
  
  return 0;
}

