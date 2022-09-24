#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};

// Capture by value
// The global variable global_x cannot be captured because it is not 
// within the reaching scope of the lambda. It can however still be accessed 
// from within the lambda using normal name lookup rules.
void test1()
{
	std::cout << "\n---Test1 local and global variables ---------------" << std::endl;
	
	int local_x {100};
	
	auto l = [local_x] () 
  {
		std::cout << "local_x: " << local_x << std::endl;
		std::cout << "global_x: " << global_x << std::endl;
	};
	l(); // "local_ x: 100 global_x: 1000
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to 
// the captured variable within the lambda body and not the actual variable.
void test2()
{
	std::cout << "\n---Test2 capture by value - mutable ------" << std::endl;
	
	int x {100};
	
  // mutable to be able to modify the capture "x" variable overriding the "const"
  // definition of operator () in the created function object 
	auto l = [x] () mutable  
  {
		x += 100;
		std::cout << "x: " << x << std::endl;  
	};
    
	l();  // x: 200
	
  std::cout << "x: " << x << std::endl;    // 100 because is the out of scope the "x" variable
    
  l();  // 300 because the lambda acts as a call to operator() 
        // of the created function object and keeps the updated value on its "x" member 
  
  std::cout << "x: " << x << std::endl;    // 100 because is the out of scope the "x" variable
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void test3()
{
	std::cout << "\n---Test3 capture by reference--------------" << std::endl;
	
	int x {100};
	
	auto l = [&x] () mutable
  {
		x += 100;
		std::cout << "x: " << x << std::endl;  
	};
    
	l();  // x: 200
	std::cout << "x: " << x << std::endl;  // x: 200
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void test4()
{
	std::cout << "\n---Test4 default capture by value--------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [=] () mutable 
  {
		x += 100;
		y += 100;
		z += 100;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "z: " << z << std::endl;
	};
  std::cout << "\nThe first call to l();\n";
	l(); // x: 200 y: 300 z: 400

  std::cout << "\nThe second call to l();\n";
	l(); // x: 300 y: 400 z: 500
	
  std::cout << "\nLocal variables outside of the lambda\n";
	std::cout << "x: " << x << std::endl; // x: 100
	std::cout << "y: " << y << std::endl; // y: 200
	std::cout << "z: " << z << std::endl; // z: 300
}

// Default capture by reference
// This time because all three variables - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void test5()
{
	std::cout << "\n---Test5 default capture by reference------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [&] () {
		x += 100;
		y += 100;
		z += 100;
		std::cout << "x: " << x << std::endl; // x: 200
		std::cout << "y: " << y << std::endl; // y: 300
		std::cout << "z: " << z << std::endl; // z: 400
	};
	l();
	
	std::cout << "\n";
	std::cout << "x: " << x << std::endl;  // x: 200
	std::cout << "y: " << y << std::endl;  // y: 300
	std::cout << "z: " << z << std::endl;  // z: 400
}

// Default capture by value, capture "y" by reference
void test6()
{
	std::cout << "\n---Test6 Individual capture by reference ---------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [=, &y] () mutable {
		x += 100;
		y += 100;
		z += 100;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "z: " << z << std::endl;
	};
	l(); // x: 200 y: 300 z: 400
	
	std::cout << "\n";
	std::cout << "x: " << x << std::endl; // x: 100
	std::cout << "y: " << y << std::endl; // y: 300
	std::cout << "z: " << z << std::endl; // z: 300
}

// Default capture by reference, capture x and z by value
// Equivalent to test6
void test7()
{
	std::cout << "\n---Test7 Individual capture by value----------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [&, x, z] () mutable 
  {
		x += 100;
		y += 100;
		z += 100;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "z: " << z << std::endl;
	};
	l(); // x: 200 y: 300 z: 400
	
	std::cout << "\n";
	std::cout << "x: " << x << std::endl; // x: 100
	std::cout << "y: " << y << std::endl; // y: 300
	std::cout << "z: " << z << std::endl; // z: 300
}

// Used for test8
class Lambda 
{
private:
	int y;
public:
  // Delegate constructor
	Lambda(int y) : y{y} {}
	
  // Overload function operator "()"
	void operator() (int x) const 
  {
		std::cout << x + y << std::endl;
	}
};

// Lambda class equivalence example
void test8()
{
	std::cout << "\n---Test8 function object vs lambda expression------" << std::endl;
	
	int y {100};
	
  // Output using a function object
	Lambda lambda1(y);
	lambda1(200); // 300

	// Same output but using a lambda expression
	auto lambda2 = [y] (int x) {std::cout << x + y << std::endl;};
	lambda2(200); // 300
}

// Used for test9 and test10
class Person 
{
  // Friend function to overload insertion operator "<<"
	friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
  std::string name;
  int age;

public:
  // Default constructor
  Person() = default;

  // Delegate constructor
  Person(std::string name, int age) : name{name}, age{age} {}

  // Copy constructor
  // Person(const Person &p): name{p.name}, age{p.age} {} // Option 1: member by member
  // Person(const Person &p) : Person {p.name, p.age} {} // Option 2: Using delegate constructor
  Person(const Person &p) = default; // Option 3: Using default option

  // Force a compile to generate the destructor
  ~Person() = default;

  // Getters
  std::string get_name() const { return name; }
  int get_age() const {return age; }

  // Setters
  void set_name(std::string name) {this->name = name; };
  void set_age(int age) {this->age = age; }
	
  // Return a lambda expression for changing the name and age in the main function
  // using "this" pointer as a captured object. It is the PREFERRED way!!!
	auto change_person1() 
  {
    return [this] (std::string new_name, int new_age) 
    {
      // Option 1: With direct assignment
      // name = new_name;
      // age = new_age;

      // Option 2: Using setters
      set_name(new_name);
      set_age(new_age);
    };
  }

  /* 
    Return a lambda expression for changing the name and age in the main function
    with object captured by-reference and NOT by value in the context of a class. 
    That's the way [=] was defined when capturing an object. So confusing!!!
    NOTE: It has been deprecated in C++20
  */
	auto change_person2() 
  {
    return [=] (std::string new_name, int new_age) 
    {
      // Option 1: With direct assignment
      // name = new_name;
      // age = new_age;

      // Option 2: Using setters
      set_name(new_name);
      set_age(new_age);
    };
  }

  // Return a lambda expression for changing the name and age in the main function 
  // with object captured by reference
	auto change_person3() 
  {
    return [&] (std::string new_name, int new_age) 
    {
      // Option 1: With direct assignment
      // name = new_name;
      // age = new_age;

      // Option 2: Using setters
      set_name(new_name);
      set_age(new_age);
    };
  }    
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) 
{
  os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
  return os;
}

// Default capture by reference of the current object using [this]
// [=], [&], and [this] are equivalent when capturing an object's member variables - all are captured by reference
// Notre that capturing this with [=] has been deprecated in C++20
// Also, C++20 allows [*this], which captures by value!
void test9()
{
	std::cout << "\n---Test9 Class Person Example--------------------" << std::endl;

	Person stooge1("Larry", 18);
	std::cout << stooge1 << std::endl; // [Larry : 18]

  // Default capture [this]
  // This is the preferred way
	auto change_person1 = stooge1.change_person1();
	change_person1("Moe", 30);
	std::cout << stooge1 << std::endl; // [Moe : 30]
	
	// Default capture [=] 
  // NOTE: It has been deprecated in C++20
	auto change_person2 = stooge1.change_person2();
	change_person2("Curly", 25);
	std::cout << stooge1 << std::endl;  // [Curly : 25]
	
	// Default capture [&]
	auto change_person3 = stooge1.change_person3();
	change_person3("Frank", 34);
	std::cout << stooge1 << std::endl; // [Frank : 34]
}

// Class used in the test10() example
class People 
{
private:
  std::vector<Person> people;
  int max_people;

public:
  // Delegate constructor
  People(int max=10) : max_people(max) {}

  // Copy constructor
  // People (const People &p): max_people{p.max_people} {} // Option 1: member by member
  // People(const People &p) : People {p.max_people} {} // Option 2: Using delegate constructor
  People(const People &p) = default; // Option 3: Using default option
 
  // Force a compile to generate the destructor
  ~People() = default;

  // Getters
  int get_max_people() const 
  {
    return max_people;
  }

  // Setters
  void set_max_people(int max) 
  {
    max_people = max;
  }

  // Add a Person object to the member's vector of people 
  void add(std::string name, int age) 
  {
    people.emplace_back(name, age); // Instead of .push_back() who is NOT recommend for objects
  }

  // This method returns a vector of Person objects in
  // people whose age > max_age AND it limits the number of 
  // persons returned to be <= the member variable max_people.
  std::vector<Person> get_people(int max_age) 
  {
    std::vector<Person> result;
    int count{0};
    std::copy_if( people.begin(), // Source: Where to start
                  people.end(),   // Source: Where to end
                  std::back_inserter(result), // Dest: Where to put the copy
                  [this, &count, max_age](const Person &p)
                  { 
                    return p.get_age() > max_age &&  ++count <= max_people;
                  }
                );
    return result;
  }
};

void test10() 
{
  std::cout << "\n---Test10 Class People Example---------------" << std::endl;

  People friends;

  // Add persons to friends object
  friends.add("Larry", 18);
  friends.add("Curly", 25);
  friends.add("Moe", 35);
  friends.add("Frank", 28);
  friends.add("James", 65);
  
  // Declare a vector of max 10 (default class value) persons which age are >= 17 
  auto result = friends.get_people(17);
  
  // Print the first ten persons which are older than 17
  for (const auto &p: result)
  {
    std::cout << p << std::endl;
  }

  // Set the maximum number of persons to three    
  friends.set_max_people(3);
  
  // Initialize the vector with max three persons which age are >= 17 
  result = friends.get_people(17);
  
  // Print the first three persons which are older than 17
  std::cout << std::endl;
  for (const auto &p: result)
  {
    std::cout << p << std::endl;
  }
      
  // Initialize the vector with max three persons which age are >= 50
  result = friends.get_people(50);
  
  // Print the first three persons which are older than 50
  std::cout << std::endl;
  for (const auto &p: result)
  {
    std::cout << p << std::endl;
  }

  // Add more persons
  friends.add("Luis Adrián", 40);
  friends.add("Leslie", 35);
  friends.add("Wilmer", 39);
  friends.add("Abraham", 35);
  friends.add("Lupita", 65);

  // Initialize the vector with max three persons which age are >= 30
  result = friends.get_people(30);

  // Print the first three persons which are older than 30
  std::cout << std::endl;
  for (const auto &p: result)
  {
    std::cout << p << std::endl;
  }

  // Set the maximum number of persons to on hundred    
  friends.set_max_people(100);

  // Initialize the vector with max one hundred persons which age are >= 30
  result = friends.get_people(30);

  // Print the first one hundred persons which are older than 30
  std::cout << std::endl;
  for (const auto &p: result)
  {
    std::cout << p << std::endl;
  }
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
	test8();
	test9();
  test10();
	
	std::cout << "\n";
	return 0;
}