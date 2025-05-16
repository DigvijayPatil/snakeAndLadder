#ifndef __DP_PLAYER__
#define __DP_PLAYER__

#include <string>

class Dice;

class Player
{
public:
	Player(std::string name) noexcept;

	int rollDice(Dice & d);

	int getPosition() const { return m_iPos; }
	void setPosition(int pos);
	std::string getName() const { return m_sName; }

	~Player() noexcept {}

private:
	std::string m_sName;
	int m_iPos;
};


#endif // ! __DP_GAME__
