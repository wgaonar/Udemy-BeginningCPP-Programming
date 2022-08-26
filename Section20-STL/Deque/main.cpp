// Section 20
// Deque
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

// template function to display any deque
template <typename T>
void display(const std::deque<T> &d) 
{
  std::cout << "[ ";
  for (const auto &elem: d)
      std::cout << elem << " ";
  std::cout <<  "]"<< std::endl;
}

void test1() 
{
  std::cout << "\nTest1 - display()=========================" << std::endl;

  std::deque<int> d {1,2,3,4,5};
  display(d);
  
  std::deque<int> d1 (10, 100);    // ten 100s in the deque
  display(d1);
  
  d = {2,4,5,6};
  display(d);
  
  d[0]  = 100;
  d.at(1) = 200;
  display(d); // [100 200 5 6]
}

void test2() 
{
  // push and pops
  std::cout << "\nTest2 - .push_front()=========================" << std::endl;

  std::deque<int> d {0,0,0};
  display(d);
  
  d.push_back(10);
  d.push_back(20);
  display(d); // [ 0 0 0 10 20 ]
  
  d.push_front(100);
  d.push_front(200);
  display(d); // [200 100 0 0 0 10 20 ]
  
  std::cout << "Front: " << d.front() << std::endl; // 200
  std::cout << "Back : " << d.back() << std::endl;  // 20
  std::cout << "Size  : " << d.size() << std::endl; // 7
  
  d.pop_back();
  d.pop_front();
  display(d); // [ 100 0 0 0 10 ]
}

void test3() 
{
  // insert all even numbers into the back of a deque and all 
  // odd numbers into the front
  std::cout << "\nTest3 - .push_front() and .push_back() =============" << std::endl;
  
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;
  
  for (const auto &elem: vec) 
  {
    if (elem % 2 == 0)
    {
      d.push_back(elem);
    }
    else
    {
      d.push_front(elem);
    }
  }
  display(d); // [ 9 7 5 3 1 2 4 6 8 10 ]

  // Reorder the elements in a new deque
  std::deque<int> d1 (10, 0);
  for (size_t i = 0; i < d.size(); i++)
  {
    d1.at(d.at(i) - 1) = d.at(i);
  }
  display(d1);
}

void test4() 
{
  // push front vs. back ordering
  std::cout << "\nTest4 - front vs. back ordering================" << std::endl;

  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;
  
  for (const auto &elem: vec) 
  {
    d.push_front(elem);
  }    
  display(d); // [ 10 9 8 7 6 5 4 3 2 1 ]
  
  d.clear();
  
  for (const auto &elem: vec) 
  {
    d.push_back(elem);
  }
  display(d); // [ 1 2 3 4 5 6 7 8 9 10 ]
}

void test5() 
{
  // Same as test4 using std::copy
  std::cout << "\nTest5 - std::copy() std::front/back_inserter()========" << std::endl;

  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;
  
  std::copy(vec.begin(), vec.end(), std::front_inserter(d));
  display(d); // [ 10 9 8 7 6 5 4 3 2 1 ]
  
  d.clear();
  
  std::copy(vec.begin(), vec.end(), std::back_inserter(d));
  display(d); // [1 2 3 4 5 6 7 8 9 10]

  // copy the even numbers of vec at the front of d
  d.clear();  
  std::copy_if(vec.begin(), vec.end(), std::front_inserter(d),
          [](int x) { return x % 2 == 0; });
  display(d); // [ 10 8 6 4 2 ]

  // copy the odd numbers of vec at the back of d
  d.clear();  
  std::copy_if(vec.begin(), vec.end(), std::back_inserter(d),
          [](int x) { return x % 2 != 0; });
  display(d); // [ 1 3 5 7 9 ]
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

