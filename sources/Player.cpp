#include "Player.hpp"

namespace pandemic
{ // TODO: fix space
        // This is an utility function which checks if the player have 'n' cards from the given color
        bool Player::count_cards(Color color, int num_of_cards)
        {
                bool ans = false;
                // clears the set
                cards_in_color.clear();
                // iterates through all the cards
                for (const auto &card : cards)
                {
                        // found five cards from the same color
                        if (cards_in_color.size() == num_of_cards)
                        {
                                ans = true;
                                break;
                        }
                        // the card is in the given color
                        if (cities_color.at(card) == color)
                        {
                                cards_in_color.insert(card);
                        }
                }
                return ans;
        }

        // This is an utility function which checks if the player have 'n' cards
        bool Player::count_cards(int num_of_cards)
        {
                bool ans = false;
                // clears the set
                cards_in_color.clear();
                // iterates through all the cards
                for (const auto &card : cards)
                {
                        // found five cards
                        if (cards_in_color.size() == num_of_cards)
                        {
                                ans = true;
                                break;
                        }
                        cards_in_color.insert(card);
                }
                return ans;
        }

        // This is an utility function which discards 'n' cards of the player from the given color
        void Player::discard_cards()
        {
                // iterates through all the 'n' cards form the same color that have benn found
                for (const auto &card : cards_in_color)
                {
                        // discards the card
                        cards.erase(card);
                }
        }

        // This function drives the player from the current city to the nearby city
        Player &Player::drive(City nearby_city)
        {
                // the cities are neighbours
                if (board.get_city_neighbours().at(city).count(nearby_city) > 0)
                {
                        // updates the current city
                        city = nearby_city;
                }
                else
                {
                        throw invalid_argument("[" + to_string(nearby_city) + "] is not nearby [" + to_string(city) + "]");
                }
                return *this;
        }

        // This funciton takes the player from the current city to the given city
        Player &Player::fly_direct(City given_city)
        {
                if (cards.count(given_city) > 0)
                {
                        // updates the current city and discards the card
                        city = given_city;
                        cards.erase(given_city);
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + to_string(given_city) + "] card");
                }
                return *this;
        }

        // This funciton takes the player from the current city to any city in the board
        Player &Player::fly_charter(City any_city)
        {
                // the player has the card of his current city
                if (cards.count(city) > 0)
                {
                        // updates the current city and discards the card
                        city = any_city;
                        cards.erase(city);
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + to_string(city) + "] card");
                }
                return *this;
        }

        // This function takes the player to another city with a research station iff the current city has one
        Player &Player::fly_shuttle(City research_city)
        {
                // this current city has a research station
                if (board.get_research_stations().count(city) > 0)
                {
                        // this given city has a research station
                        if (board.get_research_stations().count(research_city) > 0)
                        {
                                // updates the current city and discards the card
                                city = research_city;
                                cards.erase(research_city);
                        }
                        else
                        {
                                throw invalid_argument("There is not any research station in [" + to_string(research_city) + "] (dest)");
                        }
                }
                else
                {
                        throw invalid_argument("There is not any research station in [" + to_string(city) + "] (src)");
                }
                return *this;
        }

        // This function builds a research station in the current city
        Player &Player::build()
        {
                // the player has the card of his current city
                if (cards.count(city) > 0)
                {
                        // there is not any research station in the city
                        if (board.get_research_stations().count(city) == 0)
                        {
                                // building a r.s and discards the card
                                board.get_research_stations().insert(city);
                                cards.erase(city);
                        }
                        else
                        {
                                throw invalid_argument("There is already a research station in [" + to_string(city) + "]");
                        }
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + to_string(city) + "] card");
                }
                return *this;
        }

        // This function discovers a cure for the disease according to the given color
        Player &Player::discover_cure(Color disease_color)
        {
                // this current city has a research station
                if (board.get_research_stations().count(city) > 0)
                {
                        // No cure for the disease has been discovered yet
                        if (board.get_cures().count(disease_color) == 0)
                        {
                                // the player has five cards in the color of the given disease
                                if (count_cards(disease_color, 5))
                                {
                                        // adds a cure to this given disease
                                        board.get_cures().insert(disease_color);
                                        // discard the five cards from the given color
                                        discard_cards();
                                }
                                else
                                {
                                        throw invalid_argument("The player does not have enough  [" + to_string(disease_color) + "] cards");
                                }
                        }
                }
                else
                {
                        throw invalid_argument("There is not any research station in [" + to_string(city) + "] (src)");
                }
                return *this;
        }

        // This function reduces the level of illness in the current city by one
        Player &Player::treat(City treat_city)
        {
                if (city != treat_city)
                {
                        throw invalid_argument("Your card is[" + to_string(treat_city) + "], but you are at [" + to_string(city) + "]");
                }
                // the given city is healty
                if (board.get_illness_level().at(treat_city) == 0)
                {
                        throw invalid_argument("The city [" + to_string(treat_city) + "] is healty");
                }
                else
                {
                        // founds the color of the given city
                        Color city_color = cities_color.at(treat_city);
                        // the given city already has a cure
                        if (board.get_cures().count(city_color) > 0)
                        {
                                // reduces the illness level in the given city to zero
                                board.get_illness_level().at(treat_city) = 0;
                        }
                        else
                        {
                                // reduces the illness level in the given city by one
                                int illness_level = board.get_illness_level().at(treat_city);
                                board.get_illness_level().at(treat_city) = illness_level - 1;
                        }
                }
                return *this;
        }

        // This function adds the given card to this player
        Player &Player::take_card(City c)
        {
                cards.insert(c);
                return *this;
        }

        // This function remove all the cards of the player
        void Player::remove_cards()
        {
                cards.clear();
        }
}