#include "Account.h"

Account::Account(std::string name, double balance) 
                : name{name}, balance{balance} 
{}

// It is not necessary but it is util for generic methods that the
// inherited class can use
bool Account::deposit(double amount) 
{
  if (amount < 0) 
    return false;
  else 
  {
    balance += amount;
    return true;
  }
}

// It is not necessary but it is util for generic methods that the
// inherited class can use
bool Account::withdraw(double amount) 
{
  if (balance-amount >=0) 
  {
    balance-=amount;
    return true;
  } 
  else
    return false;
}

void Account::print(std::ostream &os) const
{
  os.precision(2);
  os << std::fixed;
  os << "[Account: " << name << ": " << balance << "]";
}
