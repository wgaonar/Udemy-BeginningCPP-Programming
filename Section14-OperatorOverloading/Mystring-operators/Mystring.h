#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
  char *str;      // pointer to a char[] that hold a C-style string
public:
  // No-args constructor
  Mystring();

  // Overloaded constructor
  Mystring(const char *s);
  
  // Copy constructor
  Mystring(const Mystring &source);

  // Move constructor
  Mystring(Mystring &&source);

  // Destructor
  ~Mystring();                                            
  
  // Copy assignment overload operator =
  Mystring &operator=(const Mystring &rhs);

  // Move assignment overload operator =
  Mystring &operator=(Mystring &&rhs);

  // Make lowercase - overload unary operator -
  Mystring operator-() const;

  // Concatenate - overload binary operator +
  Mystring operator+(const Mystring &rhs) const;

  // Compare - overload binary operator ==
  bool operator==(const Mystring &rhs) const;
  
  // Getters
  int get_length() const;                                      
  const char *get_str() const;

  // Accessory functions
  void display() const;
};

#endif // _MYSTRING_H_
