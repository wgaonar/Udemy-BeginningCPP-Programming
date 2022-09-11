// Section 20
// Map

#include <iostream>
#include <map>
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

template <typename T1, typename T2>
void display(const std::map<T1, T2> &m) 
{
  std::cout << "[ ";
  for (const auto &elem: m) 
  {
    std::cout << elem.first << ":" << elem.second << " ";
  }
  std::cout << "]  " << std::endl;
}

void display(const std::map<std::string, std::set<int>> &m) 
{
  std::cout << "[ ";
  for (const auto &elem: m) 
  {
    std::cout << elem.first << ": [ " ;
    for (const auto &set_elem : elem.second)
    {
      std::cout << set_elem <<  " ";
    }
    std::cout << "] " ;
  }
  std::cout << "]  " << std::endl;
}

void test1() 
{
  // Maps
  std::cout << "\nTest1 - std::pair<>() std::make_pair() =======" << std::endl;
  std::map<std::string, int> m 
  {
    {"Larry", 3},
    {"Moe", 1},
    {"Curly", 2}
  };
  display(m); // [ Curly:3 Larry:3 Moe:1 ]      
  
  m.insert( std::pair<std::string, int>("Anna", 10));
  display(m); // [ Anna:10 Curly:3 Larry:3 Moe:1 ] 
  
  m.insert(std::make_pair("Joe", 5));
  display(m); // [ Anna:10 Curly:3 Joe:5 Larry:3 Moe:1 ]
  
  // Insert with subscript operator []
  m["Frank"] = 18;
  display(m); // [ Anna:10 Curly:3 Frank:18 Joe:5 Larry:3 Moe:1 ]

  // ERROR to insert with .at() method because it checks for out_of_range limits
  // m.at("Frank") = 18;
  
  m["Frank"] += 10;               
  display(m);  // [ Anna:10 Curly:3 Frank:28 Joe:5 Larry:3 Moe:1 ]

  m.at("Frank") += 10;               
  display(m);  // [ Anna:10 Curly:3 Frank:38 Joe:5 Larry:3 Moe:1 ]
  
  m.erase("Frank");
  display(m); // [ Anna:10 Curly:3 Joe:5 Larry:3 Moe:1 ]
  
  std::cout << "Count for Joe: " << m.count("Joe") << std::endl; // 1
  std::cout << "Count for Frank: " << m.count("Frank") << std::endl; // 0
  
  // Find by using an iterator
  auto it = m.find("Larry");
  if (it != m.end())
  {
    std::cout << "Found: " << it->first << " : " << it->second << std::endl; // Found: Larry : 3
  }
      
  m.clear();
  display(m); // [ ]
}

void test2() 
{
  std::cout << "\nTest2 - map of <std::string,std::set<int>> =========================" << std::endl;
  
  // A map of string as a key an a set of ints as a values
  std::map<std::string, std::set<int>> grades  
  {
    {"Larry", {100, 90} },
    {"Moe",  {94} },
    {"Curly", {80, 90, 100} }
  };
  display(grades); // [ Curly: [ 80 90 100 ] Larry: [ 90 100] Moe: [ 94 ] ]
  
  grades["Larry"].insert(95); // insert 95 into the set of grades for "Larry"
  display(grades);  // [ Curly: [ 80 90 100 ] Larry: [ 90 95 100] Moe: [ 94 ] ] 
  
  auto it = grades.find("Moe");
  if (it != grades.end()) // found the key "Moe"
  {
    it->second.insert(1000); // insert 1000 into Moe's set of grades
  }                          // it->first is the key, it->second is the value (set)
  display(grades);  // [ Curly: [ 80 90 100 ] Larry: [ 90 95 100] Moe: [ 94 1000 ] ] 
}

void test3()
{
  std::cout << "\nTest3 - map of <int,std::set<Person>> =========================" << std::endl;
  // A map of string as a key and a Person as a value
  std::map<std::string, Person> stooges 
  {
    {"stooge 1", {"Moe", 39} },
    {"stooge 2", {"Larry", 35} },
    {"stooge 3", {"Curly", 43} }
  };
  display(stooges); // [ stooge 1:Moe:39 stooge 2:Larry:35 stooge 3:Curly:43 ]

  stooges.insert(std::pair<std::string, Person>("stooge 4", {"Shemp", 50}));
  display(stooges); // [ stooge 1:Moe:39 stooge 2:Larry:35 stooge 3:Curly:43 stooge 4:Shemp:50 ]

  stooges.insert(std::make_pair("stooge 5", Person{"Wilmer", 15}));
  display(stooges); // [ stooge 1:Moe:39 stooge 2:Larry:35 stooge 3:Curly:43 stooge 4:Shemp:50 stooge 5:Wilmer:15 ] 

  auto it = stooges.find("stooge 3");
  if (it != stooges.cend())
  { 
    // Erase using the key 
    stooges.erase("stooge 3");
  }
  display(stooges); // [ stooge 1:Moe:39 stooge 2:Larry:35 stooge 4:Shemp:50 stooge 5:Wilmer:15 ]

  it = stooges.find("stooge 5");
  if (it != stooges.cend())
  { 
    // Erase using an iterator that points to an element or elements in multimap 
    stooges.erase(it);
  }
  display(stooges); // [ stooge 1:Moe:39 stooge 2:Larry:35 stooge 4:Shemp:50 ] 
}

int main() 
{
  test1();
  test2();
  test3();
  return 0;
}

