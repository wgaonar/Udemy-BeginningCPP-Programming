// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Student
{
  std::string name;
  int grade;
};

void line() 
{
  std::cout << std::setw(20) << std::setfill('-') << std::right << "" << std::endl;
  std::cout << std::setfill(' '); // Reset setfill to blank spaces
}

int main() 
{
  std::ifstream in_file; //Declare the ifstream object

  // Initialize the ifstream object and open it with the file to read
  in_file.open("./responses.txt");

  // Check if the file was open correctly
  if (!in_file)
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  // Read the answer key and store it
  std::string answer_key{};
  in_file >> answer_key;

  std::vector<Student> grades;  // Vector to store student's names and grades

  std::string name{};   // The variable to store the student's name
  std::string answer{};  // The variable to store the student's grade
  double average_grade {0};

  // Read continuously the file ina refactor way
  while (in_file >> name >> answer)
  {
    // Determine the numeric grade
    int grade {0};
    for (size_t i = 0; i < answer_key.size(); i++)
    {
      if (answer.at(i) == answer_key.at(i))
      {
        grade++;
      }
    }
    average_grade += grade;
    
    // Store the grades pair
    Student person{name, grade};
    grades.push_back(person);    
  }

  // Calculate the average grade
  average_grade /= grades.size();

  // Print the table's header
  std::cout << std::endl;
  line();
  std::cout << std::setw(15) << std::left << "Student";
  std::cout << std::setw(5) << std::right << "Score" << std::endl;
  line();

  // Print the grades
  for(auto &student : grades)
  {
    std::cout << std::setw(15) << std::left << student.name; 
    std::cout << std::setw(5) << std::right << student.grade << std::endl;
  }
  line();

  // Print the average grade
  std::cout << std::setw(15) << std::left << "Average Score";
  std::cout << std::setw(5) << std::right << average_grade << std::endl;

  // Close the file, don't forget to do it!!!
  in_file.close();

  return 0;
}

