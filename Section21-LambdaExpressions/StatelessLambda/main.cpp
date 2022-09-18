// Section 21
// Stateless lambda expressions
// [] - empty capture lists
#include <iostream>
#include <string>
#include <vector>
#include <functional>   // for std::function
#include <algorithm>

class Person 
{
  // Friend functions to overload insertion operator "<<"
  friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
  std::string name;
  int age;

public:
  // Overload constructor
  Person(std::string name, int age) : name{name}, age{age} {};

  // Copy constructor
  Person(const Person &p): name{p.name}, age{p.age} { }

  // Force a compile to generate the destructor
  ~Person() = default;

  // Getters
  std::string get_name() const { return name; }
  int get_age() const {return age; }

  // Setters
  void set_name(std::string name) {this->name = name; };
  void set_age(int age) {this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) 
{
  os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
  return os;
}

void test1() 
{
  std::cout << "\n---Test1 lambda executions -----------------" << std::endl;

  // No parameters and instantiate with () at the end of the lambda expression
  [] () {std::cout << "Hi" << std::endl; }(); // "Hi"
  
  // One int parameter and instantiate with () at the end of the lambda expression
  [] (int x) { std::cout << x << std::endl;}(100);  // 100
  
  // Tow ints parameter and instantiate with () at the end of the lambda expression
  [](int x, int y) { std::cout << x+y << std::endl; }(100,200); // 300
}

// Using values and references as lambda parameters 
void test2() 
{
  std::cout << "\n---Test2 parameters with values and references -----------" << std::endl;
  
  auto l1 = [] () {std::cout << "Hi" << std::endl;};
  l1(); // "Hi"
  
  // Use the input parameters passed by value
  auto l2 = [](int x, int y) {std::cout << x+y << std::endl;};
  l2(10,20);  // 30
  
  int num1 {100};
  int num2 {200};
  l2(num1, num2); // 300
  
  // Modify the input parameters by passing one by reference
  auto l3 = [](int &x, int y) 
  {
    std::cout << "local variables " << "x: " << x << " y: " << y << std::endl; // x:100 y:200
    x = 1000;
    y = 2000;
  };
  l3(num1, num2);
  std::cout << "Only change num1 - " << "num1: " << num1 << " num2: " << num2 << std::endl; // num1:1000 num2:200

  // Check if a number is even or odd
  auto l4 = [] (auto x) {return x % 2 == 0;};
  num1 = 5;
  if(l4(num1))
  {
    std::cout << num1 << " is even\n";
  }
  else
  {
    std::cout << num1 << " is odd\n";
  }
}

// Using value and reference objects as lambda parameters
void test3() 
{
  std::cout << "\n---Test3 objects as parameters--------------------------" << std::endl;

  Person stooge {"Larry", 18};
  std::cout << stooge << std::endl;
  
  auto l1 = [] (Person p)  { std::cout << p << std::endl;};
  l1(stooge);
  
  auto l2 = [] (const Person &p) { std::cout << p << std::endl;};
  l2(stooge);
  
  auto l3 = [] (Person &p) 
  {
    p.set_name("Frank");
    p.set_age(25);
    std::cout << p << std::endl; 
  };
  l3(stooge);
  
  std::cout << stooge << std::endl;
    
}

// used for test4
// using std::function as a parameter in C++14 and greater
// or 
// auto as parameter type in C++20
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)   {
//void filter_vector (const std::vector<int>  &vec, auto func) {
    std::cout <<"[ ";
    for (int i: vec) {
        if (func(i)) 
            std::cout << i  << " ";
    }
    std::cout << "]" << std::endl;
}

// passing a lambda to a function
void test4() {
    std::cout << "\n---Test4 --------------------------" << std::endl;
    std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};
    
    filter_vector(nums, [](int x) {return x>50;});
    
    filter_vector(nums, [](int x) {return x<=30;});
    
    filter_vector(nums, [](int x) {return x>= 30 && x <=60;});
}

// used for test5
auto make_lambda() {
	return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};
}

// returning a lambda from a function
void test5() {
	std::cout << "\n---Test5 --------------------------" << std::endl;
	
	auto l5 = make_lambda();
	
	l5();
}

// using auto in the lambda parameter list
void test6() {
    std::cout << "\n---Test6 --------------------------" << std::endl;
    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };
    
    l6(10,20);
    l6(100.3, 200);
    l6(12.5, 15.54);
    
    l6 (Person("Larry", 18), Person("Curly", 22));
}

// Simple lambda examples with std::sort and std::for_each
void test7() {
      std::cout << "\n---Test7 --------------------------" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_name() < p2.get_name();
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;
    });
    
    std::cout << std::endl;
    
     std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age()< p2.get_age();
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;
    });
}

int main()
{
  test1();
  test2();
  test3();
  // test4();
  // test5();
  // test6();
	// test7();
    
  std::cout << std::endl;
	return 0;
}
