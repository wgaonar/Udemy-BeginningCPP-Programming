#ifndef __INSUFFICENT_FUNDS_EXCEPTION_H__
#define __INSUFFICENT_FUNDS_EXCEPTION_H__

class InsufficentFundsException : public std::exception
{
public:
  InsufficentFundsException() noexcept {}
  ~InsufficentFundsException() {} // The destructor does not throw and exception by default
  
  virtual const char* what() const noexcept
  {
    return "Insufficent funds exception";
  }
};

#endif // __INSUFFICENT_FUNDS_EXCEPTION_H__
