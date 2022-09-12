// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
  // Push the string characters in a queue and into a stack
  std::queue <char> q;
  std::stack <char> stk;

  for (const char& c: s)
  {
    if (std::isalpha(c))  // Only do with alpha characters
    {
      q.push(std::toupper(c));
      stk.push(std::toupper(c));
    }
  }

  // Check if the string is a palindrome
  while(!q.empty())
  {
    if (q.front() == stk.top())
    {
      q.pop();
      stk.pop();
      continue;
    }
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{
    std::vector<std::string> test_strings
    { "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
      "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
      "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", 
      "This is a palindrome", "palindrome" 
    };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) 
    {
      std::cout 
                << is_palindrome(s)  << " " << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}