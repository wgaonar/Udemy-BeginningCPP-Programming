// Unscoped Enumerations examples
#include <iostream>
#include <vector>
#include <string>

// Used for test1
enum Direction { North, South, East, West };

// enum Street {Main, North, Elm};   // Error, can't use North again


// Used for test1
// This function expects a Direction paramater
// and returns its string representation
std::string direction_to_string(Direction direction) 
{
  std::string result;
  switch (direction) 
  {
    case North:
      result = "North";
      break;
    case South:
      result = "South";
      break;
    case East:
      result = "East";
      break;
    case West:
      result = "West";
      break;
    default:
      result = "Unknown direction";
  }
  return result;
}

// Simple example that shows the use of an unscoped enumeration
void test1() 
{
  std::cout << "\n--- Test1 simple enum --------------------\n" << std::endl;

  Direction direction {North};
  std::cout << "Direction " << direction << std::endl;    // 0
  std::cout << direction_to_string(direction) << std::endl; // North
  
  direction = West;
  std::cout << "\nDirection " << direction << std::endl;    // 3
  std::cout << direction_to_string(direction) << std::endl; // West

  
  // direction = 2;  // Compiler Error about an incompatible assignment
  
  // Be careful casting since the compiler will assume you know what you are doing!
  direction = Direction(100); // To avoid the error in the assignment
  std::cout << "\nDirection " << direction << std::endl;    // Displays 100!
  std::cout << direction_to_string(direction) << std::endl; // Unknown direction
  
  // This is what is happening behind the scenes!!!
  direction = static_cast<Direction>(100);
  std::cout << "\nDirection " << direction << std::endl;    // Displays 100!
  std::cout << direction_to_string(direction) << std::endl; // Unknown direction
}

// Used for test2
// Unscoped enumeration representing items for a grocery shopping list
enum Grocery_Item {Milk, Bread, Apple, Orange};

/*
  Overloading the stream insertion operator to insert
  the string representation of the provided Grocery_Item
  parameter into the output stream
*/
std::ostream &operator<<(std::ostream &os, const Grocery_Item& grocery_item)
{
	switch (grocery_item) 
  {
    case Milk:      
      os << "Milk"; 
      break;
		case Bread:     
      os << "Bread"; 
      break;
		case Apple:     
      os << "Apple"; 
      break;
		case Orange:    
      os << "Orange"; 
      break;
		default:        
      os << "Invalid item"; 
	}
	return os;
}

/*
  Used for test2
  Returns a boolean depending on whether the Grocery_Item
  parameter is a valid enumerator or not.
*/
bool is_valid_grocery_item(const Grocery_Item& grocery_item)
{
	switch (grocery_item) 
  {
    case Milk:  
    case Bread:
    case Apple:
    case Orange:
      return true;
		default:        
      return false; 
	}
}

/*
  Used for test2
  Displays the grocery items in the grocery list
  Given a vector of Grocery_Items, this function displays
  the string representation of each item using the overloaded
  operator<< function.
  This function also keeps track of how many valid and invalid items
  are in the provided vector by using the is_valid_grocery_item function
  written above.
*/
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
	std::cout << "Grocery List" << "\n==============================" << std::endl;
  int invalid_item_count{0};
  int valid_item_count {0};
	for (Grocery_Item grocery_item : grocery_list)
	{
		std::cout << grocery_item << std::endl;  // User the overloaded operator<<
		
		// Check that grocery is valid grocery item
		if (is_valid_grocery_item(grocery_item))
    {
      valid_item_count++;
    }
    else
    {
			invalid_item_count++;
    }
	}
	
	std::cout << "==============================" << std::endl;
  std::cout << "Valid items: " <<  valid_item_count << std::endl;
  std::cout << "Invalid items: " <<  invalid_item_count << std::endl;
	std::cout << "Total items: " <<  valid_item_count + invalid_item_count << std::endl;
}

