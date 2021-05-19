#include "Dispatcher.hpp"
using namespace pandemic;

Player &Dispatcher::fly_direct(City given_city)
{
    // printf("Dispatcher is flying direct!\n");
    if (is_same_city(given_city))
    {
        throw invalid_argument("The player already at" + get_city_name(city) + "]!");
    }
    // if there is a research station in the city
    else if (board.get_research_stations().count(city) == 1)
    {
        // updates the current city
        city = given_city;
    }
    else if (cards.count(given_city) > 0)
    {
        // updates the current city and discards the card
        city = given_city;
        cards.erase(given_city);
    }
    else
    {
        throw invalid_argument("There is not a research station at " + get_city_name(city) + "] + does not have the destination card!");
    }
    return *this;
}