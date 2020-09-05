#pragma warning(disable: 5050)
import std.core;
import utils;
import day4;

constexpr auto FILEPATH = "./input.txt";
constexpr int NUM_BEGIN = 372037;
constexpr int NUM_END = 905157;

void part1(const std::string& input)
{
	uint64_t counter = 0;
	for (int i = NUM_BEGIN; i < NUM_END; ++i)
		counter += isValidSimple(i);

	std::cout << "Part1 answer: " << counter << std::endl;
}

void part2(const std::string& input)
{
	uint64_t counter = 0;
	for (int i = NUM_BEGIN; i < NUM_END; ++i)
		counter += isValid(i);

	std::cout << "Part2 answer: " << counter << std::endl;
}

int main()
{
	const std::string input = readFileToString(FILEPATH);

	part1(input);
	part2(input);

	wait();
	
	return 0;
}