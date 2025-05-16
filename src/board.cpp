#include "board.hpp"
#include <iostream>
#include "player.hpp"

Board::Board()
{
	std::cout << "Board Constructor called \n";
	m_Snake[46] = 15;
	m_Snake[48] = 9;
	m_Snake[52] = 11;
	m_Snake[59] = 18;
	m_Snake[68] = 3;
	m_Snake[69] = 33;
	m_Snake[83] = 39;
	m_Snake[89] = 51;
	m_Snake[93] = 37;
	m_Snake[98] = 13;

	m_Ladder[8] = 26;
	m_Ladder[19] = 38;
	m_Ladder[21] = 82;
	m_Ladder[28] = 53;
	m_Ladder[36] = 57;
	m_Ladder[43] = 77;
	m_Ladder[50] = 91;
	m_Ladder[54] = 88;
	m_Ladder[61] = 99;
	m_Ladder[62] = 96;
	m_Ladder[66] = 87;
}

Board::~Board()
{
	std::cout << "Board de-structor called \n";
}

bool Board::updatePositionAndValidate(Player * p)
{
	int pos = p->getPosition();
	if (pos == 100)
	{
		return true;
	}
	auto snakeIt = m_Snake.find(pos);
	if (snakeIt != m_Snake.end())
	{
		std::cout << "Snake bite : " << pos << " to " << snakeIt->second << "\n";
		p->setPosition(snakeIt->second);
		return false;
	}

	auto ladderIt = m_Ladder.find(pos);
	if (ladderIt != m_Ladder.end())
	{
		std::cout << "Got the Ladder : " << pos << " to " << ladderIt->second << "\n";
		p->setPosition(ladderIt->second);
	}
	return false;
}

