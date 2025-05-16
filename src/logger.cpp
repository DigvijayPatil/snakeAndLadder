#include "logger.hpp"

Logger::Logger()
{
}

Logger* Logger::getInstance()
{
	if (m_pInstance)
		m_pInstance = new Logger();

	return m_pInstance;
}

void Logger::printSeperator()
{
	std::cout << "===========================================\n";
}

void Logger::printMsg(std::string msg, LoggerType type)
{
	switch (type)
	{
	case LoggerType::INFO:
		std::cout << "INFO\t" << msg << "\n";
		break;
	case LoggerType::WARNING:
		std::cout << "WARNING\t" << msg << "\n";
		break;
	case LoggerType::ERROR:
		std::cout << "ERROR\t" << msg << "\n";
		break;
	default:
		break;
	}
}

Logger* Logger::m_pInstance{ nullptr };