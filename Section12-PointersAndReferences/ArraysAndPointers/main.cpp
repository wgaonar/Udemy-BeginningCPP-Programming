#include <iostream>

using namespace std;

int main() 
{
  int scores[] {100, 95, 89};
  
  cout << "Value of scores: " << scores << endl;        // 0x7ff7b9a2c56c  
  
  cout << "\nA pointer to the array --------------------" << endl;
  int *score_ptr {scores};
  cout << "Value of score_ptr: " << score_ptr << endl;  // 0x7ff7b9a2c56c

  cout << "\nA pointer to the third array element -----------------" << endl;
  int *score_ptr2 = &scores[2];
  cout << "Value of score_ptr2: " << score_ptr2 << endl;    // 0x7ff7b9a2c574
  cout << "Value of *score_ptr2: " << *score_ptr2 << endl;  // 89
  
  cout << "\nArray subscript notation -------------------------" << endl;
  cout << scores[0] << endl;  // 100
  cout << scores[1] << endl;  // 95
  cout << scores[2] << endl;  // 89
  
  cout << "\nPointer subscript notation -------------------------" << endl;
  cout << score_ptr[0] << endl;   // 100
  cout << score_ptr[1] << endl;   // 95
  cout << score_ptr[2] << endl;   // 89
  
  cout << "\nArray offset notation-------------------------" << endl;
  cout << *scores << endl;        // 100
  cout << *(scores + 1) << endl;  // 95
  cout << *(scores + 2) << endl;  // 89

  cout << "\nPointer offset notation-------------------------" << endl;
  cout << *score_ptr << endl;         // 100
  cout << *(score_ptr + 1) << endl;   // 95
  cout << *(score_ptr + 2) << endl;   // 89
  
  cout << endl;

  return 0;
}

