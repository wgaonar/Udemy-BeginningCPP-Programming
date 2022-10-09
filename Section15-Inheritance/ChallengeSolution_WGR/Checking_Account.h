#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

/* 
  Checking Account is a type of Account. It adds a fee of $1.50 per withdrawal transaction.

  Withdraw:
    In each withdrawal transaction an additional fee of $1.50 will be deducted from the balance

  Deposit  - same as a regular account
 */

class Checking_Account: public Account 
{
  friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double fee_withdrawal = 1.5;

public:
  // Option 1: Delegate constructor with default initializer parameters 
  // Using static constexpr defined in the class
  Checking_Account(std::string name = def_name, 
                  double balance = def_balance);

  // Option 2: Delegate constructor with default initializer parameters 
  // Classical inline way
  // Checking_Account(std::string name = "Unamed Account", 
  //                 double balance = 0.0);    
  
  // Inherits the Account::deposit method

  /*   
    Overload withdraw method
    @param double
    @return bool  
  */
  bool withdraw(double amount);
};

#endif // _CHECKING_ACCOUNT_H_
