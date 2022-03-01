#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
  char *str;      // pointer to a char[] that holds a C-style string
public:
  // No-args constructor
  Mystring();

  // Overload constructor                                                         
  Mystring (const char *s);

  // Copy constructor
  Mystring (const Mystring &source);

  // Move constructor
  Mystring (Mystring &&source);

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
