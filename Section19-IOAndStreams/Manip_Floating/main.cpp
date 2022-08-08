// Section 19
// Stream manipulators - Floating point manipulators
// scientific, setprecision, fixed, showpoint, showpos, uppercase
#include <iostream>
#include <iomanip>

int main() 
{
  double num1 {123456789.987654321};
  double num2 {1234.5678};                     
  double num3 {1234.0};                          
 
  //using default settings
  std::cout << "\n--Defaults ----------------------------" << std::endl;
  std::cout << num1 << std::endl;	// 1.23457e+08, 7 instead 6 as the last significant digit by rounding
  std::cout << num2 << std::endl;	// 1234.57
  std::cout << num3 << std::endl;	// 1234, not trailing 0s
    
  //Note how since we can't display in precision 2, scientific notation is used
  std::cout << "\n--Precision 2----------------------------" << std::endl;
  std::cout << std::setprecision(2); // precision counts all digits in the number!!!
  std::cout << num1 << std::endl;	// 1.2e+08
  std::cout << num2<< std::endl;	// 1.2e+03
  std::cout << num3<< std::endl;	// 1.2e+03
    
  // Using precision 5
  std::cout << "\n--Precision 5----------------------------" << std::endl;
  std::cout << std::setprecision(5);
  std::cout << num1 << std::endl;	// 1.2346e+08
  std::cout << num2<< std::endl;	// 1234.6
  std::cout << num3<< std::endl;	// 1234

  // Using precision 9
  std::cout << "\n--Precision 9----------------------------" << std::endl;
  std::cout << std::setprecision(9);
  std::cout << num1 << std::endl;	// 123456790, Not decimal point and rounding 8 -> 9
  std::cout << num2<< std::endl;	// 1234.5678
  std::cout << num3<< std::endl;	// 1234

  // Using precision 3 and fixed
  // Note precision is after the decimal
  std::cout << "\n--Precision 3 - fixed ----------------------------" << std::endl;
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << num1 << std::endl;	// 123456789.988, Rounding the 3rd digit after the decimal point
  std::cout << num2<< std::endl;	// 1234.568
  std::cout << num3<< std::endl;	// 1234.000 showing trailing 0s
    
  // Using precision 3 with scientific notation
  // Note precision is after the decimal
  std::cout << "\n--Precision 3 - scientific  ---------------------" << std::endl;
  std::cout << std::scientific;
  std::cout << num1 << std::endl;	// 1.235e+08
  std::cout << num2<< std::endl;	// 1.235e+03
  std::cout << num3<< std::endl;	// 1.234e+03
    
  // Using precision 5 with scientific notation and capital 'E' in scientific 
  std::cout << "\n--Precision 5 - scientific - uppercase  ---------------" << std::endl;
  std::cout << std::setprecision(5) << std::uppercase;
  std::cout << num1 << std::endl;	// 1.23457E+08
  std::cout << num2<< std::endl;	// 1.23457E+03
  std::cout << num3<< std::endl;	// 1.23400E+03
    
  // Show '+' symbol for positive numbers
  std::cout << "\n--Precision 3 - fixed - showpos ----------------------" << std::endl;
  std::cout << std::setprecision(3) << std::fixed << std::showpos;
  std::cout << num1 << std::endl;	// +123456789.988
  std::cout << num2<< std::endl;	// +1234.568
  std::cout << num3<< std::endl;	// +1234.000
    
  // Back to defaults
  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::resetiosflags(std::ios::showpos);
    
  // Show trailing zeroes up to precision 10
  std::cout << "\n-- Back to defaults -> Precision 10 - showpoint -----------" << std::endl;
  std::cout << std::setprecision(10) << std::showpoint;
  std::cout << num1 << std::endl;	// 123456790.0
  std::cout << num2<< std::endl;	// 1234.567800
  std::cout << num3<< std::endl;	// 1234.000000

// Back to defaults
  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::setprecision(6);
  std::cout << std::resetiosflags(std::ios::showpos);
  std::cout << std::resetiosflags(std::ios::showpoint);

  std::cout << "\n--Back to defaults----------------------------" << std::endl;
  std::cout << num1 << std::endl;	
  std::cout << num2<< std::endl;	
  std::cout << num3<< std::endl;	
    
  return 0;
}

