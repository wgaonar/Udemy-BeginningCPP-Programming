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
  // Friend function to overload insertion operator "<<"
  friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
  std::string name;
  int age;

public:
  // Default constructor
  Person () {}

  // Delegate constructor
  Person(std::string name, int age) : name{name}, age{age} {}

  // Copy constructor
  // Person(const Person &p): name{p.name}, age{p.age} {} // Option 1: member by member
  Person(const Person &p) : Person {p.name, p.age} {} // Option 2: Using delegate constructor

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
  
  // Two ints parameter and instantiate with () at the end of the lambda expression
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
  
  // Pass an object by value -> It uses copy constructor
  auto l1_1 = [] (Person p)  { std::cout << p << std::endl;};
  l1_1(stooge);
  
  // Pass a const object by reference -> An alias to object
  auto l1_2 = [] (const Person &p) { std::cout << p << std::endl;};
  l1_2(stooge);
  
  // Pass an object by reference and modify it
  auto l1_3 = [] (Person &p) 
  {
    p.set_name("Frank");
    p.set_age(25);
    std::cout << p << std::endl; 
  };
  l1_3(stooge);
  
  std::cout << stooge << std::endl;
    
}

// used for test4
// using std::function as a parameter in C++14 and greater
// or 
// auto as parameter type in C++20
void filter_vector(const std::vector<int> &vec, std::function<bool (int)> func) // function object C++14
// void filter_vector (const std::vector<int> &vec, bool (*func) (int)) // function pointer C++14
// void filter_vector (const std::vector<int> &vec, auto func) // C++20
{
  std::cout <<"[ ";
  for (int i: vec) 
  {
    if (func(i))
    { 
      std::cout << i  << " ";
    }
  }
  std::cout << "]" << std::endl;
}

// passing a lambda to a function as a parameter
void test4() 
{
  std::cout << "\n---Test4 lambda as a parameter -----------------" << std::endl;
  std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};
  
  // Prints the nums greater than 50
  filter_vector(nums, [](int x) {return x>50;});
  
  // Prints the nums less equal than 30
  filter_vector(nums, [](int x) {return x<=30;});
  
  // Prints the nums greater equal than 30 and less equal than 60
  filter_vector(nums, [](int x) {return x>= 30 && x <=60;});
}

// used for test5 lambda function with no-args
std::function<void (void)> make_lambda() // function object C++14
// void (*make_lambda()) (void) // function pointer C++14
// auto make_lambda() // C++20
{
	return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};
}

// used for test5 lambda function with args
std::function<void (int, int)> make_lambda_with_args() // function object C++14
// void (*make_lambda_with_args()) (int, int) // function pointer C++14
// auto make_lambda_with_args() // C++20
{
	return [] (int x, int y) 
  {
    std::cout << "This lambda was made using the make_lambda_with_args function! ";
    std::cout << x << " / " << y << " = " << static_cast<double>(x) / y << std::endl;
  };
}

// used for test5 lambda function with args and return type
std::function<double (int, int)> make_lambda_with_args_and_return_type() // function object C++14
// double (*make_lambda_with_args_and_return_type()) (int, int) // function pointer C++14
// auto make_lambda_with_args_and_return_type() // C++20
{
	return [] (int x, int y)
  {
    std::cout << "This lambda was made using the make_lambda_with_args and return type function! ";
    double division {0.0};
    division = static_cast<double>(x) / y;
    std::cout << x << " / " << y << " = " << division << std::endl;
    return division;
  };
}

// returning a lambda from a function
void test5() {
	std::cout << "\n---Test5 Return a lambda from a function -------------------------" << std::endl;
	
  // Return a void lambda with no-args
	auto l5_1 = make_lambda();
	l5_1();

  // Return a void lambda with args
  auto l5_2 = make_lambda_with_args();
  l5_2(3,5);

  // Return a type from lambda with args
  auto l5_3 = make_lambda_with_args_and_return_type();
  double division = l5_3(3,5);
  std::cout << "The returned variable: division = " << division << std::endl; // 0.6
}

// using auto in the lambda parameter list
void test6() 
{
  std::cout << "\n---Test6 auto as input parameter --------------------------" << std::endl;
  auto l6 = [](auto x, auto y) {
      std::cout << "x: " << x << " y: " << y << std::endl;
  };
  
  l6(10,20);      // x: 10 y: 20
  l6(100.3, 200); // x: 100.3 y: 200
  l6(12.5, 15.54);  // x: 12.5 y:15.54
  
  l6 (Person("Larry", 18), Person("Curly", 22)); // x: [Person: Larry : 18] y: [Person: Curly : 22]
}

// Simple lambda examples with std::sort and std::for_each
void test7() 
{
  std::cout << "\n---Test7 std::sort std::for_each()--------------------------" << std::endl;

  std::vector<Person> stooges 
  {
    {"Larry", 18},
    {"Moe", 30},
    {"Curly", 25}
  };

  // Sort by name
  std::sort
  (
    begin(stooges), // Where to start, equivalent to stooges.begin()
    end(stooges),   // Where to end
    [](const Person &p1, const Person &p2) 
    {
      return p1.get_name() < p2.get_name(); // What to do using lambda expression
    } 
  );
  
  std::cout << "Sorted by name\n";
  std::for_each(begin(stooges), end(stooges), [](const Person &p) 
  {
    std::cout << p << std::endl;
  });
  std::cout << std::endl;
  
  // Sort by ages
  std::sort
  (
    begin(stooges), // Where to start, equivalent to stooges.begin()
    end(stooges),   // Where to end
    [](const Person &p1, const Person &p2) 
    {
      return p1.get_age() < p2.get_age(); // What to do using lambda expression
    }
  );
  
  std::cout << "Sorted by age\n";
  std::for_each(begin(stooges), end(stooges), [](const Person &p) 
  {
    std::cout << p << std::endl;
  });
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
	test7();
    
  std::cout << std::endl;
	return 0;
}
