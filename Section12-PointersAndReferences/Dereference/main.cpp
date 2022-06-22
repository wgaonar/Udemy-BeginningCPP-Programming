// Section 12
// Dereferencing

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
  int score {100};
  int *score_ptr {&score};

  cout << "Value of *score_ptr: " << *score_ptr << endl;		// 100

  *score_ptr = 200;
  
  cout << "New value of *score_ptr: " << *score_ptr << endl;		// 200
  cout << "Value of score: " << score << endl; 			// 200

  cout << "\n------------------------------" << endl;
  double high_temp {100.7};
  double low_temp {37.4};			       
  double *temp_ptr {&high_temp};    

  cout  << "Value of *temp_ptr -> high_temp: " 
        << *temp_ptr << endl;   	// 100.7 

  temp_ptr = &low_temp;	
  cout  << "Value of *temp_ptr -> low_temp: " 
        << *temp_ptr << endl;   	// 37.4   	    

  cout << "\n------------------------------" << endl;
  string name {"Frank"};
  string *string_ptr {&name};

  cout << "Value of *string_ptr: " << *string_ptr << endl;   	// Frank   
  name = "James"; 	    
  cout << "New value of *string_ptr: " << *string_ptr << endl;   	// James  

  cout << "\n------------------------------" << endl;
  vector<string> stooges {"Larry", "Moe", "Curly"};
  vector<string> *vector_ptr { &stooges};
  
  cout  << "First stooge (*vector_ptr).at(0): " 
        << (*vector_ptr).at(0) << endl;    // Larry
 
  cout  << "Second stooge vector_ptr->at(1): " 
        << vector_ptr->at(1) << endl;    // Moe
  
  cout << "All the Stooges: ";
  for (auto stooge: *vector_ptr)  
      cout << stooge << " ";
  cout << endl;
  
  cout << endl;
  return 0;
}

