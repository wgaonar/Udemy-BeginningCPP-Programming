// Section 18
// Miles per Gallon - Function - Exception Classes
#include <iostream>

class DivideByZeroException 
{
  public:
  std::string message {"Sorry, you can't divide by zero"};
};

class NegativeValueException 
{
  public:
  std::string message {"Sorry, one of your parameters is negative"};
};

double calculate_mpg(int miles, int gallons) 
{
  // The first class of exception
  if (gallons == 0)
  {
    throw DivideByZeroException();
  }

  // The second class of exception
  else if (miles < 0 || gallons < 0)
  {
    throw NegativeValueException();
  }

  return static_cast<double>(miles) / gallons;
}

int main() 
{    
  int miles {};
  int gallons {};
  double miles_per_gallon {};   
  
  std::cout << "Enter the miles: ";
  std::cin >> miles;
  std::cout << "Enter the gallons: ";
  std::cin >> gallons;
  
  try 
  {
    miles_per_gallon = calculate_mpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallon << std::endl;
  } 
  catch (const DivideByZeroException &ex) 
  {
    std::cerr << ex.message << std::endl;
  } 
  catch (const NegativeValueException &ex) 
  {
    std::cerr << ex.message << std::endl;
  }
  std::cout << "Bye" << std::endl;

  return 0;
}

