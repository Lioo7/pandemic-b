#include "Dispatcher.hpp"
using namespace pandemic;

Player &Dispatcher::fly_direct(City given_city)
{
    printf("Dispatcher is flying direct!");
    // there is a research station in the city
    if (board.get_research_stations().count(city) == 1)
    {
        // updates the current city
        city = given_city;
    }
    return *this;
}