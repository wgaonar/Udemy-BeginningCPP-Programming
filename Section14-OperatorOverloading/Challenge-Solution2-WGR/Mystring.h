#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
  friend std::ostream &operator<<(std::ostream &out, const Mystring &rhs);
  friend std::istream &operator>>(std::istream &in, Mystring &rhs);
  
  // Compare equality - overload binary operator ==
  friend bool operator==(const Mystring &lhs, const Mystring &rhs);

  // Make lowercase - overload unary operator -
  friend Mystring operator-(const Mystring &obj);

  // Compare inequality - overload binary operator !=
  friend bool operator!=(const Mystring &lhs, const Mystring &rhs);

  // Compare lexically less than - overload binary operator <
  friend bool operator<(const Mystring &lhs, const Mystring &rhs);
  
  // Compare lexically grater than - overload binary operator >
  friend bool operator>(const Mystring &lhs, const Mystring &rhs);

  // Concatenate - overload binary operator +
  friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

  // Addition assignment - overload binary operator +=
  friend Mystring &operator+=(Mystring &obj, const Mystring &rhs);

  // Repeat - overload binary operator *
  friend Mystring operator*(const Mystring &obj, const int n);

  // Repeat assignment - overload binary operator *=
  friend Mystring &operator*=(Mystring &obj, const int n);

  // Pre-increment overload unary operator++ make the string upper-case
  friend Mystring &operator++(Mystring &obj);

  // Post-increment overload unary operator++ make the string upper-case
  friend Mystring operator++(Mystring &obj,int);

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
  
  // Getters
  int get_length() const;                                       
  const char *get_str() const;
  
  // Accessory functions
  void display() const;
};

#endif // _MYSTRING_H_