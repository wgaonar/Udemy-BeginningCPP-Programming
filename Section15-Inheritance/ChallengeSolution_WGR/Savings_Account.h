#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

/* 
  Savings Account is a type of Account. It adds an interest rate.

  Withdraw - same as a regular account

  Deposit:
    Amount supplied to deposit will be incremented by (amount * int_rate/100) 
    and then the updated amount will be deposited
 */

class Savings_Account: public Account 
{
  friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);

private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    double int_rate;

public:
  // Option 1: Delegate constructor with default initializer parameters 
  // Using static constexpr defined in the class
  Savings_Account(std::string name = def_name, 
                  double balance = def_balance, 
                  double int_rate = def_int_rate);

  // Option 2: Delegate constructor with default initializer parameters 
  // Classical inline way
  // Savings_Account(std::string name = "Unamed Account", 
  //                 double balance = 0.0,
  //                 double int_rate = 0.0);    
  
  /*   
    Overload deposit method
    @param double
    @return bool  
  */
  bool deposit(double amount);
  
  // Inherits the Account::withdraw method
};

#endif // _SAVINGS_ACCOUNT_H_
