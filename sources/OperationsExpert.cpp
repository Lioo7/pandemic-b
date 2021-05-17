#include "OperationsExpert.hpp"
using namespace pandemic;

Player &OperationsExpert::build()
{
    // building a research station
    board.get_research_stations().insert(city);
    return *this;
}