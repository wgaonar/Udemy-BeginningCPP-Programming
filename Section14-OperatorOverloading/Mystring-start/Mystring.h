#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
  char *str;      // pointer to a char[] that holds a C-style string
public:
  // No-args constructor
  Mystring();

  // Overloaded constructor
  Mystring(const char *s); 

  // Deep copy constructor                                   
  Mystring(const Mystring &source);

  // Destructor        
  ~Mystring(); 

  // Getters                                         
  void display() const;
  int get_length() const;

  // Accessory functions
  const char *get_str() const;
  
};

#endif // _MYSTRING_H_
