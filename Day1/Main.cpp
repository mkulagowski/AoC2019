#include "Day1.hpp"

import std.core;
import utils;

constexpr auto FILEPATH = "./input.txt";

int main()
{
	std::string input = readFileToString(FILEPATH);
	std::vector<int64_t> inputTable = splitStringToInt<'\n'>(input);

	uint64_t fuelNeeded = 0;
	for (const auto& i : inputTable)
	{
		const int64_t fuel = calcFuel(i);
		if (fuel > 0)
			fuelNeeded += fuel;
	}

	std::cout << "Part1 answer: " << fuelNeeded << std::endl;

	fuelNeeded = 0;
	for (const auto& i : inputTable)
	{
		int64_t fuel = calcFuel(i);
		do
		{
			fuelNeeded += fuel;
			fuel = calcFuel(fuel);
		} while (fuel > 0);
	}
	std::cout << "Part2 answer: " << fuelNeeded << std::endl;

	int n;
	std::cin >> n;
	
	return 0;
}