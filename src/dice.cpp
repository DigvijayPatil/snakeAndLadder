#include "dice.hpp"

#include <random>

int Dice::roll()
{
	// Create Random Device
	std::random_device rd;

	// Seed Random Generator
	std::mt19937 gen(rd());

	// Define the range
	std::uniform_int_distribution<int> dist(1, 6);

	return dist(gen);
}