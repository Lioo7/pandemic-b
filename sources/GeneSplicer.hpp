#pragma once
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
        private:

        public: 
        GeneSplicer(Board board, City city) : Player(board, city){};
    };
}