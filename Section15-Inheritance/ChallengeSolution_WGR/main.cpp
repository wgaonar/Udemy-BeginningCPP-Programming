// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Account_Util.h"

using namespace std;

int main() 
{
  cout.precision(2);
  cout << fixed;
  
  // Accounts
  vector<Account> accounts;
  accounts.push_back(Account {});
  accounts.push_back(Account {"Larry"});
  accounts.push_back(Account {"Moe", 2000} );
  accounts.push_back(Account {"Curly", 5000} );
  
  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts,2000);
  
  // Savings Accounts
  vector<Savings_Account> sav_accounts;
  sav_accounts.push_back(Savings_Account {} );
  sav_accounts.push_back(Savings_Account {"Superman"} );
  sav_accounts.push_back(Savings_Account {"Batman", 2000} );
  sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  withdraw(sav_accounts, 2000);

  // Checking Accounts
  vector<Checking_Account> checking_accounts;
  checking_accounts.emplace_back(Checking_Account {} );
  checking_accounts.emplace_back(Checking_Account {"IronMan"} );
  checking_accounts.emplace_back(Checking_Account {"Captain America", 3000} );
  checking_accounts.emplace_back(Checking_Account {"Dr. Strange", 6000} );

  display(checking_accounts);
  deposit(checking_accounts, 1000);
  withdraw(checking_accounts, 2000);

  // Trust Accounts
  vector<Trust_Account> trust_accounts;
  trust_accounts.emplace_back(Trust_Account {} );
  trust_accounts.emplace_back(Trust_Account {"Aang"} );
  trust_accounts.emplace_back(Trust_Account {"Katara", 3000} );
  trust_accounts.emplace_back(Trust_Account {"Soka", 6000, 10.0});

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  deposit(trust_accounts, 5000);
  withdraw(trust_accounts, 100);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 2000);
  withdraw(trust_accounts, 4000); // Withdrawal #4 is NOT let!!!
    
  return 0;
}

