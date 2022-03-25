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
  if (s==nullptr) {
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
Mystring::Mystring(const Mystring &source) 
: str{nullptr} 
{
  str = new char[strlen(source.str)+ 1];
  strcpy(str, source.str);
  std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
:str{source.str} 
{
  source.str = nullptr;
  std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() 
{
  delete [] str;
}

// Copy assignment overload operator =
Mystring &Mystring::operator=(const Mystring &rhs) 
{
  // std::cout << "Using copy assignment" << std::endl;
  if (this == &rhs) 
      return *this;

  delete [] str;
  str = new char[strlen(rhs.str) + 1];
  strcpy(str, rhs.str);
  return *this;
}

// Move assignment overload operator =
Mystring &Mystring::operator=( Mystring &&rhs) 
{
  // std::cout << "Using move assignment" << std::endl;
  if (this == &rhs) 
      return *this;

  delete [] str;
  str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

// Make lowercase - overload unary operator -
Mystring Mystring::operator-() const 
{
  char *buff= new char[std::strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i=0; i<std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);

  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Compare equality - overload binary operator ==
bool Mystring::operator==(const Mystring &rhs) const 
{
  if (std::strcmp(str, rhs.str) == 0)
    return true;
  else
    return false;
}

// Compare inequality - overload binary operator !=
bool Mystring::operator!=(const Mystring &rhs) const 
{
  if (std::strcmp(str, rhs.str) != 0)
    return true;
  else
    return false;
}

// Compare lexically less than - overload binary operator <
bool Mystring::operator<(const Mystring &rhs) const 
{
  if (str < rhs.str)
    return true;
  else
    return false;
}

// Compare lexically greater than - overload binary operator >
bool Mystring::operator>(const Mystring &rhs) const 
{
  if (str > rhs.str)
    return true;
  else
    return false;
}

// Concatentate - overload binary operator +
Mystring Mystring::operator+(const Mystring &rhs) const 
{
  char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);

  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Addition assignment - overload binary operator +=
Mystring &Mystring::operator+=(const Mystring &rhs)
{
  std::strcat(str, rhs.str);
  // *this = *this + rhs;

  return *this;
}

// Repeat - overload binary operator *
Mystring Mystring::operator*(const int n) const
{
  char *buff = new char[std::strlen(str) * n  + 1];
  for (size_t i = 0; i < n; i++)
    std::strcat(buff, str);

  /*
  Mystring temp;
  for (size_t i = 0; i < n; i++)
    temp = temp + *this;
  return temp;
  */

  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Repeat assignment - overload binary operator *=
Mystring &Mystring::operator*=(const int n)
{
  *this = *this * n;
  return *this;
}

// Display method
void Mystring::display() const 
{
  std::cout << str << " : " << get_length() << std::endl;
}

// Getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// Overloaded insertion operator as a global function
std::ostream &operator<<(std::ostream &out, const Mystring &rhs) 
{
  out << rhs.str;
  return out;
}

// Overloaded extraction operator as a global function
std::istream &operator>>(std::istream &in, Mystring &rhs) 
{
  char *buff = new char[1000];
  in >> buff;
  rhs = Mystring{buff};
  delete [] buff;
  return in;
}

