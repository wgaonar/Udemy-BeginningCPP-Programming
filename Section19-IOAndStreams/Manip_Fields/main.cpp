// Section 19
// Stream manipulators - Field width, justification and setfill
// setw, left, right, setfill
#include <iostream>
#include <iomanip>

void ruler() 
{
  std::cout << "12345678901234567890123456789012345678901234567890" << std::endl;
}

int main() 
{
  int num1 {1234};
  double num2 {1234.5678};
  std::string hello  {"Hello"};
  
  // Defaults
  std::cout << "\n--Defaults --------------------------------------------" << std::endl;
  ruler();
  std::cout << num1 << num2 << hello << std::endl; // 12341234.5678Hello
    
  // Defaults - one per line
  std::cout << "\n--Defaults - one per line------------------------------" << std::endl;
  ruler();
  std::cout << num1 <<std::endl;    // 1234
  std::cout << num2 << std::endl;   // 1234.57
  std::cout << hello << std::endl;  // Hello
    
  // Set field width to 10 
  // Note the default justification (right) is for num1 only!
  std::cout << "\n--width 10 for num1------------------------------------" << std::endl;
  ruler(); 
  std::cout << std::setw(10) << num1 
            << num2 
            << hello 
            << std::endl;   //      12341234.57Hello
    
  // Set field width to 10 for the first 2 outputs
  // Note the default justification (right) is for num1 and num2
  std::cout << "\n--width 10 for num1 and num2-------------------------" << std::endl;
  ruler(); 
  std::cout << std::setw(10) << num1 
            << std::setw(10) << num2  
            << hello 
            << std::endl;   //      1234   1234.57Hello
                  
  // Set field width to 10 for all 3 outputs
  // Note the default justification is right for all
  std::cout << "\n--width 10 for num1 and num2 and hello right for all--" << std::endl;
  ruler(); 
  std::cout << std::setw(10) << num1 
            << std::setw(10) << num2  
            << std::setw(10) << hello 
            << std::endl;   //      1234   1234.57     Hello
                  
  // Set field width to 10 for all 3 outputs and justify all left
  // Note the left justification persistent for all
  std::cout << "\n--width 10 for num1 and num2 and hello left for all--" << std::endl;
  ruler(); 
  std::cout << std::setw(10) << std::left << num1 
            << std::setw(10) << num2  
            << std::setw(10) << hello 
            << std::endl;   // 1234      1234.57   Hello
                  
  // setfill to a dash
  // This left justification is persistent from the previous display
  std::cout << "\n--width 10 for num1, num2 and hello left for all and setfill to dash------------" << std::endl;
  ruler(); 
  std::cout << std::setfill('-');
  std::cout << std::setw(10) << num1 
            << std::setw(10) << num2  
            << std::setw(10) <<  hello 
            << std::endl;   // 1234------1234.57---Hello-----
  
  // setfill to a dash and right justification
  std::cout << "\n--width 10 for num1 and num2 and hello right for all setfill to dash------------" << std::endl;
  ruler(); 
  std::cout << std::right << std::setfill('-');
  std::cout << std::setw(10) << num1 
            << std::setw(10) << num2  
            << std::setw(10) <<  hello 
            << std::endl;   // ------1234---1234.57-----Hello

  // Set width to 10 for all, left justify all and carry the setfill character
  std::cout << "\n--width 10 for num1 and num2 and hello left - setfill varies------------------------" << std::endl;
  ruler();
  std::cout << std::left; 
  std::cout << std::setw(10) << std::setfill('*') << num1 
            << std::setw(10) << std::setfill('#' )<< num2  
            << std::setw(10) <<  std::setfill('-') << hello 
            << std::endl;   // 1234******1234.57###Hello-----
  
  // Set width to 10 for all, different justifications all and carry the setfill character
  std::cout << "\n--width 10 for num1 and num2 and hello different justifications - setfill varies--" << std::endl;
  ruler(); 
  std::cout << std::setw(10) << std::right << std::setfill('*') << num1 
            << std::setw(10) << std::left << std::setfill('#' )<< num2  
            << std::setw(10) << std::right <<  std::setfill('-') << hello 
            << std::endl;   // ******12341234.57###-----Hello

  // Defaults
  std::cout << "\n--Defaults----------------------------" << std::endl;
  ruler();
  std::cout << num1 << num2 << hello << std::endl; // 12341234.5678Hello

  std::cout << std::endl << std::endl;
  return 0;
}

