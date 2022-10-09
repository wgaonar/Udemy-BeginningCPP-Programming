#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_withdrawals {0} 
{}

/* 
  Deposit:
  Amount supplied to deposit will be incremented in the SAME WAY that
  a Savings_Account unless, if the amount is $5000.00 or more, a bonus of $50.00 will added. 
  and then the updated amount will be deposited.
  It uses the derived class method -Savings_Account::deposit- to update the balance 
*/
bool Trust_Account::deposit(double amount) 
{
  if (amount >= bonus_threshold)
  {
    amount += bonus_amount;
  }
  return Savings_Account::deposit(amount);
}

/* 
  Withdraw:
  Amount will be limited to 20% of the balance.
  Besides, this Trust account only lets 3 withdrawals per year.
  It uses the base class method -Account::withdraw to update the balance 
*/
bool Trust_Account::withdraw(double amount) 
{
  if (num_withdrawals < max_withdrawals && amount <= this->balance * (max_withdraw_percent/100))
  {
    num_withdrawals++;
    return Savings_Account::withdraw(amount);
  }
  else
  {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) 
{
  os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
  return os;
}

