#include "Medic.hpp"
using namespace pandemic;
// TODO: what i hvae to do here?

void Medic::auto_treat_check()
{
    // if the city is not healty
    if (board.get_illness_level().at(city) != 0)
    {
        // founds the color of the current city
        Color city_color = cities_color.at(city);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            // reduces the illness level in the given city to zero
            board.get_illness_level().at(city) = 0;
        }
    }
}

Player &Medic::treat(City treat_city)
{
    // the given city is healty
    if (board.get_illness_level().at(treat_city) == 0)
    {
        throw invalid_argument("The city [" + to_string(treat_city) + "] is healty");
    }
    else
    {
        // founds the color of the given city
        Color city_color = cities_color.at(treat_city);
        // the given city already has a cure
        if (board.get_cures().count(city_color) > 0)
        {
            // reduces the illness level in the given city to zero
            board.get_illness_level().at(treat_city) = 0;
        }
        else
        {
            // reduces the illness level in the given city by one
            int illness_level = board.get_illness_level().at(treat_city);
            board.get_illness_level().at(treat_city) = 0;
        }
    }
    return *this;
}

Player &Medic::drive(City nearby_city)
{
    Player::drive(nearby_city);
    auto_treat_check();
    return *this;
}
Player &Medic::fly_direct(City given_city)
{
    Player::fly_direct(given_city);
    auto_treat_check();
    return *this;
}
Player &Medic::fly_charter(City any_city)
{
    Player::fly_charter(any_city);
    auto_treat_check();
    return *this;
}
Player &Medic::fly_shuttle(City research_city)
{
    Player::fly_shuttle(research_city);
    auto_treat_check();
    return *this;
}