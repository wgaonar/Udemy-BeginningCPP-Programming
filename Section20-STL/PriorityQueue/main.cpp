// Section 20
// Priority Queue
#include <iostream>
#include <queue>

class Person 
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  // Default constructor
  Person() : name{"Unknown"}, age{0} {}

  // Overload constructor
  Person(std::string name, int age) 
    : name{name}, age{age}  {}

  // Overload less than "<" operator
  bool operator<(const Person &rhs) const 
  {
    // return this->age < rhs.age; // If you desire order by age
    return this->name < rhs.name;  // If you desire order by name
  }

  // Overload equal "=" operator
  bool operator==(const Person &rhs) const 
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

// Friend function to print an object of the class Person
std::ostream &operator<<(std::ostream &os, const Person &p) 
{
  os << p.name << ":" << p.age;
  return os;
}

// This displays the priority queue by
// repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the 
// priority queue being passed in
template <typename T>
void display(std::priority_queue<T> pq)  
{
  std::cout << "[ ";
  while (!pq.empty()) 
  {
    T elem = pq.top();
    pq.pop();
    std::cout << elem << " ";
  }
  std::cout <<  "]" << std::endl;
}

void  test1() 
{
  std::cout << "\nTest1 - .push() .pop() =========================" << std::endl;

  std::priority_queue<int> pq;
  for (int i : {3,5,7,12,23,12,4,100,0, 3,5,7})
  {
    pq.push(i);
  }
      
  std::cout << "Size: " << pq.size() << std::endl;  // 12
  std::cout << "Top: " << pq.top() << std::endl;    // 100
      
  display(pq); // [ 100 23 12 12 7 7 5 5 4 3 3 0 ]
  
  pq.pop();
  display(pq); // [ 23 12 12 7 7 5 5 4 3 3 0 ]
}

void test2() 
{
  std::cout << "\nTest2 - .push(Person)=========================" << std::endl;

  std::priority_queue<Person> pq;
  pq.push(Person{"A", 10});
  pq.push(Person{"B", 1});
  pq.push(Person{"C", 14});
  pq.push(Person{"D", 18});  
  pq.push(Person{"E", 7});  
  pq.push(Person{"F", 27});
  
  display(pq); // [ F:27 E:7 D:18 C:14 B:1 A:10 ]
}

int main() 
{
  test1();
  test2();
  return 0;
}

