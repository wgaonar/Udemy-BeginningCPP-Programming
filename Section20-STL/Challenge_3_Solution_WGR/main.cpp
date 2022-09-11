// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) 
{
  std::cout << std::setw(12) << std::left << "\nWord"
            << std::setw(7) << std::right << "Count"<< std::endl;
  std::cout << "===================" << std::endl;
  for (auto pair: words)
  {
    std::cout << std::setw(12) << std::left << pair.first 
              << std::setw(7) << std::right << pair.second << std::endl;
  } 
}

// Used for Part2
// Display the word and occurrences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
  std::cout << std::setw(12) << std::left << "\nWord"
            << "Occurrences"<< std::endl;
  std::cout << "=====================================================================" << std::endl;
  for (auto pair: words) 
  {
    std::cout << std::setw(12) << std::left << pair.first 
              << std::left << "[ ";
    for (auto i: pair.second)
    { 
      std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
  }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) 
{
  std::string result;
  for (char c: s) 
  {
    if (c == '.' || c == ',' || c == ';' || c == ':')
    {
      continue;
    }
    else
    {
      result += c;
    }
  }
  return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() 
{
  std::map<std::string, int> words;     
  std::string word;
  std::string clean_word;   
  std::ifstream in_file {"./words.txt"};

  // Check if the file was open correctly
  if (!in_file) // Equivalent to !in_file.is_open()
  {
    std::cerr << "Problem opening file" << std::endl;
  }
  else 
  {
    std::string word;
    while (!in_file.eof())
    {
      // Read each word in the file
      in_file >> word;

      clean_word = clean_string(word);

      // If the word is not in the map -> insert it
      if (words.count(clean_word) == 0)
      {
        words.insert(std::make_pair(clean_word,1));
      }
      // If the word is in the map -> increase the frequency
      else
      {
        words.at(clean_word) ++;
      }
    }
    in_file.close();
    display_words(words);
  } 
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::string clean_word;
    int line_counter{1};
    std::ifstream in_file {"./words.txt"};

  // Check if the file was open correctly
  if (!in_file) // Equivalent to !in_file.is_open()
  {
    std::cerr << "Problem opening file" << std::endl;
  }
  else 
  {
    // Read continuously the file line by line in a refactor way
    while (std::getline(in_file, line))
    {
      // Object used to split the line around spaces.
      std::istringstream ss {line};

      // Traverse through all words in the line
      while (ss >> word)
      {
        clean_word = clean_string(word);

        // If the word is not in the map -> insert it
        if (words.count(clean_word) == 0)
        {
          words.insert(std::make_pair(clean_word,std::set<int>{line_counter}));
        }
        // If the word is in the map -> insert in the set the new line number
        else
        {
          words.at(clean_word).insert(line_counter);
        }
      }
      line_counter++;
    }
    
        
    in_file.close();
    display_words(words);
  } 
}

int main() 
{
  part1();
  part2();
  return 0;
}

