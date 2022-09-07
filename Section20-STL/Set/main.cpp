// Section 20
// Set
#include <iostream>
#include <set>

class Person 
{
private:
  // For overloading "<<" operator
  friend std::ostream& operator<<(std::ostream &os, const Person &p);

  std::string name;
  int age;
public:
  // Default constructor
  Person() 
    : name{"Unknown"}, age{0} 
    {}

  // Overload constructor
  Person(std::string name, int age) 
    : name{name}, age{age} 
    {}

  // Overload less "<" operator
  // Sets uses it to check for the duplicate elements
  bool operator<(const Person &rhs) const 
  {
    return this->age < rhs.age;
  }

  // Overload equal "==" operator
  bool operator==(const Person &rhs) const 
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

// Friend function for overloading "<<" operator
std::ostream &operator<<(std::ostream &os, const Person &p) 
{
  os << p.name << ":" << p.age;
  return os;
}

template <typename T>
void display(const std::set<T> &s) 
{
  std::cout << "[ ";
  for (const auto &elem: s) 
  {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() 
{
  // Sets
  std::cout << "\nTest1 - display() .find() =========================" << std::endl;
  std::set<int> s1 {1, 4, 3, 5, 2};
  display(s1); // [ 1 2 3 4 5]
  
  s1 = {1,2,3,1,1,2,2,3,3,4,5};
  display(s1); // [ 1 2 3 4 5 ]
  
  s1.insert(0);
  s1.insert(10);  
  display(s1); // [ 0 1 2 3 4 5 10 ]
  
  if (s1.count(10)) // 0 or 1 is the return of .count()
  {
    std::cout << "10 is in the set" << std::endl;
  } 
  else
  {
    std::cout << "10 is NOT in the set" << std::endl;
  }

  auto it = s1.find(5);
  if (it != s1.end())
  {
    std::cout << "Found: " << *it << std::endl;    
  }
      
  s1.clear();
  
  display(s1);
}

void test2() 
{
  std::cout << "\nTest2 - .emplace() .erase() =========================" << std::endl;
  
  std::set<Person> stooges 
  {
      {"Larry", 1},
      {"Moe", 2},
      {"Curly", 3}
  };
  display(stooges); // [ Larry:1 Moe:2 Curly:3 ]
                    // Note the order of display!  due to the operator "<"

  stooges.emplace("James", 50);   
  display(stooges); // [ Larry:1 Moe:2 Curly:3 James:50 ]

  stooges.emplace("Frank", 50); // NO -- 50 already exists
  display(stooges); // [ Larry:1 Moe:2 Curly:3 James:50 ]
  
  auto it = stooges.find(Person{"Moe", 2});
  if (it != stooges.end())
  {
    stooges.erase(it);
  }
  display(stooges); // [ Larry:1 Curly:3 James:50 ]
  
  it = stooges.find(Person("XXXX", 50));     // Will remove James!!!!
                                             // using the  operator "<"
  if (it != stooges.end())
  {
    stooges.erase(it);
  }
  display(stooges); // [Larry:1 Curly:3 ]
}

void test3() 
{
  std::cout << "\nTest3 .insert() =========================" << std::endl;
  
  std::set<std::string> s {"A", "B", "C"};
  display(s);
  
  auto result = s.insert("D");  // Insert return std::pair <it, true/False>
  display(s); // [ A B C D ]
  
  std::cout << std::boolalpha;
  std::cout << "first: " <<  *(result.first)<< std::endl; // D
  std::cout  << "second: " << result.second << std::endl; // true
  
  std::cout << std::endl;

  result = s.insert("A");
  display(s); // [ A B C D ] // A already exists!
  
  std::cout << std::boolalpha;
  std::cout << "first: " <<  *(result.first)<< std::endl; // A
  std::cout  << "second: " << result.second << std::endl; // false
}

int main() 
{
  test1();
  test2();
  test3();

  return 0;
}

