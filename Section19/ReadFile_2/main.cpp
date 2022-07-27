// Section 19
// Read File 2
// Continuous read of 3 data items in a loop
#include <iostream>
#include <iomanip>
#include <fstream>

int main() 
{
  std::ifstream in_file;  // Declare the ifstream object
  std::string word;
  int num;
  double total;
  
  std::cout << "\n----Open the file and read it with a classic way----" << std::endl;
  // Initialize the ifstream object and open it with the file to read
  in_file.open("./test.txt");

  // Check if the file was open correctly
  if (!in_file) // Equivalent to !in_file.is_open()
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  // Read continuously the file checking eof() method
  while(!in_file.eof())
  {
    in_file >> word >> num >> total;
    std::cout << std::setw(10) << std::left << word 
              << std::setw(10) << num 
              << std::setw(10) << total
              << std::endl;
  }

  // Close the file, don't forget to do it!!!
  in_file.close();

  std::cout << "\n----Open the file again and read it with a refactor way----" << std::endl;
  // Again, open the file to read
  in_file.open("./test.txt");

  // Check if the file was open correctly
  if (!in_file) // Equivalent to !in_file.is_open()
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  // Read continuously the file in a refactor way
  while (in_file >> word >> num >> total)
  {
    std::cout << std::setw(10) << std::left << word 
              << std::setw(10) << num 
              << std::setw(10) << total
              << std::endl;
  }

  // Close the file, don't forget to do it!!!
  in_file.close();
  return 0;
}

