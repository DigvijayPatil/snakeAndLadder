#include <iostream>
#include <memory>

#include "game.hpp"
#include "dice.hpp"
#include "logger.hpp"


int main()
{
	Game game;
	Logger* logger = Logger::getInstance();

	int numPlayers{0};
	std::cout << "Enter Number of Players : \n";
	std::cin >> numPlayers;

	for (int i = 0; i < numPlayers; i++)
	{
		std::string name;
		std::cout << "Create Player " << i << "\n" << "	Enter Player Name : ";
		std::cin >> name;
		std::unique_ptr<Player> player = std::make_unique<Player>(name);
		game.addPlayers(std::move(player));
		logger->printSeperator();
	}

	bool isGameOver = false;
	while (!isGameOver)
	{
		char input;
		std::cout << "Enter any key to continue and \'q\' for quitting the game !\n";
		std::cin >> input;
		if (input == 'q')
			isGameOver = true;
		isGameOver = game.play();
	}
	return 0;
}