#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
        private:

        public: 
        Researcher(Board board, City city) : Player(board, city){};
    };
}