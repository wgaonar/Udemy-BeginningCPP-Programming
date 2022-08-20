// Section 20
// Class template - Array of Ints

// Note: Since C++11 the STL has std::array which is a template-based array class
// Use std::array instead of raw arrays whenever possible

// Note that we can have non-type template parameters
// That's what N is in this case

#include <iostream>
#include <string>

template <int N>
class Array 
{
private:
  int size {N};           // how do we get the N???
  int values[N];          // the N needs to ne known at compile-time! -> For this we use the template!!!

  friend std::ostream &operator<<(std::ostream &os, const Array<N> &arr) 
  {
    os << "[ ";
    for (const auto &val: arr.values)
        os << val << " ";
    os << "]" << std::endl;
    return os;
  }

public:
  Array() = default;

  Array(int init_val) 
  {
    for (auto &item: values)
    {
      item = init_val;
    }
  }

  void fill(int val) 
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
  // this lets to code "array[index] = number" instead of "array.operator[](index) = number"
  int &operator[](int index) 
  {
    return values[index];
  }
};


int main() 
{
  Array<5> nums;
  std::cout << "\nThe size of nums is: "<< nums.get_size() << std::endl;    // 5
  std::cout << nums << std::endl;                                         // Array of 5 ints with garbage as its values
  
  nums.fill(0);
  std::cout << "The size of nums is: "<< nums.get_size() << std::endl;    // 5
  std::cout << nums << std::endl;                                         // [ 0 0 0 0 0 0 ]
  
  nums.fill(10);
  std::cout << nums << std::endl;                                         // [ 10 10 10 10 10 ]

  nums[0] = 1000;                                                         // [ 1000 10 10 2000 10 ]
  nums[3] = 2000;
  std::cout << nums << std::endl;
  
  Array<100> nums2 {1};
  std::cout << "The size of nums2 is: "<< nums2.get_size() << std::endl;  // 100
  std::cout << nums2 << std::endl;                                        // [ 1 1 1 1 ... 1 ]

  return 0;
}

