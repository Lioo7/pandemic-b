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
        Board &board;
        City city;
        string player_role;
        unordered_set<City> cards;
        unordered_set<City> cards_in_color;

        // This is an utility function which checks if the player have 'n' cards from the given color
        bool count_cards(Color color, int num_of_cards);
        // This is an utility function which checks if the player have 'n' cards
        bool count_cards(int num_of_cards);
        // This is an utility function which discards 'n' cards of the player from the given color
        void discard_cards();
        // This is an utility function which checks if the player is trying to move to his current city
        bool is_same_city(City c);

    public: 
        // Constructor
        Player(Board &board, City city, string player_role = "role") : board(board), city(city), player_role(player_role) {}
        // This function drives the player from the current city to the nearby city
        virtual Player &drive(City nearby_city);
        // This funciton takes the player from the current city to the given city
        virtual Player &fly_direct(City given_city);
        // This funciton takes the player from the current city to any city in the board
         virtual Player &fly_charter(City any_city);
        // This function takes the player to another city with a research station iff the current city has one
        virtual Player &fly_shuttle(City research_city);
        // This function builds a research station in the current city
        virtual Player &build();
        // This function discovers a cure for the disease according to the given color
        virtual Player &discover_cure(Color disease_color);
        // This function reduces the level of illness in the current city by one
        virtual Player &treat(City treat_city);
        // This function returns the role of the player
        string role() { return player_role; }
        // This function adds the given card to this player
        Player &take_card(City c);
        // This function remove all the cards of the player
        void remove_cards();
    };
}