#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
  char *str;      // pointer to a char[] that holds a C-style string
public:
  // No-args constructor
  Mystring(); // No-args constructor
  
  // Overloaded constructor
  Mystring(const char *s);

  // Deep copy constructor
  Mystring(const Mystring &source);

  // Destructor
  ~Mystring();                                                      
  
  // Copy assignment overload operator =
  Mystring &operator=(const Mystring &rhs);

   // Getters
  int get_length() const;                                      
  const char *get_str() const;

  // Accessory functions
  void display() const;
};

#endif // _MYSTRING_H_
