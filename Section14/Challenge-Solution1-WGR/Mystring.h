#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
  friend std::ostream &operator<<(std::ostream &out, const Mystring &rhs);
  friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
  char *str;      // pointer to a char[] that holds a C-style string
public:
 // No-args constructor
  Mystring();
  
  // Overloaded constructor
  Mystring(const char *s);

  // Deep copy constructor                                     
  Mystring(const Mystring &source);

  // Move constructor
  Mystring( Mystring &&source);

  // Destructor                         
  ~Mystring();
  
  // Copy assignment overload operator =
  Mystring &operator=(const Mystring &rhs);

  // Move assignment overload operator = 
  Mystring &operator=(Mystring &&rhs);

  // Make lowercase - overload unary operator -
  Mystring operator-() const;

  // Compare equality - overload binary operator ==
  bool operator==(const Mystring &rhs) const;

  // Compare inequality - overload binary operator !=
  bool operator!=(const Mystring &rhs) const;

  // Compare lexically less than - overload binary operator <
  bool operator<(const Mystring &rhs) const;
  
  // Compare lexically grater than - overload binary operator >
  bool operator>(const Mystring &rhs) const;

  // Concatenate - overload binary operator +
  Mystring operator+(const Mystring &rhs) const;

  // Addition assignment - overload binary operator +=
  Mystring &operator+=(const Mystring &rhs);

  // Repeat - overload binary operator *
  Mystring operator*(const int n) const;

  // Repeat assignment - overload binary operator *=
  Mystring &operator*=(const int n);
  
  // Getters
  int get_length() const;                                       
  const char *get_str() const;
  
  // Accessory functions
  void display() const;
};

#endif // _MYSTRING_H_