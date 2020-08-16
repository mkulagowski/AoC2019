#pragma warning(disable: 5050)
import std.core;
import utils;
import intcode.comp;

constexpr auto FILEPATH = "./input.txt";
constexpr auto PART2_EXPECTED_VAL = 19690720;

void part1(const std::string& input)
{
	Intcode comp;
	comp.initializeMemory(input);
	comp.setVal(1, 12);
	comp.setVal(2, 2);
	comp.execute();

	std::cout << "Part1 answer: " << comp.getVal(0) << std::endl;
}

void part2(const std::string& input)
{
	Intcode comp;
	for (int noun = 0; noun <= 99; ++noun)
	{
		for (int verb = 0; verb <= 99; ++verb)
		{
			comp.initializeMemory(input);
			comp.setVal(1, noun);
			comp.setVal(2, verb);
			comp.execute();
			const int64_t result = comp.getVal(0);
			if (result == PART2_EXPECTED_VAL)
			{
				std::cout << "Part2 answer: " << 100 * noun + verb << std::endl;
				return;
			}
		}
	}

	std::cout << "Part2 answer not found!" << std::endl;
}

int main()
{
	const std::string input = readFileToString(FILEPATH);

	part1(input);
	part2(input);

	wait();
	
	return 0;
}