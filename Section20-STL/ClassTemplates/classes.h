// Section 20
// Class  templates
// Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file
// would be used

template <typename T>
class Item 
{
private:
  std::string name;
  T   value;
public:
  Item(std::string name, T value) : name{name}, value{value} {}
  std::string get_name() const {return name; }
  T get_value() const {return value; }
};

template <typename T1, typename T2>
struct My_Pair 
{
  T1 first;
  T2 second;
};