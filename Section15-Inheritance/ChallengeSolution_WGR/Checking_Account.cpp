#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance}
{}

/* 
  Withdraw:
  Amount supplied to deposit will be incremented by (amount * int_rate/100) 
  and then the updated amount will be deposited.
  It uses the base class method -Account::deposit- to update the balance 
*/
bool Checking_Account::withdraw(double amount) 
{
  amount += fee_withdrawal;
  return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) 
{
  os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
  return os;
}

