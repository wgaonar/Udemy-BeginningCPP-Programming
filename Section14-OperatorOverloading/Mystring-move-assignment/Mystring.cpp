#include <iostream>
#include <cstring>
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
    str = new char[strlen(s)+1];
    strcpy(str, s);
  }
}

// Deep copy constructor
Mystring::Mystring (const Mystring &source) 
  : str{nullptr} 
{
  str = new char[strlen(source.str)+ 1];
  strcpy(str, source.str);
  std::cout << "Deep copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring (Mystring &&source) 
  :str{source.str} 
{
  std::cout << "Move constructor used" << std::endl;
  source.str = nullptr;
}

 // Destructor
Mystring::~Mystring() 
{
  if (str == nullptr) 
  {
    std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
  } 
  else 
  {
    std::cout << "Calling destructor for Mystring : " << str << std::endl;
  }
  delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) 
{
  std::cout << "Using copy assignment" << std::endl;

  // Check if the rhs object is the same than this object
  if (this == &rhs) 
    return *this;
  
  delete [] str;
  str = new char[strlen(rhs.str) + 1];
  strcpy(str, rhs.str);
  return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) 
{
  std::cout << "Using move assignment" << std::endl;

  // Check if the rhs object is the same than this object
  if (this == &rhs) 
      return *this;

  delete [] str;
  str = rhs.str;
  rhs.str = nullptr;
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




