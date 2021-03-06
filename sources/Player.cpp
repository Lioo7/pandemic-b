#include "Player.hpp"
const int cards_to_find = 5;

namespace pandemic
{
        //========================================Utility-Functions================================================

        // This is an utility function which checks if the player have 'n' cards from the given color
        bool Player::count_cards(Color color, int num_of_cards)
        {
                if (num_of_cards == 0)
                {
                        return true;
                }
                bool ans = false;
                int count = 0;
                // clears the set
                cards_in_color.clear();
                // iterates through all the cards
                for (const auto &card : cards)
                {
                        // the card is in the given color
                        if (cities_color.at(card) == color)
                        {
                                cards_in_color.insert(card);
                        }
                        // found five cards from the same color
                        count = cards_in_color.size();
                        if (count >= num_of_cards)
                        {
                                ans = true;
                                break;
                        }
                }
                return ans;
        }

        // This is an utility function which checks if the player have 'n' cards
        bool Player::count_cards(int num_of_cards)
        {
                if (num_of_cards == 0)
                {
                        return true;
                }
                bool ans = false;
                // clears the set
                cards_in_color.clear();
                // iterates through all the cards
                for (const auto &card : cards)
                {
                        cards_in_color.insert(card);
                        // found 'n' cards
                        if (cards_in_color.size() >= num_of_cards)
                        {
                                ans = true;
                                break;
                        }
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

        // This is an utility function which checks if the player is trying to move to his current city
        bool Player::is_same_city(City c)
        {
                return city == c;
        }

        //========================================Main-Functions================================================

        // This function drives the player from the current city to the nearby city
        Player &Player::drive(City nearby_city)
        {
                if (is_same_city(nearby_city))
                {
                        throw invalid_argument("The player already at" + get_city_name(city) + "]!");
                }
                // printf("driving!\n");
                // the cities are neighbours
                if (board.are_neighbors(city, nearby_city))
                {
                        // updates the current city
                        city = nearby_city;
                }
                else
                {
                        throw invalid_argument("[" + get_city_name(nearby_city) + "] is not nearby [" + get_city_name(city) + "]");
                }
                return *this;
        }

        // This funciton takes the player from the current city to the given city
        Player &Player::fly_direct(City given_city)
        {
                if (is_same_city(given_city))
                {
                        throw invalid_argument("The player already at" + get_city_name(city) + "]!");
                }
                // printf("flying direct!\n");
                if (cards.contains(given_city))
                {
                        // updates the current city and discards the card
                        cards.erase(given_city);
                        city = given_city;
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + get_city_name(given_city) + "] card");
                }
                return *this;
        }

        // This funciton takes the player from the current city to any city in the board
        Player &Player::fly_charter(City any_city)
        {
                // printf("flying charter!\n");
                // printf("From %s to %s\n", get_city_name(city).c_str(), get_city_name(any_city).c_str());
                if (is_same_city(any_city))
                {
                        throw invalid_argument("The player already at" + get_city_name(city) + "]!");
                }
                // the player has the card of his current city
                if (cards.count(city) > 0)
                {
                        // updates the current city and discards the card
                        cards.erase(city);
                        city = any_city;
                        // printf("erase %s\n", get_city_name(city).c_str());
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + get_city_name(city) + "] card");
                }
                return *this;
        }

        // This function takes the player to another city with a research station iff the current city has one
        Player &Player::fly_shuttle(City research_city)
        {
                if (is_same_city(research_city))
                {
                        throw invalid_argument("The player already at" + get_city_name(city) + "]!");
                }
                // this current city has a research station
                if (board.get_research_stations().count(city) != 0)
                {
                        // this given city has a research station
                        if (board.get_research_stations().count(research_city) > 0)
                        {
                                // updates the current city and discards the card
                                cards.erase(research_city);
                                city = research_city;
                        }
                        else
                        {
                                throw invalid_argument("There is not any research station in [" + get_city_name(research_city) + "] (dest)");
                        }
                }
                else
                {
                        throw invalid_argument("There is not any research station in [" + get_city_name(city) + "] (src)");
                }
                return *this;
        }

        // This function builds a research station in the current city
        Player &Player::build()
        {
                // printf("building!\n");
                // the player has the card of his current city
                if (cards.count(city) > 0)
                {
                        // if there is not any research station in the city
                        if (board.get_research_stations().count(city) == 0)
                        {
                                // building a r.s and discards the card
                                board.add_research_station(city);
                                cards.erase(city);
                        }
                }
                else
                {
                        throw invalid_argument("The player does not have the [" + get_city_name(city) + "] card");
                }
                return *this;
        }

        // This function discovers a cure for the disease according to the given color
        Player &Player::discover_cure(Color disease_color)
        {
                // printf("discover_cure!\n");
                // this current city has a research station
                if (board.get_research_stations().count(city) > 0)
                {
                        // No cure for the disease has been discovered yet
                        if (board.get_cures().count(disease_color) == 0)
                        {
                                // the player has five cards in the color of the given disease
                                if (count_cards(disease_color, cards_to_find))
                                {
                                        // printf("disease color: %d\n", disease_color);
                                        // adds a cure to this given disease
                                        board.add_cure(disease_color);
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
                        throw invalid_argument("There is not any research station in [" + get_city_name(city) + "] (src)");
                }
                return *this;
        }

        // This function reduces the level of illness in the current city by one
        Player &Player::treat(City treat_city)
        {
                // printf("treating!\n");
                if (city != treat_city)
                {
                        throw invalid_argument("Your card is[" + get_city_name(treat_city) + "], but you are at [" + get_city_name(city) + "]");
                }
                // the given city is healty
                if (board.get_illness_level().at(treat_city) == 0)
                {
                        throw invalid_argument("The city [" + get_city_name(treat_city) + "] is healty");
                }

                // founds the color of the given city
                Color city_color = cities_color.at(treat_city);
                // if the given city already has a cure
                if (board.get_cures().count(city_color) > 0)
                {
                        // reduces the illness level in the given city to zero
                        board.set_illness_level(treat_city, 0);
                }
                else
                {
                        // reduces the illness level in the given city by one
                        int illness_level = board.get_illness_level().at(treat_city);
                        board.set_illness_level(treat_city, illness_level - 1);
                }

                return *this;
        }

        // This function adds the given card to this player
        Player &Player::take_card(City c)
        {
                // printf("taking a card!\n");
                cards.insert(c);
                return *this;
        }

        // This function remove all the cards of the player
        void Player::remove_cards()
        {
                cards.clear();
        }
}