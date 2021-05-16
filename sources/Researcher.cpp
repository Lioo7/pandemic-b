#include "Researcher.hpp"
using namespace pandemic;

Player &Player::discover_cure(Color disease_color)
{
    Board board;
    // No cure for the disease has been discovered yet
    if (board.get_cures().count(disease_color) == 0)
    {
        // the player has five cards in the color of the given disease
        if (count_cards(disease_color, 5))
        {
            // adds a cure to this given disease
            board.get_cures().insert(disease_color);
            // discard the five cards from the given color
            discard_cards();
        }
        else
        {
            throw invalid_argument("The player does not have enough  [" + disease_color + "] cards");
        }
    }
    return *this;
}