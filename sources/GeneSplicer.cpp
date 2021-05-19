#include "GeneSplicer.hpp"
using namespace pandemic;

Player &GeneSplicer::discover_cure(Color disease_color)
{
    // this current city has a research station
    if (board.get_research_stations().count(city) > 0)
    {
        // No cure for the disease has been discovered yet
        if (board.get_cures().count(disease_color) == 0)
        {
            // the player has five cards in the color of the given disease
            if (count_cards(5))
            {
                // adds a cure to this given disease
                board.add_cure(disease_color);
                // discard the five cards from the given color
                discard_cards();
            }
            else
            {
                throw invalid_argument("The player does not have enough cards");
            }
        }
    }
    else
    {
        throw invalid_argument("There is not any research station in [" + to_string(city) + "] (src)");
    }
    return *this;
}