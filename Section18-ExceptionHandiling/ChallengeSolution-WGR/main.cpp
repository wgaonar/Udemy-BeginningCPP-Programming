#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() 
{
  // Declare an account
  std::unique_ptr<Account> moes_account; 
  try 
  {
    // Try to create an account with negative balance
    moes_account = std::make_unique<Checking_Account>("Moe", -100.0);
    std::cout << *moes_account << std::endl;
  }
  catch (const IllegalBalanceException &ex)
  {
    std::cerr << ex.what() << std::endl;
  }

  // Declare another account
  std::unique_ptr<Account> larrys_account;
  try
  {
    larrys_account = std::make_unique<Savings_Account>("Larry", 200);
    std::cout << *larrys_account << std::endl;

    larrys_account->withdraw(100);
    std::cout << *larrys_account << std::endl;

    // Try to make a witdrawal exceeding the funds
    larrys_account->withdraw(500);
    std::cout << *larrys_account << std::endl;
  }
  catch (const IllegalBalanceException &ex)
  {
    std::cerr << ex.what() << std::endl;
  }
  catch(const InsufficentFundsException &ex)
  {
    std::cerr << ex.what() << std::endl;
  }
  
  std::cout << "Program completed successfully" << std::endl;
  return 0;
}

