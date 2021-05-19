#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &board, City city) : Player(board, city, "Medic"){};
        Player &drive(City nearby_city) override;
        Player &fly_direct(City given_city) override;
        Player &fly_charter(City any_city) override;
        Player &fly_shuttle(City research_city) override;
        Player &treat(City treat_city) override;
        void auto_treat_check();
    };
}