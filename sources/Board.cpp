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

  // adds all the cities to the map
  map<City, unordered_set<City>> Board::city_neighbours{
      {Algiers, {Madrid, Paris, Istanbul, Cairo}},
      {Atlanta, {Chicago, Miami, Washington}},
      {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
      {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
      {Beijing, {Shanghai, Seoul}},
      {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
      {BuenosAires, {Bogota, SaoPaulo}},
      {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
      {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
      {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
      {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
      {Essen, {London, Paris, Milan, StPetersburg}},
      {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
      {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
      {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
      {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
      {Johannesburg, {Kinshasa, Khartoum}},
      {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
      {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
      {Kinshasa, {Lagos, Khartoum, Johannesburg}},
      {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
      {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
      {Lima, {MexicoCity, Bogota, Santiago}},
      {London, {NewYork, Madrid, Essen, Paris}},
      {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
      {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
      {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
      {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
      {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
      {Milan, {Essen, Paris, Istanbul}},
      {Montreal, {Chicago, Washington, NewYork}},
      {Moscow, {StPetersburg, Istanbul, Tehran}},
      {Mumbai, {Karachi, Delhi, Chennai}},
      {NewYork, {Montreal, Washington, London, Madrid}},
      {Osaka, {Taipei, Tokyo}},
      {Paris, {Algiers, Essen, Madrid, Milan, London}},
      {Riyadh, {Baghdad, Cairo, Karachi}},
      {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
      {Santiago, {Lima}},
      {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
      {Seoul, {Beijing, Shanghai, Tokyo}},
      {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
      {StPetersburg, {Essen, Istanbul, Moscow}},
      {Sydney, {Jakarta, Manila, LosAngeles}},
      {Taipei, {Shanghai, HongKong, Osaka, Manila}},
      {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
      {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
      {Washington, {Atlanta, NewYork, Montreal, Miami}}};
}