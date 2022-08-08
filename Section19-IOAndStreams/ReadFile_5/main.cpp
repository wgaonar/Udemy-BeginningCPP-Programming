// Section 19
// Read File 5
// Read and display Shakespeare Sonnet 18 poem using UNFORMATTED get()
#include <iostream>
#include <fstream>

int main() 
{
  std::ifstream in_file;  // Declare the ifstream object

  // Initialize the ifstream object and open it with the file to read
  in_file.open("./poem.txt");

  // Check if the file was open correctly
  if (!in_file) 
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  char c {};  // The variable to store the characters in the file

  // Read continuously the file in a refactor way
  while (in_file.get(c)) 
  {
    std::cout << c;
  }
  std::cout << std::endl;

  // Close the file, don't forget to do it!!!
  in_file.close();
  
  return 0;
}