// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account 
{
  friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:   
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;

protected:
  std::string name;
  double balance;
  
public:
  // Option 1: Delegate constructor with default initializer parameters 
  // Using static constexpr defined in the class
  Account(std::string name = def_name, double balance = def_balance); // Option 1
  
  // Option 2: Delegate constructor with default initializer parameters 
  // Classical inline way
  // Account(std::string name = "Unamed Account", double balance = 0.0);

  // Methods
  bool deposit(double amount);
  bool withdraw(double amount);
  double get_balance() const;
};
#endif