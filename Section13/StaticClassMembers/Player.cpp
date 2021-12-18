#include "Player.h"

int Player::num_players {0}; // Initialize static variable of the class

// Overload constructor
Player::Player(std::string name_val, int health_val, int xp_val) : 
  name{name_val}, 
  health{health_val}, 
  xp{xp_val} 
{ ++num_players; }

// Copy constructor
Player::Player(const Player &source) : 
  Player {source.name, source.health, source.xp}  
{}

// Destructor
Player::~Player() 
{ --num_players; }

// Static function that only has access to static class members
int Player::get_num_players() 
{ return num_players; }


