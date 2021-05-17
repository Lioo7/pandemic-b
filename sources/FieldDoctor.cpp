#include "FieldDoctor.hpp"
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    bool flag = true;

    // checks if the card is equal to the current city 
    if (c == city)
    {
        flag = false;
    }
    else
    {
        // checks if the card is equal to any of the nearby cities of the current city
        // for (const City &current : board.get_city_neighbours().at(city))
        // {
        //     if (c == current)
        //     {
        //         flag = false;
        //     }
        // }
    }
    if (flag)
    {
        throw invalid_argument("Your card is[" + to_string(c) + "], but you are at [" + to_string(city) + "] or any of its nearby cities");
    }

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
            board.get_illness_level().at(city) = illness_level - 1;
        }
    }
    return *this;
}