// Section 20
// Iterators
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) 
{
  std::cout << "[ ";
  for (auto const &i: vec) 
  {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}

// display any vector of integers using for traditional loop
void display_with_for(const std::vector<int> &vec) 
{
  std::cout << "[ ";
  for (auto  it = vec.begin(); it != vec.end(); it++) // it != vec.end(); is equivalent to: it < vec.end();
  {
    std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
}

// display any vector of integers using while loop
void display_with_while(const std::vector<int> &vec) 
{
  auto it = vec.begin();

  std::cout << "[ ";
  while (it != vec.end())   // Equivalent to: while (it < vec.end())
  {
    std::cout << *it << " ";
    it++;
  }
  std::cout << "]" << std::endl;
}

void test1() 
{
  std::cout << "\n==Test 1===========================" << std::endl;
  std::vector<int> nums1 {1, 2, 3, 4, 5};

  display(nums1);
  display_with_for(nums1);

  auto it = nums1.begin();                    // point to 1
  std::cout << *it << std::endl;

  it++;                                       // point to 2
  std::cout << *it << std::endl;      

  it += 2;                                    // point to 4
  std::cout << *it << std::endl;

  it -= 2;                                    // point to 2
  std::cout << *it << std::endl;

  it = nums1.end() - 1;                       // point to 5
  std::cout << *it << std::endl;
}

void test2() 
{
  std::cout << "\n==Test 2===========================" << std::endl;
  // display all vector elements using an iterator
  
  std::vector<int> nums1 {1, 2, 3, 4, 5};

  display_with_while(nums1);
  
  // change all vector elements to 0
  std::vector<int>::iterator it = nums1.begin();  // Equivalent to: auto it = nums1.begin();
  while (it != nums1.end()) 
  {
    *it = 0;
    it++;
  }

  display(nums1);
}

void test3() 
{
  std::cout << "\n==Test 3===========================" << std::endl;
    
  // using a const_iterator
  std::vector<int> nums1 {1, 2, 3, 4, 5};

  std::vector<int>::const_iterator it1 = nums1.cbegin();   // Equivalent to: auto it1 = nums1.cbegin();
  
  display_with_while(nums1);
  
  // compiler error when we try to change element
  it1 = nums1.cbegin();
  while (it1 != nums1.end()) 
  {
    // *it1 = 0;   // Complier error - read only
    it1++;
  }

}

void test4() 
{
  std::cout << "\n==Test 4===========================" << std::endl;

  std::vector<int> nums1 {1,2,3,4,5};
  display_with_while(nums1);

  // reverse iterator over vector of ints starts at 5
  std::vector<int>::reverse_iterator it1 = nums1.rbegin();   // Equivalent to: auto it1  = nums1.rbegin();
     
  // using a reverse iterator
  std::cout << "[ ";
  while (it1 != nums1.rend())
  {
    std::cout << *it1 << " ";
    it1++;            // Note the increment in the iterator, i.e., traversing the vector from right to left
  }
  std::cout << "]" << std::endl;

  // const reverse iterator over a list
  std::list<std::string> names {"Larry", "Moe", "Curly"};
  
  auto it2 =names.crbegin();    // iterator over list of strings  point to Curly
  std::cout << *it2 << std::endl;
  
  it2++;  // point to Moe
  std::cout << *it2 << std::endl;

  // iterator over a map
  std::map<std::string, std::string> favorites {
      {"Frank", "C++"},
      {"Bill", "Java"},
      {"James", "Haskell"}
  };

  auto it3 = favorites.begin();   // iterator over map of string, string pairs

  while (it3 != favorites.end()) 
  {
    std::cout << it3->first << " : " << it3->second << std::endl;
    it3++;
  }
}

void test5() 
{
  std::cout << "\n==Test 5===========================" << std::endl;

  // iterate over a subset of a container
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  auto start = vec.begin() + 2;
  auto finish = vec.end() - 3;
  
  std::cout << "[ ";
  while (start != finish)   // Equivalent to: while (start < finish)
  {
    std::cout << *start << " ";
    start++;
  }
  std::cout << "]" << std::endl;  
}

int main() 
{
  test1();
  test2();
  test3();
  test4();
  test5();
  return 0;
}