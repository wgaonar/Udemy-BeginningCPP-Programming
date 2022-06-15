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
  
  // Overload copy assignment operator
  Mystring &operator=(const Mystring &rhs);

  // Overload Move assignment 
  Mystring &operator=(Mystring &&rhs);       
  
  // Getters
  int get_length() const;                                       
  const char *get_str() const;
  
  // Accessory functions
  void display() const;
};

#endif // _MYSTRING_H_