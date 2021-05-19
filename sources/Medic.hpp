#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &board, City city) : Player(board, city, "Medic"){};
        Player &drive(City nearby_city);
        Player &fly_direct(City given_city);
        Player &fly_charter(City any_city);
        Player &fly_shuttle(City research_city);
        Player &treat(City treat_city);
        void auto_treat_check();
    };
}