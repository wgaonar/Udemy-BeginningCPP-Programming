// Section 9
// Challenge
/*    
This challenge is about using a collection (list) of integers and allowing the user
to select options from a menu to perform operations on the list.

Your program should display a menu options to the user as follows:

P - Print numbers
A - Add a number
M - Display mean of the numbers
S - Display the smallest number
L - Display the largest number
Q - Quit

Enter your choice:
  
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a multiset!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the multiset class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <set>

using namespace std;

template <typename T>
void DisplayContainer (const T &container)
{
  for (auto element : container)
  {
    cout << element << ' ';
  }
}

void Display_Menu(char &selection);

template <typename T>
void Print_Numbers(const T &container);

template <typename T>
void Add_Numbers(T &container);

template <typename T>
double Calculate_Mean(const T &container);

template <typename T>
int Find_Smallest(const T &container);

template <typename T>
int Find_Largest(const T &container);

template <typename T>
void Count_Number(const T &container);

template <typename T>
double Find_number(const T &container);

// Display menu
void Display_Menu(char &selection)
{
  cout << "\nP - Print numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "S - Display the smallest number" << endl;
  cout << "L - Display the largest number"<< endl;
  cout << "Q - Quit" << endl;
  cout << "\nEnter your choice: ";
  cin >> selection;
}
// Print Numbers
template <typename T>
void Print_Numbers(const T &container)
{
  if (container.size() != 0)
  {
    cout << "[ ";
    DisplayContainer(container);
    cout << "]" << endl;
  }
  else
    cout << "[] - the list is empty" << endl;
}

// Add numbers
template <typename T>
void Add_Numbers(T &container)
{
  int number{0};
  cout << "Enter the int to add: ";
  cin >> number;
  container.insert(number);
  cout << number << " added" << endl;
}

// Calculate Mean
template <typename T>
double Calculate_Mean(const T &container)
{
  if (container.size() != 0)
  {
    int sum {0};
    for (auto cont : container)
    {
      sum += cont;
    }
    double mean = static_cast<double>(sum) / container.size();
    cout << "The mean is: " << mean << endl;
    return mean;
  }
  else 
  {
    cout << "Unable to calculate the mean - no data" << endl;
    return 0;
  }
}

// Find the smallest number in a container
template <typename T>
int Find_Smallest(const T &container)
{
  if (container.size() != 0)
  {
    auto element = container.cbegin();
    int smallest {*element};
    for (auto cont : container)
    {
      if (smallest > cont)
        smallest = cont;
    }
    cout << "The smallest is: " << smallest << endl;
    return smallest;
  }
  else
  {
    cout << "Unable to determine the smallest number - list is empty" << endl;
    return 0;
  } 
}

// Find the largest number in a container
template <typename T>
int Find_Largest(const T &container)
{
  if (container.size() != 0)
  {
    auto element = container.cbegin();
    int largest {*element};
    for (auto cont : container)
    {
      if (largest < cont)
        largest = cont;
    }
    cout << "The largest is: " << largest << endl;
    return largest;
  }
  else
  {
    cout << "Unable to determine the largest number - list is empty" << endl;
    return 0;
  } 
}

// Count the frequency of the numbers in a sorted container
template <typename T>
void Count_Number(const T &container)
{
  if (container.size() != 0)
  {
    for (auto it = container.begin(); it != container.end();) 
    {
      auto cnt = container.count(*it);
      cout << *it << ":\t" << cnt << endl;
      advance(it, cnt); // move to the next different element
    }
  }
  else
    cout << "Unable to count - list is empty" << endl;
}

// Find a number in a container
template <typename T>
double Find_Number(const T &container)
{
  if (container.size() != 0)
  {
    int number{0};
    cout << "Enter the int to find: ";
    cin >> number;
    auto search = container.find(number);
    if (search != container.end()) 
    {
      cout << number << " found" << endl;
      return number;
    } 
    else 
    {
      cout << number << " Not found" << endl;
    }
  }
  else
  {
    cout << "Unable to find - list is empty" << endl;
  }
  return 0;
}

int main() 
{
  multiset<int> container;
  char selection {};
  do 
  {
    Display_Menu(selection);
    if (selection == 'P' or selection == 'p')
    {
      Print_Numbers(container);
    }
    else if (selection == 'A' or selection == 'a')
    {
      Add_Numbers(container);
    } 
    else if (selection == 'M' or selection == 'm')
    {
      Calculate_Mean(container);
    } 
    else if (selection == 'S' or selection == 's')
    {
      Find_Smallest(container);
    }
    else if (selection == 'L' or selection == 'l')
    {
      Find_Largest(container);
    }
      
    else if (selection == 'C' or selection == 'c')
    {
      Count_Number(container);
    }
    else if (selection == 'F' or selection == 'f')
    {
      Find_Number(container);
    }      
    else if (selection == 'Q' or selection == 'q')
    {
      cout << "Goodbye..." << endl;
    }
    else
    { 
      cout << "Unknown option -- try again..." << endl;
    }
  
  } 
  while ( selection != 'q' && selection != 'Q');

  cout << endl;
  return 0;
}

