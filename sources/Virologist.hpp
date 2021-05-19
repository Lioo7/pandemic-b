#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        Virologist(Board &board, City city) : Player(board, city, "Virologist"){};
        Player &treat(City city);
    };
}