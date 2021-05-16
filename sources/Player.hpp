#pragma once
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
using namespace std;
namespace pandemic
{
    class Player
    {
    protected:
        Board board;
        City city;
        string role;
        unordered_set<City> cards;
        unordered_set<City> cards_in_color;

        // This is an utility function which checks if the player have five cards from the given color
        bool five_cards(Color color);
        // This is an utility function which discards five cards of the player from the given color
        void discard_five();

    public:
        // Constructor
        Player(Board &board, City &city, string role = "player_role") {}
        // This function drives the player from the current city to the nearby city
        Player &drive(City nearby_city);
        // This funciton takes the player from the current city to the given city
        Player &fly_direct(City given_city);
        // This funciton takes the player from the current city to any city in the board
        Player &fly_charter(City any_city);
        // This function takes the player to another city with a research station iff the current city has one
        Player &fly_shuttle(City research_city);
        // This function builds a research station in the current city
        Player &build();
        // This function discovers a cure for the disease according to the given color
        Player &discover_cure(Color disease_color);
        // This function reduces the level of illness in the current city by one
        Player &treat(City city);
        // This function returns the role of the player
        string role() { return role; }
        // This function adds the given card to this player
        Player &take_card(City city);
        // This function remove all the cards of the player
        void remove_cards();
    };
}