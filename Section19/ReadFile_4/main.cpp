// Section 19
// Read File 4
// Read and display word by word Shakespeare Sonnet 18 poem using getline
#include <iostream>
#include <fstream>
#include <sstream> // To use istringstream objects to split into words a line

int main() 
{
  std::ifstream in_file;   // Declare the ifstream object

  // Initialize the ifstream object and open it with the file to read
  in_file.open("./poem.txt");

  // Check if the file was open correctly
  if (!in_file) 
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  std::string line; // The variable to store the lines of the file
  
  // Read continuously the file in a refactor way
  while (std::getline(in_file, line)) 
  {    
    std::cout << std::endl << line << std::endl; // Print the line

    std::istringstream ss(line); // Object used to split the line around spaces.
    std::string word;

    // Traverse through all words in the line
    while (ss >> word) 
    {
      // print the read word
      std::cout << word << std::endl;
    }
  }
  
  in_file.close();
  return 0;
}