#ifndef __DP_BOARD__
#define	__DP_BOARD__

#include <map>

class Player;

class Board
{
public:
	Board();
	~Board();

	bool updatePositionAndValidate(Player * p);

private:
	std::map<int, int> m_Snake;
	std::map<int, int> m_Ladder;
};

#endif // ! __DP_BOARD__
