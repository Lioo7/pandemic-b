#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        map<City, unordered_set<City>> city_neighbours;
        map<City, int> illness_level;
        unordered_set<Color> cures;
        unordered_set<City> research_stations;

    public:
        // Constructor
        Board() {}
        // Getters
        map<City, unordered_set<City>> get_city_neighbours()
        {
            return city_neighbours;
        }
        map<City, int> get_illness_level()
        {
            return illness_level;
        }
        unordered_set<Color> get_cures()
        {
            return cures;
        }
        unordered_set<City> get_research_stations()
        {
            return research_stations;
        }

        // This function gets city name and returns the level of illness in the city
        int &
        operator[](City city);
        // This funciton display the status of the board
        friend ostream &operator<<(ostream &output, Board &board);
        // This function returns true iff the board is clean(no illness cubes)
        bool is_clean();
        // This function removes all the cures that discovered from the board
        void remove_cures();
        // This function removes all the research stations that discovered from the board
        void remove_stations();
    };
}