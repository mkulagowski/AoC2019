#pragma warning(disable: 5050)
import std.core;
import utils;
import day1;

constexpr auto FILEPATH = "./input.txt";

void part1(const std::vector<int64_t>& inputTable)
{
	uint64_t fuelNeeded = 0;
	for (const auto& i : inputTable)
	{
		const int64_t fuel = calcFuel(i);
		if (fuel > 0)
			fuelNeeded += fuel;
	}

	std::cout << "Part1 answer: " << fuelNeeded << std::endl;
}

void part2(const std::vector<int64_t>& inputTable)
{
	uint64_t fuelNeeded = 0;
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
}

int main()
{
	const std::string input = readFileToString(FILEPATH);
	std::vector<int64_t> inputTable = splitStringToInt(input, '\n');

	part1(inputTable);
	part2(inputTable);

	wait();
	
	return 0;
}