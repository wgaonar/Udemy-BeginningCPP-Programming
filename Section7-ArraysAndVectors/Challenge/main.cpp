/*  Section 7
  Challenge
  
  Write a C++ program as follows:
  
  Declare 2 empty vectors of integers named
  vector1 and vector 2, respectively.
  
  Add 10 and 20 to vector1 dynamically using push_back
  Display the elements in vector1 using the at() method as well as its size using the size() method
  
  Add 100 and 200 to vector2 dynamically using push_back
  Display the elements in vector2 using the at() method as well as its size using the size() method

  Declare an empty 2D vector called vector_2d
  Remember, that a 2D vector is a vector of vector<int>
  
  Add vector1 to vector_2d dynamically using push_back
  Add vector2 to vector_2d dynamically using push_back
  
  Display the elements in vector_2d using the at() method
  
  Change vector1.at(0) to 1000
  
  Display the elements in vector_2d again using the at() method
  
  Display the elements in vector1 
  
  What did you expect? Did you get what you expected? What do you think happended?
*/
    
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Instantiate a couple of vectors
  vector <int> vector1;
  vector <int> vector2;

  // Inserting and accessing the vector 1 elements
  vector1.push_back(10);
  vector1.push_back(20);
  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  cout << vector1.size() << endl;

  // Inserting and accessing the vector 2 elements
  vector2.push_back(100);
  vector2.push_back(200);
  cout << vector2.at(0) << endl;
  cout << vector2.at(1) << endl;
  cout << vector2.size() << endl;

  // Instantiate a twodimensional vector
  vector <vector <int>> vector_2d;

  // Inserting a vector into another twodimensional vector
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  // Accessing two dimensional vector elements
  cout << vector_2d.at(0).at(0) << " "  << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

  vector1.at(0) = 1000;

  cout << vector_2d.at(0).at(0) << " "  << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  cout << vector1.size() << endl;


  // Instantiate and initialize another twodimensional vector 
  vector < vector <int>> movieRatings
  {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };

  // Accessing a twodimensional vector elements through iterating over it
  for (size_t i = 0; i < movieRatings.size(); i++)
  {
    for (size_t j = 0; j < movieRatings.at(0).size(); j++)
    {
      cout << movieRatings.at(i).at(j) << " ";
    }
    cout << endl;
  }
  

  cout << endl;
  return 0;
}

