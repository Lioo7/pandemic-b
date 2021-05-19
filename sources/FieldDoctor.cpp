#include "FieldDoctor.hpp"
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    printf("DiledDoctor is treating!\n");
    bool flag = false;
    // checks if the card is not equal to the current city
    if (c == city)
    {
        printf("if1\n");
        flag = true;
    }
    else if (board.are_neighbors(c, city))
    {
        printf("if2\n");
        flag = true;
        printf("flag = %d\n", flag);
    }

    else
    {
        printf("if3\n");
        // checks if the card is equal to any of the nearby cities of the current city
        for (City nei : board.get_city_neighbours().at(city))
        {
            printf("looping\n");
            if (board.are_neighbors(c, nei))
            {
                flag = true;
            }
        }
    }

    if (!flag)
    {
        throw invalid_argument("Your card is [" + get_city_name(c) + "], but you are at [" + get_city_name(city) + "] which has other neighbors");
    }

    // the given city is healty
    if (board.get_illness_level().at(c) == 0)
    {
        printf("the city is healty!\n");
        throw invalid_argument("The city [" + get_city_name(city) + "] is healty");
    }
    else
    {
        // founds the color of the given city
        Color city_color = cities_color.at(c);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            printf("redcue illness to 0!\n");
            // reduces the illness level in the given city to zero
            board.set_illness_level(c, 0);
        }
        else
        {
            printf("reduce city illness by 1\n");
            // reduces the illness level in the given city by one
            int illness_level = board.get_illness_level().at(c);
            board.set_illness_level(c, illness_level - 1);
        }
    }
    return *this;
}