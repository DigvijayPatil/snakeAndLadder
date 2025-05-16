#ifndef  __DP_GAME__
#define __DP_GAME__

#include <map>
#include <memory>
#include <vector>

#include <player.hpp>
#include <board.hpp>
#include "dice.hpp"

class Game 
{
public:
	Game();
	~Game();

	void addPlayers(std::unique_ptr<Player> player);
	bool play();

private:
	int rollDice(int playerId);

	std::vector<std::unique_ptr<Player>> m_PlayersList;
	std::unique_ptr<Board> m_pBoard;
	std::unique_ptr<Dice> m_pDice;
	int m_iCurrentPlayerIndex;
};


#endif // ! __DP_GAME__
