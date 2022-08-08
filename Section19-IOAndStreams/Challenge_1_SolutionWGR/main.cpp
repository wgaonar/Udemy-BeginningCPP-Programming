// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void ruler() 
{
  std::cout << "12345678901234567890123456789012345678901234567890"
            << "12345678901234567890" << std::endl;
}

void line() 
{
  std::cout << std::setw(70) << std::setfill('-') << std::right << "" << std::endl;
  std::cout << std::setfill(' '); // Reset setfill to blank spaces
}

struct City 
{
  std::string name;
  long population;
  double cost;
};

// Assume each country has at least 1 city
struct Country 
{
  std::string name;
  std::vector<City> cities;
};

struct Tours 
{
  std::string title;
  std::vector<Country> countries;
};

int main()
{
  Tours tours;
  tours.title = "Tour Ticket Prices from Miami";

  Country colombia
  {
    "Colombia", { 
                  { "Bogota", 8778000, 400.98 },
                  { "Cali", 2401000, 424.12 },
                  { "Medellin", 2464000, 350.98 },
                  { "Cartagena", 972000, 345.34 } 
                }
  };

  Country brazil
  {
    "Brazil", { 
                { "Rio De Janeiro", 13500000, 567.45 },
                { "Sao Paulo", 11310000, 975.45 },
                { "Salvador", 18234000, 855.99 }
              }
  };

  Country chile
  {
    "Chile", { 
                { "Valdivia", 260000, 569.12 }, 
                { "Santiago", 7040000, 520.00 }
              }
  };

  Country argentina
  {
    "Argentina",  { 
                    { "Buenos Aires", 3010000, 723.77 } 
                  }
  };

  tours.countries.push_back(colombia);
  tours.countries.push_back(brazil);
  tours.countries.push_back(chile);
  tours.countries.push_back(argentina);

  /*
  // Another way to initialize the structure Tours
  { "Tour Ticket Prices from Miami",
    {
      {
        "Colombia", 
        { 
            { "Bogota", 8778000, 400.98 },
            { "Cali", 2401000, 424.12 },
            { "Medellin", 2464000, 350.98 },
            { "Cartagena", 972000, 345.34 } 
        },
      },
      {
        "Brazil", 
        { 
            { "Rio De Janiero", 13500000, 567.45 },
            { "Sao Paulo", 11310000, 975.45 },
            { "Salvador", 18234000, 855.99 }
        },
      },
      {
        "Chile", 
        { 
            { "Valdivia", 260000, 569.12 }, 
            { "Santiago", 7040000, 520.00 }
        },
      },
      { 
        "Argentina", 
        { 
          { "Buenos Aires", 3010000, 723.77 } 
        } 
      },
    }
  };
  */

  // Unformatted display so you can see how to access the vector elements
  std::cout << "\n--Unformatted display--------------------" << std::endl;
  std::cout << tours.title << std::endl;
  // loop through the countries
  for(auto &country : tours.countries) 
  {   
    std::cout << country.name << std::endl;
    // loop through the cities for each country 
    for(auto &city : country.cities) 
    {       
      std::cout << "\t" << city.name 
                << "\t" << city.population 
                << "\t" << city.cost 
                << std::endl;
    }
  }

  // Formatted display so you can see how to access the vector elements
  std::cout << std::endl << std::endl;
  ruler();
  // Format the title
  std::cout << std::endl;
  std::cout << std::setw(49) << tours.title << std::endl;
  std::cout << std::endl;
  // Format the table's header
  line();
  std::cout << std::setw(15) << std::left << "Country";
  std::cout << std::setw(15) << std::left << "City";
  std::cout << std::setw(20) << std::right << "Population";
  std::cout << std::setw(20) << std::setprecision(2) << std::fixed << std::right << "Price" << std::endl;
  line();
  // Format the table's content
  // loop through the countries
  for(auto &country : tours.countries) 
  {   
    // loop through the cities for each country
    for (size_t index = 0; index < country.cities.size(); ++index) 
    {
      std::cout << std::setw(15) << std::left << ((index == 0) ? country.name: "");
      std::cout << std::setw(15) << std::left << country.cities.at(index).name;
      std::cout << std::setw(20) << std::right << country.cities.at(index).population;
      std::cout << std::setw(14) << std::right << "$";
      std::cout << std::setw(6) << std::right << country.cities.at(index).cost << std::endl;
    }
    std::cout << std::endl;
  }
  
  return 0;
}