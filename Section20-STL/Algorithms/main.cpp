// Section 20
// Algorithms
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> 

class Person 
{
private:
  std::string name;
  int age;
public:
  // Default constructor
  Person() = default;

  // Overloaded constructor
  Person(std::string name, int age) 
    : name{name}, age{age}  {}

  // Getters
  std::string get_name() const
  {
    return name;
  }

  int get_age() const
  {
    return age;
  }

  // Overloaded operator "<" for using with algorithm
  bool operator<(const Person &rhs) const 
  {
    return this->age < rhs.age;
  }

  // Overloaded operator "==" for using with algorithm
  bool operator==(const Person &rhs) const 
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

// Function to check if an element is in a container
template <typename T, typename U>
bool is_contained(const T& container, const U& p)
{
  auto loc = std::find(container.begin(), container.end(), p);
  if (loc != container.end())
  {
    std::cout << p.get_name() << " was found" << std::endl;
    return true;
  }
  else
  {
    std::cout << p.get_name() << " was NOT found" << std::endl;
    return false;
  }
}

// Find an element in a container
void find_test() 
{
  std::cout << "\n==find test======================" << std::endl;

  std::vector<int> vec {1,2,3,4,5};
  
  auto loc = std::find(std::begin(vec), std::end(vec), 1);  // begin(vec) is equivalent to: vec.begin()
  
  if (loc != std::end(vec))
  {
    std::cout << "Found the number: " << *loc << std::endl;
  }
  else
  { 
    std::cout << "Couldn't find the number" << std::endl;
  }

  std::list<Person> players 
  {
    {"Larry", 18},
    {"Moe", 20},
    {"Curly", 21}
  };
  
  // Find a person using explicit code
  Person person1 {"Moe", 20};
  auto loc1 = std::find(players.begin(), players.end(), person1);
  if (loc1 != players.end())
  {
    std::cout << person1.get_name() << " was found" << std::endl;
  }
  else
  {
    std::cout << person1.get_name() << " was NOT found" << std::endl;
  }

  // Find a person using a user-defined function
  Person person2 {"Wilmer", 39};
  is_contained(players, person2);
}

// Count the number of elements in a container
void count_test() 
{
  std::cout << "\n==count test======================" << std::endl;

  std::vector<int> vec {1,2,3,4,5,1,2,1};
    
  int num_to_find = 3;
  int num = std::count(vec.begin(), vec.end(), num_to_find);
  std::cout << num 
            << ((num == 1) ? " occurrence found of number: " : " occurrences found of number: ") 
            << num_to_find << std::endl;
}

// Count the number of occurrences of an element in a container
// based on a predicate using a lambda expression
void count_if_test() 
{
  std::cout << "\n==count_if_test======================" << std::endl;

  // count only if the element is even
  std::vector<int> vec {1,2,3,4,5,1,2,1,100};
  int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x %2 == 0; });
  std::cout << num << " even numbers found" << std::endl;
  
  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x %2 != 0; });
  std::cout << num << " odd numbers found" << std::endl;
  
  // how can we determine how many elements in vec are >= 5?
  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x>=5; });
  std::cout << num << "  numbers are >= 5" << std::endl;

  // Making a list of Persons
  std::list<Person> players 
  {
    {"Larry", 18},
    {"Moe", 20},
    {"Curly", 21},
    {"Shemp", 21},
    {"Wilmer", 39},
    {"Frank", 50}
  };
  
  // Count with explicit code the persons who are > than an age threshold
  int age_threshold = 30;
  num = std::count_if(players.cbegin(), players.cend(), [age_threshold](Person p) { return p.get_age() >= age_threshold; });
  std::cout << num << " persons are >= of " << age_threshold << " years old" << std::endl;

  // Count with the overloaded operator < the persons who are < than other person
  // REMEMBER: the overloading operator expects the same type of data as argument. In this case an object of type Person
  Person person_test {"Joseph", 19};
  num = std::count_if(players.cbegin(), players.cend(), [person_test](Person p) { return p < person_test; });
  std::cout << num << " person(s) are < of " << person_test.get_age() << " years old" << std::endl;

  
}

// Replace occurrences of elements in a container
void replace_test() {
    std::cout << "\n========================" << std::endl;

     std::vector<int> vec {1,2,3,4,5,1,2,1};
     for (auto i: vec) {
         std::cout << i << " ";
     }
     std::cout << std::endl;
     
    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i: vec) {
         std::cout << i << " ";
     }
    std::cout << std::endl;
}

void all_of_test() {
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else    
        std::cout << "Not all the elements are > 10" << std::endl;
    
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else    
        std::cout << "Not all the elements are < 20" << std::endl;        
}

// Transform elements in a container - string in this example
void string_transform_test() {
    std::cout << "\n========================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After transform: " << str1 << std::endl;
}

int main() 
{
  find_test();
  count_test();
  count_if_test();
//    replace_test();
//    all_of_test();
//    string_transform_test();

    return 0;
}

