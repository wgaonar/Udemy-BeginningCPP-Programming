// Section 13
// Copy Constructor
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
  // Default parameters constructor
  Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);

  // Copy constructor
  Player(const Player &source);
  
  // Destructor
  ~Player() { cout << "Destructor called for: " << name << endl; }

  // Accessor member functions
  std::string get_name() const { return name; }
  int get_health() const { return health; }
  int get_xp() const {return xp; } 
};

// Default parameters constructor
Player::Player(std::string name_val, int health_val, int xp_val) : 
  name{name_val},
  health{health_val}, 
  xp{xp_val} 
{ cout << "Three-args constructor for " + name << endl; }

// Copy constructor
Player::Player(const Player &source) :
  // Option 1: initialize member by member
  // name{source.name}, health {source.health}, xp{source.xp}

  // Option 2: use the delegate constructor with the default parameters constructor
  Player {source.name, source.health, source.xp}  
{ cout << "Copy constructor - made copy of: " << source.name << endl; }

// Outside class function
void display_player(Player p) 
{
  cout << "Name: " << p.get_name() << endl;
  cout << "Health: " << p.get_health() << endl;
  cout << "XP: " << p.get_xp() << endl;    
}

int main() 
{ 
  Player nothing;   
  Player empty {"XXXXXX", 100, 50};
  
  Player my_new_object {empty};
  
  display_player(empty);
  
  Player frank {"Frank"};
  Player hero {"Hero", 100};
  Player villain {"Villain", 100, 55};
      
  return 0;
}