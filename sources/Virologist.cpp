#include "Virologist.hpp"
using namespace pandemic;

Player &Virologist::treat(City c)
{
    printf("if1\n");
    // if the viro not in his city or not have the card of the city
    if (c != city && cards.count(c) == 0)
    {
        throw invalid_argument("The player does not have the [" + get_city_name(c) + "] card");
    }
    // the given city is healty
    if (board.get_illness_level().at(c) == 0)
    {
        printf("if2\n");
        throw invalid_argument("The city [" + to_string(c) + "] is healty");
    }
    else
    {
        printf("if3\n");
        // founds the color of the given city
        Color city_color = cities_color.at(c);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            printf("if4\n");
            // reduces the illness level in the given city to zero
            board.set_illness_level(c, 0);
        }
        else
        {
            printf("if5\n");
            // reduces the illness level in the given city by one
            int illness_level = board.get_illness_level().at(c);
            board.set_illness_level(c, illness_level - 1);
        }
    }
    return *this;
}