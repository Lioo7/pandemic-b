#include "Scientist.hpp"
using namespace pandemic;

Player &Player::discover_cure(Color disease_color)
{
    Board board;
                // this current city has a research station
                if (board.get_research_stations().count(city) > 0)
                {
                        // No cure for the disease has been discovered yet
                        if (board.get_cures().count(disease_color) == 0)
                        {
                                // the player has 'n' cards in the color of the given disease
                                if (count_cards(disease_color, num))
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
                }
                else
                {
                        throw invalid_argument("There is not any research station in [" + city + "] (src)");
                }
                return *this;
}
