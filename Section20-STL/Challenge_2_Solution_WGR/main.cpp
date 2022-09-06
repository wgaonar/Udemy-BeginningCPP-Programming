// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song 
{
private:
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;

public:
  // Default constructor
  Song() = default;

  // Overload constructor
  Song(std::string name, std::string artist, int rating)
    : name{name}, artist{artist}, rating{rating} 
    {}

  // Getters
  std::string get_name() const 
  {
    return name;
  }
  
  std::string get_artist() const 
  {
    return artist;
  }
  
  int get_rating() const 
  {
    return rating;
  }
  
  // Overload less "<" operator
  bool operator<(const Song &rhs) const  
  {
    return this->name < rhs.name;
  }
  
  // Overload equal "==" operator
  bool operator==(const Song &rhs) const  
  {
    return this->name == rhs.name;
  }
};

// Friend function for overloading "<<" operator
std::ostream &operator<<(std::ostream &os, const Song &s) 
{
  os  << std::setw(20) << std::left << s.name
      << std::setw(30) << std::left << s.artist
      << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu() 
{
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) 
{
  // This function should display 
  // Playing: followed by the song that is playing
   
  std::cout << "Playing:\n"<< song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) 
{
  // This function should display the current playlist 
  // and then the current song playing.

  for (const Song &s: playlist)
  {
    std::cout << s << std::endl;
  }

  play_current_song(current_song);
  std::cout << std::endl;
}

void add_new_song(std::list<Song> &playlist, auto &current_song)
{
  std::cout << "Adding and playing new song\n";

  // Clear the buffer
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout << "Enter song name: ";
  std::string name {};
  getline(std::cin, name);

  std::cout << "Enter song artist: ";
  std::string artist {};
  getline(std::cin, artist);

  std::cout << "Enter rating (1-5): ";
  int rating {0};
  std::cin >> rating;

  // Make the new song
  Song new_song(name, artist, rating);

  // Insert the new song BEFORE the current song
  playlist.emplace(current_song, new_song);

  // Move the iterator to the new added song
  current_song--;

}

int main() 
{

  std::list<Song> playlist {
          {"God's Plan",        "Drake",                     5},
          {"Never Be The Same", "Camila Cabello",            5},
          {"Pray For Me",       "The Weekend and K. Lamar",  4},
          {"The Middle",        "Zedd, Maren Morris & Grey", 5},
          {"Wait",              "Maroon 5",                 4},
          {"Whatever It Takes", "Imagine Dragons",           3}          
  };
    
  std::list<Song>::iterator current_song = playlist.begin();
    
    
  char selection{};

  while (selection != 'Q' and selection != 'q')
  {
    display_menu();
    std::cin >> selection;

    switch (selection)
    {
    case 'F':
    case 'f':
      current_song = playlist.begin();
      play_current_song(*current_song);
      break;
    
    case 'N':
    case 'n':
      // Increment before check because .cend() is exclusive
      current_song++;
      if (current_song == playlist.cend())
      {
        current_song = playlist.begin();
      }
      play_current_song(*current_song);
      break;

    case 'P':
    case 'p':
      if (current_song == playlist.cbegin())
      {
        current_song = playlist.end();
      }
      // Increment after check because .cbegin() is inclusive
      current_song--;
      play_current_song(*current_song);
      break;

    case 'A':
    case 'a':
      add_new_song(playlist, current_song);
      play_current_song(*current_song);
      break;
    
    case 'L':
    case 'l':
      display_playlist(playlist, *current_song);
      break;

    default:
      break;
    }
  }
  
  std::cout << "Thanks for listening!" << std::endl;
  return 0;
}