#include "player.hpp"

#include <iostream>
#include "dice.hpp"

Player::Player(std::string name) noexcept : m_sName{ name }, m_iPos{0}
{
	std::cout << "Player " << m_sName << " is Created\n";
}

int Player::rollDice(Dice& d)
{
	std::cout << "It me " << m_sName << " Its my turn \n";
	int i = d.roll();
	std::cout << "\t\t I got " << i << "\n";
	setPosition(i);
	return i;
}

void Player::setPosition(int pos)
{
	m_iPos = ((m_iPos + pos) > 100) ? m_iPos : m_iPos + pos;
	std::cout << m_sName << " Pos : " << m_iPos << "\n";
}

