#include "InputManager.hpp"
#include "Day1.hpp"
#include <iostream>

constexpr auto FILEPATH = "./input.txt";

int main()
{
	std::string input = InputManager::readFileToString(FILEPATH);
	std::vector<int> inputTable = InputManager::splitStringToInt<'\n'>(input);
	std::cout << input << std::endl;
	uint64_t fuelNeeded = 0;
	for (const auto& i : inputTable)
	{
		int fuel = calcFuel(i);
		if (fuel > 0)
			fuelNeeded += fuel;
	}
	std::cout << "Total fuel: " << fuelNeeded;
}