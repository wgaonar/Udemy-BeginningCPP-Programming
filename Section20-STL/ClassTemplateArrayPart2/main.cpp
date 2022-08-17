// Section 20
// Class template - Array of ANY type

// Note: Since C++11 the STL has std::array which is a template-based array class
// Use std::array instead of raw arrays whenever possible

// Note that we can have non-type template parameters
// That's what N is in this case

#include <iostream>
#include <string>

template <typename T, int N>
class Array 
{
private:
  int size {N};           // how do we get the N???
  T values[N];        // the N needs to ne known at compile-time!

  friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) 
  {
    os << "[ ";
    for (const auto &val: arr.values)
        os << val << " ";
    os << "]" << std::endl;
    return os;
  }
public:
  Array() = default;
  Array(T init_val) 
  {
    for (auto &item: values)
    {
      item = init_val;
    }
  }
  void fill(T val) 
  {
    for (auto &item: values )
    {
      item = val;
    }
  }
  int get_size() const 
  {
    return size;
  }

  // overloaded subscript operator for easy use
  // this lets to code "array[index] = data of type T" instead of "array.operator[](index) = data of type T"
  T &operator[](int index) 
  {
    return values[index];
  }
};

int main() 
{
    
  Array<int, 5> nums; 
  nums.fill(10);
  std::cout << nums << std::endl;             // [ 10 10 10 10 10 ]

  nums[0] = 1000;
  nums[3] = 2000;
  std::cout << nums << std::endl;             // [ 1000 10 10 2000 10 ]
  
  Array<int, 100> nums2 {1};                    
  std::cout << "The size of nums2 is: "<< nums2.get_size() << std::endl;    // 100
  std::cout << nums2 << std::endl;                                          // [ 1 1 1 1 ... 1 ]

  Array<std::string, 10> strings(std::string{"Frank"}); 
  std::cout << "The size of strings is: "<< strings.get_size() << std::endl;  // 10
  std::cout << strings << std::endl;                                          // [Frank Frank ... Frank ]
  
  strings[0] = std::string{"Larry"};
  std::cout << strings << std::endl;                                          // [Larry Frank ... Frank ]
  
  strings[1] = "Moe";                                                         // Initialize in C-style string works too
  std::cout << strings << std::endl;                                          // [Larry Moe ... Frank ]
  
  strings.fill(std::string{"X"});                                             
  std::cout << strings << std::endl;                                          // [X X ... X ]

  return 0;
}

