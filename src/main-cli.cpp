#include "cli.h"

int main(){
	flashCards* flash_card_deck = new flashCards("config.txt");

	for(int i = 0; i < 3; i++)
	{
		flash_card_deck->shuffleDeck();

		std::cout << flash_card_deck->current_card->front << std::endl;
		std::cout << flash_card_deck->current_card->back << std::endl;
	}

	return 0;
};
