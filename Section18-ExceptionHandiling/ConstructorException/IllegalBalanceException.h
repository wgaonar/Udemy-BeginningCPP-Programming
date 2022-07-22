#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException
{
public:
  std::string message;
  IllegalBalanceException(): 
    message{"Couldn't create account - negative balance"} 
  {}
  
  ~IllegalBalanceException() = default;
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
