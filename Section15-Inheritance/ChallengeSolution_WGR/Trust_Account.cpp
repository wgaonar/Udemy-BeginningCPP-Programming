#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate} 
{}

/* 
  Deposit:
  Amount supplied to deposit will be incremented by (amount * int_rate/100).
  Besides, if the amount is $5000.00 or more, a bonus of $50.00 will added. 
  and then the updated amount will be deposited.
  It uses the base class method -Account::deposit- to update the balance 
*/
bool Trust_Account::deposit(double amount) 
{
  if (amount >= 5000)
  {
    amount += amount * (int_rate/100) + bonus;
  }
  else
  {
    amount += amount * (int_rate/100);
  }
  return Account::deposit(amount);
}

/* 
  Withdraw:
  Amount will be limited to 20% of the balance.
  Besides, this Trust account only lets 3 withdrawals per year.
  It uses the base class method -Account::withdraw to update the balance 
*/
bool Trust_Account::withdraw(double amount) 
{
  if (num_withdrawals < max_withdrawals)
  {
    if (amount <= this->balance * 0.2)
    {
      num_withdrawals++;
      return Account::withdraw(amount);
    }
  }
  
  return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) 
{
  os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
  return os;
}

