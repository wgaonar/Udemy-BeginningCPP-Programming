// Section 20
// std::array
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // for more algorithms like accumulate

// Display the array -- note the size MUST be included
// when passing a std::array to a function
void display(const std::array<int, 5> &arr) 
{
  // Option 1: Using arr.size() member method
  std::cout << "[ ";
  for (std::size_t i = 0; i != arr.size(); i++)
  {
    std::cout << arr.at(i) << " ";
  }
  std::cout <<  "]"<< std::endl;

  // Option 2: Using a range-base for loop
  /* std::cout << "[ ";
  for (const auto &i: arr)
  {
    std::cout << i << " ";
  }
  std::cout <<  "]"<< std::endl; */
}

// Display the array in reverse order -- note the size MUST be included
// when passing a std::array to a function
void display_reverse(const std::array<int, 5> &arr) 
{
  // Option 1: Using reverse iterators
  std::cout << "[ ";
  for (auto i = arr.crbegin(); i != arr.crend(); i++)
  {
    std::cout << *i << " ";
  }
  std::cout <<  "]"<< std::endl;

  // Option 2: Using arr.size() member method
  /* std::cout << "[ ";
  for (std::size_t i = arr.size(); i--;)  // because size_t is ever a non-negative number
  {
    std::cout << arr.at(i) << " ";
  }
  std::cout <<  "]"<< std::endl; */
}

void test1() 
{
  std::cout << "\nTest1 - display=========================" << std::endl;
  std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} if C++ 11
  std::array<int, 5> arr2;
  
  display(arr1);          // [ 1 2 3 4 5 ]
  display(arr2);          // Elements are not initialized (contain 'garbage')

  display_reverse(arr1);  // [5 4 3 2 1 ]
  display_reverse(arr2);  // Elements are not initialized (contain 'garbage')
      
  arr2  = {10,20,30,40,50};

  display(arr1);
  display(arr2);
  
  std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       //5 
  std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       //5
  
  arr1[0] = 1000;
  arr1.at(1) = 2000;
  display(arr1);

  std::cout << "Front of arr2: " << arr2.front() << std::endl;        // 10
  std::cout << "Back of arr2: " << arr2.back() << std::endl;          // 50
}
 
void test2() 
{
  std::cout << "\nTest2 -fill and swap=========================" << std::endl;
  std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11
  std::array<int, 5> arr2 {10,20,30,40,50};
  
  display(arr1);
  display(arr2);
  
  arr1.fill(0);
  
  display(arr1);
  display(arr2);
  
  arr1.swap(arr2);
  
  display(arr1);
  display(arr2);
}

void test3() 
{
  std::cout << "\nTest3 - data->pointer =========================" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11
  display(arr1);

  int *ptr = arr1.data();
  std::cout << ptr << " contains: "<< *ptr << std::endl;

  *ptr = 10000;
  std::cout << ptr << " now contains: "<< *ptr << std::endl;
  display(arr1);
}

void test4() 
{
  std::cout << "\nTest4 - sorting=========================" << std::endl;

  std::array<int, 5> arr1 {2,1,4,5,3};     // double {{ }} is C++ 11
  display(arr1);
  
  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}

void test5() 
{
  std::cout << "\nTest5 - min and max=========================" << std::endl;

  std::array<int, 5> arr1 {2,1,4,5,3};     // double {{ }} is C++ 11

  std::array<int,5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
  auto max_num = std::max_element(arr1.begin(), arr1.end());
  std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

void test6() 
{
  std::cout << "\nTest6 - Find adjacent values=================" << std::endl;

  std::array<int, 7> arr1 {2,1,3,3,5,4,4};     // double {{ }} is C++ 11

  auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
  if (adjacent != arr1.end()) 
  {
    std::cout << "First adjacent element found with value: " << *adjacent << std::endl;
  }
  else
  { 
    std::cout << "No adjacent elements found" << std::endl;
  }

  // std::advance(adjacent,2); Option 1 to move the iterator
  adjacent += 2;
  while (adjacent != arr1.end())
  {
    adjacent = std::adjacent_find(adjacent, arr1.end());
    std::cout << "Other adjacent element found with value: " << *adjacent << std::endl;
    std::advance(adjacent,2);
  }
  
}

void test7() 
{
  std::cout << "\nTest7 - accumulate =========================" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};     // double {{ }} is C++ 11
  display(arr1);

  //accumulate is from #include <numeric>
  int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
  std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test8() 
{
  std::cout << "\nTest8 - count =========================" << std::endl;
  std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
  
  int count = std::count(arr1.begin(), arr1.end(), 3);
  std::cout << "Found 3 : " << count << " times" << std::endl;
}

void test9() 
{
  std::cout << "\nTest9 - count if =========================" << std::endl;
  std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300 ,400};
  
  // find how many numbers are between 10 and 200 ->  50,60,70,80
  int count = std::count_if(arr1.begin(), arr1.end(), [](int x) { return x>10 && x<200; });
                                          
  std::cout << "Found  " << count << " matches" << std::endl;
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
  
  return 0;
}

