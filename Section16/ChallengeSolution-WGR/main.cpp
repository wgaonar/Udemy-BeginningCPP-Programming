// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() 
{ 
  // Static binding
  Checking_Account c;
  cout << c << endl;

  Savings_Account s{"Frank", 5000, 2.6};
  cout << s << endl;
  s.deposit(10000);
  cout << s << endl;
  s.withdraw(10000);
  cout << s << endl;

  // dynamic binding
  Account *ptr = new Trust_Account{"Leo", 10000, 2.6};
  cout << *ptr << endl;

  // Vector of pointers for dynamic binding
  Account *p1 = new Checking_Account{"Larry", 10000};
  Account *p2 = new Savings_Account{"Moe", 1000};
  Account *p3 = new Trust_Account{"curly"};
  
  vector<Account *> accounts {p1,p2,p3};
    
  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts,2000);
    
  // Savings 
  vector <Account *> sav_accounts;
  Account *svptr1 = new Savings_Account {};
  Account *svptr2 = new Savings_Account {"Superman"};
  Account *svptr3 = new Savings_Account {"Batman", 2000};
  Account *svptr4 = new Savings_Account {"Wonderwoman", 5000, 5.0};

  sav_accounts.push_back(svptr1);
  sav_accounts.push_back(svptr2);
  sav_accounts.push_back(svptr3);
  sav_accounts.push_back(svptr4);

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  withdraw(sav_accounts,2000);
   
  // Checking
  vector <Account *> check_accounts;
  Account *chptr1 = new Checking_Account {}; 
  Account *chptr2 = new Checking_Account {"Kirk"}; 
  Account *chptr3 = new Checking_Account {"Spock", 2000}; 
  Account *chptr4 = new Checking_Account {"Bones", 5000}; 

  check_accounts.push_back(chptr1);
  check_accounts.push_back(chptr2);
  check_accounts.push_back(chptr3);
  check_accounts.push_back(chptr4);

  display(check_accounts);
  deposit(check_accounts, 1000);
  withdraw(check_accounts, 2000);

  // Trust
  vector <Account *> trust_accounts;
  Account *thptr1 = new Trust_Account {};
  Account *thptr2 = new Trust_Account {"Athos", 10000, 5.0};
  Account *thptr3 = new Trust_Account {"Porthos", 20000, 4.0};
  Account *thptr4 = new Trust_Account {"Aramis", 30000};

  trust_accounts.push_back(thptr1);
  trust_accounts.push_back(thptr2);
  trust_accounts.push_back(thptr3);
  trust_accounts.push_back(thptr4);


  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 3000);
    
  // Withdraw 5 times from each trust account
  // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
  for (int i=1; i<=5; i++)
  {
    withdraw(trust_accounts, 1000);
  }

  delete p1;
  delete p2;
  delete p3;

  delete svptr1;  
  delete svptr2;  
  delete svptr3;  
  delete svptr4;

  delete thptr1;
  delete thptr2;
  delete thptr3;
  delete thptr4;

  return 0;
}

