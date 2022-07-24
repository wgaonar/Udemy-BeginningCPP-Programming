#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
  IllegalBalanceException() noexcept {}
  ~IllegalBalanceException() {} // The destructor does not throw and exception by default
  
  virtual const char* what() const noexcept
  {
    return "Illegal balance exception";
  }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
