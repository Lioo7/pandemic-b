#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
        private:

        public: 
        Medic(Board board, City city) : Player(board, city){};
    };
}