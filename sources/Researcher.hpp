#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
        public: 
        Researcher(Board &board, City city) : Player(board, city, "Researcher"){};
        Player &discover_cure(Color disease_color) override;
    };
}