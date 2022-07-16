// Section 17
// Unique Pointers 
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test 
{
private:
  int data;
public:
  // Default constructor
  Test() : data{0} 
  { 
    std::cout << "Test constructor (" << data << ")" << std::endl; 
  }

  // Override constructor
  Test(int data) : data {data} 
  { 
    std::cout << "Test constructor (" << data << ")" << std::endl; 
  }

  // Accessor Methods
  int get_data() const 
  {
    return data; 
  }

  // Destructor
  ~Test() 
  {
    std::cout << "Test destructor (" << data << ")" << std::endl; 
  }
};

int main() 
{
  std::cout << "\n--------------------------\n";
  Test *t1 = new Test {1000};
  delete t1;

  std::cout << "\n--------------------------\n";
  std::unique_ptr<Test> t2 {new Test{2000}};

  std::unique_ptr<Test> t3 = std::make_unique<Test>(3000);

  std::unique_ptr<Test> t4;
  t4 = std::move(t2);
  if (!t2)
  {
    std::cout << "t2 is nullptr" << std::endl;
  }

  auto t5 = std::make_unique<Test>(5000);
  
  std::cout << "\n--------------------------\n";
  std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
  std::cout << *a1 << std::endl;
  a1->deposit(5000);
  std::cout << *a1 << std::endl;

  std::cout << "\n--------------------------\n";
  std::vector<std::unique_ptr<Account>> accounts;
  accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
  accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
  accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));

  std::unique_ptr<Account> acc1 = std::make_unique<Checking_Account>("Wilmer", 1000);
  // accounts.push_back(acc1); // error: unique_prt does not admit copy, only move
  accounts.push_back(std::move(acc1)); 

  for (const auto &acc: accounts) // &acc because we can't copy unique_prt, only move
  {    
    std::cout << *acc << std::endl;
  }
  return 0;
}

