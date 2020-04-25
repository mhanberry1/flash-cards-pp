#include "flashCards.h"

flashCards::flashCards(std::string config_file_name)
{
	
	// Initialize all_cards, and current_card attributes
	all_cards = readConfig(config_file_name);
	current_card = all_cards[0];
}

flashCards::card::card(std::string front, std::string back)
{
	// Initialize front and back attributes
	this->front = front;
	this->back = back;
}

std::string flashCards::card::flip(){

	// Flip the values of front and back, then return the new value of front 
	std::string temp = back;
	back = front;
	return front = temp;
}

flashCards::card* flashCards::shuffleDeck()
{
	// Create a random number generator and shuffle all_cards
	std::shuffle(all_cards.begin(), all_cards.end(), random_number_generator);
	return current_card = all_cards[0];
}

flashCards::card* flashCards::nextCard()
{
	// If all cards have been used, set current_card to nullptr and return
	if(current_card == nullptr || ++current_card_index >= all_cards.size())
		return current_card = nullptr;

	// Else, set current_card to the next card and return
	else
		return current_card = all_cards[current_card_index];
}

flashCards::card* flashCards::previousCard()
{
	// If we are already at the beginning of the deck, return current_card
	if(current_card_index == 0)
		return current_card;
	
	// Else, set current_card to the previous card and return
	else
		return current_card = all_cards[--current_card_index];
}

std::vector<flashCards::card *>flashCards::readConfig(std::string config_file_name)
{
	std::ifstream config_file(config_file_name);
	std::string front;
	std::vector<card *> all_cards;

	// If the file is open, read it
	if(config_file.is_open()){
		while(getline(config_file, front)){
			std::string back;
			getline(config_file, back);
			all_cards.push_back(new card(front, back));
		}
		config_file.close();
	}

	// Else, throw an exception
	else throw std::ios_base::failure("Could not open 'config.txt'");

	return all_cards;
}
