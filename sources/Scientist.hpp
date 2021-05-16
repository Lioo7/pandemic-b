#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        private:

        public: 
        Scientist(Board board, City city, int amount) : Player(board, city){};
    };
}