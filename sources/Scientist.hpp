#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int n; 
    public:
        Scientist(Board &board, City city, int num) : Player(board, city, "Scientist"){
            this->n = num;
        }
        Player &discover_cure(Color disease_color) override;
    };
}