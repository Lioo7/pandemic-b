#include "Virologist.hpp"
using namespace pandemic;

Player &Virologist::treat(City c)
{
    // the given city is healty
    if (board.get_illness_level().at(c) == 0)
    {
        throw invalid_argument("The city [" + to_string(c) + "] is healty");
    }
    else
    {
        // founds the color of the given city
        Color city_color = cities_color.at(c);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            // reduces the illness level in the given city to zero
            board.get_illness_level().at(c) = 0;
        }
        else
        {
            // reduces the illness level in the given city by one
            int illness_level = board.get_illness_level().at(c);
            board.get_illness_level().at(c) = illness_level - 1;
        }
    }
    return *this;
}