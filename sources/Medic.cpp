#include "Medic.hpp"
using namespace pandemic;
// TODO: what i hvae to do here?
Player &Player::treat(City city)
{
    Board board;
    // the given city is healty
    if (board.get_illness_level().at(city) == 0)
    {
        throw invalid_argument("The city [" + to_string(city) + "] is healty");
    }
    else
    {
        // founds the color of the given city
        Color city_color = cities_color.at(city);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            // reduces the illness level in the given city to zero
            board.get_illness_level().at(city) = 0;
        }
        else
        {
            // reduces the illness level in the given city by one
            int illness_level = board.get_illness_level().at(city);
            board.get_illness_level().at(city) = 0;
        }
    }
    return *this;
}