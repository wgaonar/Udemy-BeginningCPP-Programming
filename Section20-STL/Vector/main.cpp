// Section 20
// Vector

#include <iostream>
#include <vector>
#include <algorithm>

class Person 
{
private:
  // For overloading "<<" operator
  friend std::ostream &operator<< (std::ostream &out, const Person &rhs);

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

  // Overloaded operator "<" for using with sTL algorithms
  bool operator<(const Person &rhs) const 
  {
    return this->age < rhs.age;
  }

  // Overloaded operator "==" for using with STL algorithms
  bool operator==(const Person &rhs) const 
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

std::ostream &operator<< (std::ostream &out, const Person &rhs)
{
  out << rhs.name << ": " << rhs.age;
  return out;
}

// Use for_each and a lambda expression to display vector of any type
template <typename T>
void display_vector_for_each(const std::vector<T> &vec) 
{
  std::cout << "[ ";
  std::for_each(vec.begin(), vec.end(), [](T x) { std::cout << x << " ";});
  std::cout << "]" << std::endl;
}

// template function to display a vector of any type
template <typename T>
void display_vector(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &elem: vec)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

// template function to display_vector any container
template <typename T>
void display_container(const T &container) {
    std::cout << "[ ";
    for (const auto &elem: container)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

void test1() 
{
  std::cout << "\nTest1 - display_vector() =========================" << std::endl;

  std::vector<int> vec {1,2,3,4,5};
  display_vector_for_each(vec);
  
  vec = {2,4,5,6};
  display_vector(vec);
  
  std::vector<int> vec1 (10, 100);    // ten 100s in the vector
  display_container(vec1);
}

void test2() 
{
  std::cout << "\nTest2 - .size() and .capacity() ================" << std::endl;

  std::vector<int> vec {1,2,3,4,5};
  display_vector(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << "\n\n";
  
  vec.push_back(6);
  display_vector(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << "\n\n";
  
  vec.shrink_to_fit();    // C++11
  display_vector(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << "\n\n";
  
  vec.reserve(100);
  display_vector(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << "\n\n";
}

void test3() 
{
  std::cout << "\nTest3 - .at() =========================" << std::endl;

  std::vector<int> vec {1,2,3,4,5};
  display_vector(vec);
  
  vec[0] = 100;
  vec.at(1) = 200;
  
  display_vector(vec);
}

void test4() 
{
  std::cout << "\nTest4 - .emplace_back() ==================" << std::endl;
  std::vector<Person> stooges;
  
  Person p1 {"Larry", 18};
  display_vector(stooges);
  
  stooges.push_back(p1);                  // Creates a copy
  display_vector(stooges);
  
  stooges.push_back(Person{"Moe", 25});   // Use move() semantics
  display_vector(stooges);
  
  stooges.emplace_back("Curly", 30);      // Use emplace_back for objects!!!
  display_vector(stooges);
}

void test5() 
{
  std::cout << "\nTest5 - .front() =====================" << std::endl;

  std::vector<Person> stooges 
  {
    {"Larry", 18},
    {"Moe", 25},
    {"Curly", 30}
  };
  
  display_vector(stooges);
  std::cout << "\nFront: " << stooges.front() << std::endl;
  std::cout << "Back: " << stooges.back() << std::endl;
  
  stooges.pop_back();
  display_vector(stooges);
}

void test6_1() 
{
  std::cout << "\nTest6_1 - .erase() =================" << std::endl;
  std::vector<int> vec {1,2,3,4,5};
  display_vector(vec);
  
  vec.clear();    // remove all elements
  display_vector(vec);
  
  vec = {1,2,3,4,5,6,7,8,9,10};
  display_vector(vec);   // [ 1 2 3 4 5 6 7 8 9 10 ]
  vec.erase(vec.begin(), vec.begin() + 2); // [ 3 4 5 6 7 8 9 10 ]
  display_vector(vec);

  // Erase all odd numbers using for loop
  vec = {1,2,3,4,5,6,7,8,9,10};
  for (auto it = vec.begin(); it != vec.end();) // [ 4 6 8 10 ]
  {
    if (*it % 2 != 0) 
    {
      it = vec.erase(it);
    } 
    else 
    {
      ++it; // only increment if not erased!
    }
  }
  display_vector(vec);

  // erase all even numbers using while loop
  vec = {1,2,3,4,5,6,7,8,9,10};
  auto it = vec.begin();
  while (it != vec.end())   // [ 1 3 5 7 9 ]
  {
    if (*it % 2 == 0)
    {
      vec.erase(it);
    }  
    else
    {
      it++;   // only increment if not erased!
    }
  }
  display_vector(vec);
}

void test6_2() 
{
  std::cout << "\nTest6_2 - std::erase() std::erase_if() C++20=================" << std::endl;
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};

  // erase the number 3
  std::erase(vec, 3); // [ 1 2 4 5 6 7 8 9 10 ] since C++20
  display_vector(vec);

  // erase all even numbers using erase_if()
  std::erase_if(vec, [](int x) { return x % 2 == 0; }); // [ 1 5 7 9 ] since C++20
  display_vector(vec);
}

void test7() 
{
  std::cout << "\nTest7 - .swap() =========================" << std::endl;
  
  std::vector<int> vec1 {1,2,3,4,5};
  std::vector<int> vec2 {10,20,30,40,50};
  
  display_vector(vec1); // [ 1 2 3 4 5 ]
  display_vector(vec2); // [ 10 20 30 40 50 ]
  std::cout << std::endl;

  vec2.swap(vec1);
  display_vector(vec1); // [ 10 20 30 40 50 ]
  display_vector(vec2); // [ 1 2 3 4 5 ]
}

void test8() 
{
  std::cout << "\nTest8 std::sort() =========================" << std::endl;

  std::vector<int> vec1 {1,21,3,40,12};    
  display_vector(vec1);

  // Sort with default operator<
  std::sort(vec1.begin(), vec1.end());
  display_vector(vec1);

  // Sort with standard library compare function object
  std::sort(vec1.begin(), vec1.end(), std::greater<int>());
  display_vector(vec1);
}

void test9() 
{
  // std::back_inserter constructs a back-insert iterator that inserts new elements 
  // at the end of the container it applied to. It's a special output iterator
  // It's awesome!!!!   and  very efficient
  // There is also a front_inserter we can use with deques and lists
  // Copy one list to another using an iterator and back_inserter
  
  std::cout << "\nTest9 - std::copy() std::copy_if() std::front/back_inserter()==========" << std::endl;
  
  std::vector<int> vec1 {1,2,3,4,5};   
  std::vector<int> vec2 {10,20};
  display_vector(vec1); 
  display_vector(vec2);
  std::cout << std::endl;

  // copy vec1 at the end of vec2
  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
  display_vector(vec1); // [ 1 2 3 4 5 6 7 8 9 10 ]
  display_vector(vec2); // [ 10 20 1 2 3 4 5 6 7 8 9 10 ]
  std::cout << std::endl;

  vec1 = {1,2,3,4,5,6,7,8,9,10};
  vec2 = {10,20};
  display_vector(vec1);
  display_vector(vec2);
  std::cout << std::endl;
  
  // copy the even numbers of vec1 at the end of vec2
  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
          [](int x) { return x%2 == 0; });
  display_vector(vec1); // [ 1 2 3 4 5 6 7 8 9 10 ]
  display_vector(vec2); // [ 10 20 2 4 6 8 10 ]
  std::cout << std::endl;
}

void test10() 
{
  std::cout << "\nTest10 std::transform() =========================" << std::endl;
  
  std::vector<int> vec1 {1,2,3,4,5};   
  std::vector<int> vec2 {10,20,30,40,50};
  std::vector<int> vec3;
  
  // transform over 2 ranges and store the results in vec3
  // 1*10, 2*20, 3*30, 4*40, 5*50 
  std::transform(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
    std::back_inserter(vec3), [](int x, int y) { return x * y; });
      
  display_vector(vec3); // [ 10 40 90 160 250 ]

  std::vector<int> vec4 (vec1.size(), 0);

  std::transform(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
    vec4.begin(), [](int x, int y) { return 2 * x * y; });

  display_vector(vec4);  // [ 20 80 180 320 500 ]
    
}

void test11() {
  // Insertion from another vector
  // Insert vec2 into vec1 before the 5

  std::cout << "\nTest11 - .insert() =========================" << std::endl;
  std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
  std::vector<int> vec2 {100,200,300,400};
  display_vector(vec1);
  display_vector(vec2);

  // Option 1: Find the position in vec1 where vec2 is going to be inserted
  auto it = std::find(vec1.begin(), vec1.end(), 5);

  // Option 2: Define the desired position in the vector
  // auto it = vec1.begin() + 3;

  // Insert vec2 into vec1
  if (it != vec1.end()) 
  {
    std::cout << "inserting..." << std::endl;
    vec1.insert(it, vec2.begin(), vec2.end());
  } 
  else 
  {
    std::cout << "Sorry, 5 not found" << std::endl;
  }
  display_vector(vec1); // [ 1 2 3 4 100 200 300 400 5 6 7 8 9 10 ]
}

int main()  
{    
  test1();
  test2();
  test3();
  test4();
  test5();
  test6_1();
  test6_2();
  test7();
  test8();
  test9();
  test10();
  test11();
  
  return 0;
}