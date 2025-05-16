#ifndef __DP_LOGGER__
#define __DP_LOGGER__

#include <string>
#include <iostream>

enum class LoggerType
{
	INFO,
	WARNING,
	ERROR,
};

class Logger
{
public:
	static Logger* getInstance();
	void printSeperator();
	void printMsg(std::string msg, LoggerType type = LoggerType::INFO);
private:
	Logger();
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	static Logger* m_pInstance;
};


#endif // ! __DP_GAME__