// Using an unscoped enumeration to model grocery items
void test2() 
{
	std::cout << "\n--- Test2 vector of enums ----------------\n" << std::endl;
	
	std::vector<Grocery_Item> shopping_list;
    
	shopping_list.push_back(Apple);
	shopping_list.push_back(Apple);
	shopping_list.push_back(Milk);
	shopping_list.push_back(Orange);
	
  // Grocery_Item item = 100;                         // Compiler error
    
  // Be careful when casting
  int Helicopter {1000};
	shopping_list.push_back(Grocery_Item(Helicopter));  // It is an invalid item but WITHOUT error

  // Add items using the numeric key through casting
  shopping_list.push_back(Grocery_Item(0));           // Will add Milk again using casting!
  shopping_list.push_back(Grocery_Item(1));           // Will add Bread again using casting!
  shopping_list.push_back(Grocery_Item(2));           // Will add Apple again using casting!
  shopping_list.push_back(Grocery_Item(3));           // Will add Orange again using casting!
    
	display_grocery_list(shopping_list);
}

/*
  Used for test3
  Unscoped enumerations holding the possible states 
  and sequences of a rocket launch.
  Note the addition of the Unknown enumerator for the State enumeration.
*/
enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

/*
  Used for test3
  Overloading the stream extraction operator to allow a user
  to enter the state of State enumeration.
  enum state passed by reference to store the user input
  Note the use of underlying_type_t.
*/
std::istream &operator>>(std::istream &is, State &state) 
{
  // int user_input;   // Will also work
  std::underlying_type_t<State> user_input;
  is >> user_input;

  switch (user_input) 
  {
    case Engine_Failure:       
    case Inclement_Weather:
    case Nominal:
    case Unknown:
      state = State(user_input);  // Store the user input with casting to avoid the error in the assignment
      break;
    default:                   
      std::cout << "User input is not a valid launch state." << std::endl;
      state = Unknown;
  }

  return is;
}

/*
  Used for test 3
  Overloading the stream insertion operator to insert
  the string representation of the provided State
  parameter into the output stream
*/
std::ostream &operator<<(std::ostream &os, const State &state)
{
  switch (state)
  {
    case Engine_Failure:
      os << "Engine_Failure";
      break;
    case Inclement_Weather:
      os << "Inclement_Weather";
      break;
    case Nominal:
      os << "Nominal";
      break;
    case Unknown:
      os << "Unknown";
      break;
    default:
      break;
  }

  return os;
}

/*
  Used for test3
  Overloading the stream insertion operator to insert
  the string representation of the provided Sequence
  parameter into the output stream
*/
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
	switch (sequence) 
  {
    case Abort:    
      os << "Abort"; 
      break;
		case Hold:      
      os << "Hold"; 
      break;
		case Launch:    
      os << "Launch"; 
      break;
    }
	
	return os;
}

// Used for test3
// Displays an information message given the sequence parameter.
void initiate(Sequence sequence)
{
	std::cout << "Initiate " << sequence << " sequence!" << std::endl;   // Uses overloaded operator<< to print the Sequence enum
}

// Used for test3
// Displays the state.
void print_state(State state)
{
	std::cout << "The actual state is: " << state << std::endl;   // Uses overloaded operator<< to print the State enum
}

// Using unscoped enums to control a rocket launch
// Reads input from the user for the State of the rocket launch,
// and then determines which Sequence to execute.
void test3() 
{
	std::cout << "\n--- Test3 overloading << and  >> operators-------------\n" << std::endl;
	
	State state;
	std::cout << "Launch state: ";
	std::cin >> state;               // users the overloaded operator>>
	
  print_state(state); // Displays the actual state in string representation
	
  switch (state) 
  {
		case Engine_Failure:        // Abort if Engine Failure or Unknown!
    case Unknown:   
      initiate(Abort); 
      break;
		case Inclement_Weather:                 
      initiate(Hold); 
      break;
		case Nominal:                         
      initiate(Launch); 
      break;
	}    
}

int main()
{
  test1();
  test2();
	test3();
	
	std::cout << "\n";
	return 0;
}