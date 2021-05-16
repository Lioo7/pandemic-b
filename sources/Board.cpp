#include "Board.hpp"

namespace pandemic
{
  // This function gets city name and returns the level of illness in the city
  int &Board::operator[](City city)
  {
    return this->illness_level[city];
  }
  // This funciton display the status of the board
  ostream &operator<<(ostream &output, Board &board)
  {
    output << "Board status:" << endl;
    output << "============:" << endl;
    output << "Illness level:" << endl;
    for (const auto &it : board.illness_level)
    {
      cout << it.first // City
           << ':'
           << it.second // level
           << endl;
    }

    output << "============:" << endl;
    output << "Cures found:" << endl;
    for (const auto &curse : board.cures)
    {
      cout << curse << endl;
    }

    output << "============:" << endl;
    output << "Research stations built:" << endl;
    for (const auto &station : board.research_stations)
    {
      cout << station << endl;
    }

    return output;
  }
  // This function returns true iff the board is clean(no illness cubes)
  bool Board::is_clean()
  {
    bool ans = true;
    for (const auto &city : illness_level)
    {
      if (illness_level.at(city.first) != 0)
      {
        ans = false;
        break;
      }
    }
    return ans;
  }
  
  // This function removes all the cures that discovered from the board
  void Board::remove_cures()
  {
    cures.clear();
  }

  // This function removes all the research stations that discovered from the board
  void Board::remove_stations()
  {
    research_stations.clear();
  }

}