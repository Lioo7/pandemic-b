#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int num; // TODO
    public:
        Scientist(Board &board, City &city, int n) : Player(board, city, "Scientist"), num(n){};
        Player &discover_cure(Color disease_color);
    };
}