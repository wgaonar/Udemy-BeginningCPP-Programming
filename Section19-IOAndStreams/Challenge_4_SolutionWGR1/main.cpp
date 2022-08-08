// Section 19
// Copy the contest of a file into another with line number
// in ALL lines including the blank lines.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
  std::ifstream in_file {"./romeoandjuliet.txt"};
  std::ofstream out_file{"./romeoandjuliet.txt"};

  // Check if the file was open correctly
  if (!in_file)
  {
    cerr << "Error opening input file\n";
    return 1;
  }

  // Check if the file was created correctly
  if (!out_file)
  {
    cerr << "Error opening output file\n";
    return 1;
  }

  string line{};
  int line_counter{0};
  while (getline(in_file, line))
  {
    out_file << setw(5) << line_counter << line << endl;
  }
  
  cout << "File copied" << std::endl;

  in_file.close();
  out_file.close();
  
  return 0;
}

