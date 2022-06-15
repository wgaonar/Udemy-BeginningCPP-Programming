#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
  : str{nullptr} 
{
  str = new char[1];
  *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
  : str {nullptr} 
{
  if (s==nullptr) 
  {
    str = new char[1];
    *str = '\0';
  } 
  else 
  {
    str = new char[std::strlen(s)+1];
    std::strcpy(str, s);
  }
}

// Deep copy constructor
Mystring::Mystring(const Mystring &source) 
  : str{nullptr} 
{
  std::cout << "Deep copy constructor used" << std::endl;
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() 
{
  delete [] str;
}

// Copy assignment overload operator =
Mystring &Mystring::operator= (const Mystring &rhs) 
{
  std::cout << "Copy assignment" << std::endl;

  // Check if the rhs object is the same than this object
  if (this == &rhs)
    return *this;
  
  delete [] str;
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  return *this;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }
 
// string getter
const char *Mystring::get_str() const { return str; }

// Display method
void Mystring::display() const 
{
  std::cout << str << " : " << get_length() << std::endl;
}