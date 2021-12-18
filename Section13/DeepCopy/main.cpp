// Section 13
// Copy Constructor - Deep Copy
// This corrects the shallow copy
#include <iostream>

using namespace std;

class Deep {
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }
  // Constructor
  Deep(int d);
  // Copy Constructor
  Deep(const Deep &source);
  // Destructor
  ~Deep();
};

// Constructor
Deep::Deep(int d) 
{
  data = new int;
  *data = d;
}

// Copy constructor
Deep::Deep(const Deep &source) : 
  // Using a delegate constructor to create a new pointer
  Deep {*source.data} 
{ cout << "Copy constructor  - deep copy" << endl; }

// Destructor
Deep::~Deep() 
{
  delete data;
  cout << "Destructor freeing data" << endl;
}

// Outside class function
void display_deep(Deep s) 
{ cout << s.get_data_value() << endl; }

int main() 
{    
  Deep obj1 {100};
  display_deep(obj1);
  
  Deep obj2 {obj1};
  obj2.set_data_value(1000);

  return 0;
}