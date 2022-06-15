/******************************************************************
  * Section 13 Challenge with Raw Pointer
  * Movies.h
  * 
  * Models a collection of Movies as a std::vector
* ***************************************************************/
#include <iostream>
#include "Movies.h"

/*************************************************************************
  Movies no-args constructor
**************************************************************************/
Movies::Movies() 
{
  // Create in the heap new empty vector and direct pointer to it.
  movies = new std::vector<Movie>;
}

/*************************************************************************
  Deep Copy Constructor
**************************************************************************/
Movies::Movies (const Movies &source)
{
  // Create in the heap new vector and initialize it from 'source'
  movies = new std::vector<Movie>;
  *movies = *source.movies;
}

/*************************************************************************
  Move Constructor
**************************************************************************/
Movies::Movies (Movies &&source)
  : movies {source.movies}
{
  source.movies = nullptr;
}

/*************************************************************************
  Movies destructor
**************************************************************************/
Movies::~Movies() 
{
  // Delete the vector that was earlier created in the heap
  delete movies;
}

/*************************************************************************
add_movie expects the name of the move, rating and watched count

It will search the movies vector to see if a movie object already exists
with the same name. 

If it does then return false since the movie already exists
Otherwise, create a movie object from the provided information
and add that movie object to the movies vector and return true
*********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) 
{
  // Search for the movie int the vector member movies
  for (const auto &movie : *movies) 
  { 
    if (movie.get_name() == name)
    {
      std::cout << "The movie: \"" << name << "\" already exists!\n";
      return false;
    } 
  }

  // Add the movie to the vector member movies
  Movie movieToAdd {name, rating, watched}; 
  (*movies).push_back(movieToAdd); 
  std::cout << "The movie: \"" << name << "\" was added" << std::endl;
  return true;
}

/*************************************************************************
increment_watched expects the name of the move to increment the
watched count

It will search the movies vector to see if a movie object already exists
with the same name. 
If it does then increment that objects watched by 1 and return true.

Otherwise, return false since then no movies object with the movie name
provided exists to increment
*********************************************************************/
bool Movies::increment_watched(std::string name) 
{
  // Search for the movie in the vector member movies
  for (auto &movie : *movies) 
  {
    if (movie.get_name() == name) 
    { 
      movie.increment_watched(); 
      std::cout << "The views of the movie: \"" << name << "\" was incremented" <<  std::endl;
      return true;
    }
  }

  std::cout << "The movie: \"" << name << "\" does not exist! and can not be incremented\n";
  return false;
}

/*************************************************************************
remove_movie expects the name of the move

It will search the movies vector to see if a movie object already exists
with the same name. 

If it does then return false since the movie no exists
Otherwise, remove a movie object movie object to the movies vector and return true
*********************************************************************/
bool Movies::remove_movie(std::string name)
{
  // Search for the movie int the vector member movies
  size_t index {0};
  for (const auto &movie : *movies) 
  { 
    if (movie.get_name() == name)
    {
      // Remove the movie from the vector member movies
      (*movies).erase((*movies).begin()+index); 
      std::cout << "The movie: \"" << name << "\" was erased" << std::endl;
      return true;
    }
    index++; 
  }

  std::cout << "The movie: \"" << name << "\" does not exist! and can not be erased\n";
  return false;
}

/*************************************************************************
display

display all the movie objects in the movies vector.
for each movie call the movie.display method so the movie
object displays itself
*********************************************************************/
void Movies::display() const 
{
  if ((*movies).size() == 0)
    std::cout << "\nSorry, no movies to display\n" << std::endl;
  else
  {
    std::cout << "\n===================================\n";
    for (const auto &movie : *movies)
    { movie.display(); }
    std::cout << "===================================\n" << std::endl;
  }
}