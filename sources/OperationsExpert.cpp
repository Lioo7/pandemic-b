#include "OperationsExpert.hpp"
using namespace pandemic;

Player &Player::build()
{
    Board board;
    // building a research station
    board.get_research_stations().insert(city);
    return *this;
}