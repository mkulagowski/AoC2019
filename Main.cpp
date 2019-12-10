#include "InputManager.hpp"
//#include "Day1.hpp"
#include <iostream>
#include <memory>
#include "Day9.hpp"

constexpr auto FILEPATH = "./input.txt";

template <typename T>
std::vector<std::unique_ptr<std::vector<T>>> Permutation(std::vector<T> v)
{
	std::vector<std::unique_ptr<std::vector<T>>> res;
	std::sort(v.begin(), v.end());
	do {
		//std::vector<T> subRes(v.begin(), v.end());
		std::unique_ptr<std::vector<T>> ss = std::make_unique<std::vector<T>>(v.begin(), v.end());
		res.push_back(std::move(ss));
	} while (std::next_permutation(v.begin(), v.end()));

	return res;
}

int main()
{
	std::string input = InputManager::readFileToString(FILEPATH);
	/*
	std::vector<int> phaseSetting{ 9,7,8,5,6 };
	std::vector<AmplifierCircuit> acs(5);
	int biggestOut = 0;

	for (const auto& setting : Permutation(phaseSetting))
	{
		for (auto& ac : acs)
			ac.intializeMemory(input);
		int output = 0;
		int idx = 0;
		bool isRunning = true;
		bool isInitialLoop = true;
		int bout = 0;
		while (isRunning)
		{
			for (const int& phase : *setting.get())
			{
				std::array<int, 2> customInput{ phase, output };
				if (!isInitialLoop)
					customInput[0] = customInput[1];

				acs[idx].setCustomInput(customInput);
				output = acs[idx].execute();
				if (output == -1)
				{
					isRunning = false;
					break;
				}
				if (idx > 3)
					idx = 0;
				else
					idx++;
				if (output > bout)
					bout = output;
			}
			isInitialLoop = false;
		}
		std::cout << "FOR SETTING { ";
		std::copy(setting->begin(), setting->end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "} GOT OUTPUT = " << bout << std::endl;
		if (bout > biggestOut)
			biggestOut = bout;
	}
	std::cout << "Biggest output: " << biggestOut << std::endl;
	*/
	/*
	for (const auto& setting : Permutation(phaseSetting))
	{
		int output = 0;
		for (const int& phase : *setting.get())
		{
			std::array<int, 2> customInput{ phase, output };
			ac.setCustomInput(customInput);
			output = ac.execute();
		}
		std::cout << "FOR SETTING { ";
		std::copy(setting->begin(), setting->end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "} GOT OUTPUT = " << output << std::endl;
		if (output > biggestOut)
			biggestOut = output;
	}
	std::cout << "Biggest output: " << biggestOut << std::endl;
	*/

	
	IntCodeComputer comp;
	comp.intializeMemory(input);
	//comp.setMemoryByte(1, 12);
	//comp.setMemoryByte(2, 2);
	int result = comp.execute();
	std::cout << "Res: " << result << std::endl;

	
	/*
	const int output = 19690720;
	for (int n = 0; n <= 99; ++n)
	{
		for (int v = 0; v <= 99; ++v)
		{
			comp.setMemoryByte(1, n);
			comp.setMemoryByte(2, v);
			int subresult = comp.execute();
			if (subresult == output)
			{
				std::cout << "Res: " << 100 * n + v;
				break;
			}
		}
	}
	std::cout << std::endl;
	*/
	/*
	std::vector<int> inputTable = InputManager::splitStringToInt<'\n'>(input);
	std::cout << input << std::endl;
	int64_t fuelNeeded = 0;
	for (const auto& i : inputTable)
	{
		int fuel = calcFuel(i);
		if (fuel > 0)
			fuelNeeded += fuel;
	}
	std::cout << "Total fuel: " << fuelNeeded;
	*/
}