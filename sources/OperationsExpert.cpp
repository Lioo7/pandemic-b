#include "OperationsExpert.hpp"
using namespace pandemic;

Player &OperationsExpert::build()
{
    // building a research station
    board.add_research_station(city);
    return *this;
}