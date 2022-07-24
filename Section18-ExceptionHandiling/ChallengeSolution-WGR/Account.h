// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include <exception>
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

class Account : public I_Printable 
{
private:   
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;
protected:
  std::string name;
  double balance;
public:
  // Constructor
  Account(std::string name = def_name, double balance = def_balance);

  // Getters
  virtual std::string get_name() const;

  // Modifiers
  virtual bool deposit(double amount) = 0;  // Must be implemented in the inherited classes
  virtual bool withdraw(double amount) = 0; // Must be implemented in the inherited classes
  virtual void print(std::ostream &os) const override;
  virtual ~Account() = default;
};
#endif