// Section 10
// Assignment - Letter Pyramid
// Substitution Cipher

/*
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:
      A                          
     ABA                                                     
    ABCBA 
If the user enters the string, "12345", then your program should display:
        1   
       121                        
      12321                       
     1234321                    
    123454321

If the user enters 'ABCDEFG', then your program should display:

          A                           
         ABA                          
        ABCBA                        
       ABCDCBA                     
      ABCDEDCBA                    
     ABCDEFEDCBA                 
    ABCDEFGFEDCBA

If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:
                             A
                            ABA
                           ABCBA
                          ABCDCBA
                         ABCDEDCBA
                        ABCDEFEDCBA
                       ABCDEFGFEDCBA
                      ABCDEFGHGFEDCBA
                     ABCDEFGHIHGFEDCBA
                    ABCDEFGHIJIHGFEDCBA
                   ABCDEFGHIJKJIHGFEDCBA
                  ABCDEFGHIJKLKJIHGFEDCBA
                 ABCDEFGHIJKLMLKJIHGFEDCBA
                ABCDEFGHIJKLMNMLKJIHGFEDCBA
               ABCDEFGHIJKLMNONMLKJIHGFEDCBA
              ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
             ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
            ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
           ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA

If the user enters "C++isFun!", then your program should display:

            C                        
           C+C                   
          C+++C                     
         C++i++C                   
        C++isi++C                  
       C++isFsi++C                 
      C++isFuFsi++C               
     C++isFunuFsi++C          
    C++isFun!nuFsi++C
*/

#include <iostream>

using namespace std;
int main() 
{
  string letters {};
  cout << "Enter the letters of the pyramid: ";
  cin >> letters;

  int levels = letters.size();
  int columns = levels * 2 - 1;
  int index {0};

  for (size_t i = 0; i < levels; i++)
  {
    index = 0;
    for (size_t j = 0; j < columns; j++)
    {
      if(j < levels - 1 - i or j > levels - 1 + i)
        cout << " ";
      else if ( j < levels)
      {
        cout << letters.at(index);
        index++;
      }
      else if (j == levels)
      {
        index-=2;
        cout << letters.at(index);
      }
      else
      {
        index--;
        cout << letters.at(index);
      }
    }
    cout << endl;
  }

  return 0;
}

