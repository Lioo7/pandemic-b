#include "Researcher.hpp"
using namespace pandemic;

Player &Researcher::discover_cure(Color disease_color)
{
    // No cure for the disease has been discovered yet
    if (board.get_cures().count(disease_color) == 0)
    {
        // the player has five cards in the color of the given disease
        if (count_cards(disease_color, 5))
        {
            // printf("disease_color(res): %d\n", disease_color);
            // adds a cure to this given disease
            board.add_cure(disease_color);
            // discard the five cards from the given color
            discard_cards();
        }
        else
        {
            throw invalid_argument("The player does not have enough  [" + to_string(disease_color) + "] cards");
        }
    }
    return *this;
}