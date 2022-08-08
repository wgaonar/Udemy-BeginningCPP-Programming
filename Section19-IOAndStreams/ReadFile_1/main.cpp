// Section 19
// Read File 1
// Test for file open and simple read of 3 data items
#include <iostream>
#include <fstream>

int main() 
{
  std::ifstream in_file;  // Declare the ifstream object
  std::string word;
  int num;
  double total;
  
  // Initialize the ifstream object and open it with the file to read
  in_file.open("./test.txt");

  // Check if the file was open correctly
  if (!in_file) // Equivalent to !in_file.is_open()
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  // Read the file word or number at a time
  in_file >> word >> num >> total;
  std::cout << word << std::endl;
  std::cout << num << std::endl;
  std::cout << total << std::endl;

  // Close the file, don't forget to do it!!!
  in_file.close();
  return 0;
}

