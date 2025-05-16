#include "game.hpp"
#include <iostream>

Game::Game() : m_pBoard{std::make_unique<Board>()}, m_iCurrentPlayerIndex(0)
{
	std::cout << "Game Constructor called \n";
}

Game::~Game()
{
	std::cout << "Game de-structor called \n";
}

void Game::addPlayers(std::unique_ptr<Player> player)
{
	// Adding Player into the vector we need to move it from current to vector.
	m_PlayersList.push_back(std::move(player));
}

int Game::rollDice(int playerId)
{
	return m_PlayersList[playerId]->rollDice(*m_pDice);

}

bool Game::play()
{
	int pos = rollDice(m_iCurrentPlayerIndex);

	if (m_pBoard->updatePositionAndValidate(m_PlayersList[m_iCurrentPlayerIndex].get()))
	{
		std::cout << "**************\n" << m_PlayersList[m_iCurrentPlayerIndex]->getName() << " Won the Match\n";
		return true;
	}

	m_iCurrentPlayerIndex++;

	if (m_iCurrentPlayerIndex >= m_PlayersList.size()) m_iCurrentPlayerIndex = 0;
	return false;
}

