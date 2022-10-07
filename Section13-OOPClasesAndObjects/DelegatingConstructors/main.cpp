// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
  std::string name;
  int health;
  int xp;

public:
// Overloaded Constructors
  Player();
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);
};

// Default constructor
Player::Player() : Player {"None", 0, 0} // Use the delegate constructor
{
  cout << "No-args constructor" << endl;
  cout << "name: " << name << endl;
  cout << "health: " << health << endl;
  cout << "xp: " << xp << endl << endl;
}

// Overloaded constructor with one-arg
Player::Player(std::string name_val) : 
  Player {name_val, 0, 0}  // Use the delegate constructor
{
  cout << "One-arg constructor" << endl;
  cout << "name: " << name << endl;
  cout << "health: " << health << endl;
  cout << "xp: " << xp << endl << endl;
}
  
// Delegate constructor with all-args
Player::Player(std::string name_val, int health_val, int xp_val) : 
  name {name_val}, 
  health {health_val}, 
  xp {xp_val} 
{
  cout << "The delegate constructor with three-args" << endl;
  cout << "name: " << name << endl;
  cout << "health: " << health << endl;
  cout << "xp: " << xp << endl << endl;
}

int main() {
    
  Player empty;
  Player frank {"Frank"};
  Player villain {"Villain", 100, 55};
    
  return 0;
}

