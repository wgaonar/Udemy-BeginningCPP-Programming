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

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <set>

using namespace std;

template <typename T>
void DisplayContainer (const T & container)
{
  for (auto element : container)
  {
    cout << element << ' ';
  }
}
int main() 
{
  multiset<int> container;
  char selection {};
  do 
  {
    cout << "\n---------------------" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your selection: ";
    cin >> selection;

    if (selection == 'P' or selection == 'p')
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
    else if (selection == 'A' or selection == 'a')
    {
      int number{0};
      cout << "Enter the int to add: ";
      cin >> number;
      container.insert(number);
      cout << number << " added" << endl;
    } 
    else if (selection == 'M' or selection == 'm')
    {
      if (container.size() != 0)
      {
        int sum {0};
        for (auto it : container)
        {
          sum += it;
        }
        double average = static_cast<double>(sum) / container.size();
        cout << "The mean is: " << average << endl;
      }
      else
        cout << "Unable to calculate the mean - no data" << endl;
    } 
    else if (selection == 'S' or selection == 's')
      if (container.size() != 0)
      {
        auto element = container.cbegin();
        int smallest {*element};
        for (auto it : container)
        {
          if (smallest > it)
            smallest = it;
        }
        cout << "The smallest is: " << smallest << endl;
      }
      else
        cout << "Unable to determine the smallest number - list is empty" << endl; 
    else if (selection == 'L' or selection == 'l')
      if (container.size() != 0)
      {
        auto element = container.cbegin();
        int largest {*element};
        for (auto it : container)
        {
          if (largest < it)
            largest = it;
        }
        cout << "The largest is: " << largest << endl;
      }
      else
        cout << "Unable to determine the largest number - list is empty" << endl; 
    else if (selection == 'C' or selection == 'c')
    {
      if (container.size() != 0)
      {
        for (auto it = container.begin(); it != container.end();) 
        {
          auto cnt = container.count(*it);
          std::cout << *it << ":\t" << cnt << endl;
          std::advance(it, cnt); // move to the next different element
        }
      }
      else
        cout << "Unable to count - list is empty" << endl;
    }
    else if (selection == 'F' or selection == 'f')
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
        } 
        else 
        {
          cout << number << " Not found" << endl;
        }
      }
      else
        cout << "Unable to find - list is empty" << endl;
    }      
    else if (selection == 'Q' or selection == 'q')
        cout << "Goodbye..." << endl;
    else 
        cout << "Unknown option -- try again..." << endl;
  
  } 
  while ( selection != 'q' && selection != 'Q');

  cout << endl;
  return 0;
}

