// Simple Account 
#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>
#include <string>

class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
  virtual void print(std::ostream &os) const = 0;
  
  virtual ~I_Printable() = default; // same as: virtual ~I_Printable() {}
};
#endif