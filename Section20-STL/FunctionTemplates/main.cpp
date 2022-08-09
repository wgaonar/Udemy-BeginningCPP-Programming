// Section 20
// Displaytion templates
#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) 
{
  return (a < b) ? a : b;
}

template <typename T1, typename T2>
void Display(T1 a, T2 b) 
{
  std::cout << a << " " << b << std::endl;
}

struct Person 
{
  std::string name;
  int age;

  // Overload less than operator "<"
  bool operator<(const Person &rhs) const 
  {
    return this->age < rhs.age;
  }
};

// Overload the insertion operator "<<"
std::ostream &operator<<(std::ostream &os, const Person &p) 
{
  os << p.name;
  return os;
}

template <typename T>
void my_swap(T &a, T &b) 
{
  T temp = a;
  a = b;
  b = temp;
}

int main() 
{
  std::cout << "\n--Compare two primitive data of the same type------\n";
  std::cout << min<int>(2,3) << std::endl;        // 2
  std::cout << min(2,3) << std::endl;             // 2
  std::cout << min('A', 'B') << std::endl;        // A
  std::cout << min(12.5, 9.2) << std::endl;       // 9.2
  std::cout << min(5+2*2, 7+40) << std::endl;     // 9

  std::cout << "\n--Compare two user defined data of the same type------\n";
  Person p1 {"Curly", 15};
  Person p2 {"Moe", 30};
  Person p3 = min(p1, p2);
  std::cout << p3.name << " is younger" << std::endl;
  Display(p1, p2);                                // Curly Moe

  std::cout << "\n--Display two different data in the same template function------\n";
  Display<int,int>(10,20);
  Display(10,20);
  Display<char, double>('A', 12.4);
  Display('A', 12.4);
  Display(1000, "Testing");
  Display(2000, std::string{"Frank"});
  
  std::cout << "\n--Swap two data types by reference------\n";
  int x{100};
  int y{200};
  std::cout << x << ", " << y << std::endl;       // 100, 200
  my_swap(x, y);
  std::cout << x << ", " << y << std::endl;       // 200, 100
    
  return 0;
}

