#include "Dispatcher.hpp"
using namespace pandemic;

Player &Player::fly_direct(City given_city)
{
    Board board;
    // there is a research station in the city
    if (board.get_research_stations().count(city) == 1)
    {
        // updates the current city
        city = given_city;
    }
    return *this;
}