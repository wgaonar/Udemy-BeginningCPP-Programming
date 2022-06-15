/******************************************************************
 * Section 13 Challenge with Raw Pointer
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

int main() {
    
  Movies my_movies;
    
  my_movies.display();
    
  my_movies.add_movie("Big", "PG-13", 2);              // OK
  my_movies.add_movie("Star Wars", "PG", 5);           // OK
  my_movies.add_movie("Cinderella", "PG", 7);          // OK
  my_movies.add_movie("Toy Story", "G",5); 
    
  my_movies.display();  // Big, Star Wars, Cinderella, Toy Story, 
    
  my_movies.add_movie("Cinderella", "PG",7);            // Already exists
  my_movies.add_movie("Ice Age", "PG",12);              // OK
 
  my_movies.display();    // Big, Star Wars, Cinderella, Toy Story, Ice Age
    
  my_movies.increment_watched("Big");                    // OK
  my_movies.increment_watched("Ice Age");              // OK
    
  my_movies.display();    // Big and Ice Age watched count incremented by 1
    
  my_movies.increment_watched("XXX");         // XXX not found

  my_movies.remove_movie("Toy Story");
  my_movies.display();

	return 0;
}