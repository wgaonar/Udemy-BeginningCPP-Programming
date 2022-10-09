#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

/* 
  Trust Account is a type of Savings Account. But:
    It adds a bonus of $50.00 by each deposit of $5000.00 of more.
    It only lets 3 withdrawals per year and each one is limited to 20% or less of the balance

  Withdraw:
    Limited to 20% of the balance and only 3 withdrawals by year.

  Deposit:
    Amount supplied to deposit will be incremented by (amount * int_rate/100). Besides, a bonus
    of $50.00 will be added if the deposit amount is $5000.0 or more and then the updated 
    amount will be deposited
 */

class Trust_Account: public Savings_Account 
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Trust Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  const double bonus = 50.0;
  int num_withdrawals = 0;
  const int max_withdrawals = 3;

public:
  // Option 1: Delegate constructor with default initializer parameters 
  // Using static constexpr defined in the class
  Trust_Account(std::string name = def_name, 
                  double balance = def_balance, 
                  double int_rate = def_int_rate);

  // Option 2: Delegate constructor with default initializer parameters 
  // Classical inline way
  // Trust_Account(std::string name = "Unamed Account", 
  //                 double balance = 0.0,
  //                 double int_rate = 0.0);    
  
  /*   
    Overload deposit method
    @param double
    @return bool 
  */
  bool deposit(double amount);

  /*   
    Overload deposit method
    @param double
    @return bool  
  */
  bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
