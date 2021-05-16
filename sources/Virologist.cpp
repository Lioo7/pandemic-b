#include "Virologist.hpp"
using namespace pandemic;

Player &Player::treat(City c)
{
    Board board;
    // the given city is healty
    if (board.get_illness_level().at(c) == 0)
    {
        throw invalid_argument("The city [" + c + "] is healty");
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