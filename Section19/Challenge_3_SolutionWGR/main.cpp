// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
  ifstream in_file; //Declare the ifstream object

  // Initialize the ifstream object and open it with the file to read
  in_file.open("./romeoandjuliet.txt");

  // Check if the file was open correctly
  if (!in_file)
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  string word {};
  string word_to_search {};
  int word_count {0};
  int total_words {0};

  cout << "Enter the substring to search for: ";
  cin >> word_to_search;

  while (in_file >> word)
  {
    total_words++;  
    if (word.find(word_to_search) != string::npos)
    {
      word_count++;
    }
  }
    
  cout << total_words << " words were searched...\n";
  cout  << "The substring " << word_to_search 
        << " was found " << word_count << " times\n";
  return 0;
}

