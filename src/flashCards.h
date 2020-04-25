#pragma once

#include <fstream>
#include <exception>
#include <random>
#include <algorithm>

// Represents a set of flash cards
class flashCards
{
public:
	flashCards(std::string config_file_name);
	~flashCards();

public:
	class card
	{
	public:
		card(std::string front, std::string back);
		~card();
	
	public:
		std::string front;
		std::string back;
		std::string flip();
	};

	std::vector<card *> all_cards;
	card* current_card;

	card* shuffleDeck();
	card* nextCard();
	card* previousCard();

	private:
		int current_card_index;
		std::random_device random_number_generator;
		std::vector<card *> readConfig(std::string config_file_name);
};
