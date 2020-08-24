#pragma warning(disable: 5050)
import std.core;
import utils;
import day3;

constexpr auto FILEPATH = "./input.txt";

void part1(const std::string& input)
{
	const auto wires = splitString(input, '\n');
	int minDistance = std::numeric_limits<int>::max();
	Point startA, startB;
	for (const auto [dirA, distA] : splitStringToCharInt(wires[0], ','))
	{
		const Segment wireA = {startA, calcWireEnd(startA, dirA, distA)};
		startB = {0, 0};
		for (const auto [dirB, distB] : splitStringToCharInt(wires[1], ','))
		{
			const Segment wireB = {startB, calcWireEnd(startB, dirB, distB)};
			if (canIntersect(dirA, dirB))
			{
				const auto [horizontalWire, verticalWire] = sortWires(dirA, wireA, wireB);
				if (doIntersect(horizontalWire, verticalWire))
				{
					const Point intersection(verticalWire.first.x, horizontalWire.first.y);
					const int distance = abs(intersection.x) + abs(intersection.y);
					if (distance > 0 && distance < minDistance)
						minDistance = distance;
				}
			}
			startB = wireB.second;
		}
		startA = wireA.second;
	}

	std::cout << "Part1 answer: " << minDistance << std::endl;
}

void part2(const std::string& input)
{
	const auto wires = splitString(input, '\n');
	int minDistance = std::numeric_limits<int>::max();
	Point startA, startB;
	int stepsA = 0;
	for (const auto [dirA, distA] : splitStringToCharInt(wires[0], ','))
	{
		const Segment wireA = {startA, calcWireEnd(startA, dirA, distA)};
		startB = {0, 0};
		int stepsB = 0;
		for (const auto [dirB, distB] : splitStringToCharInt(wires[1], ','))
		{
			const Segment wireB = {startB, calcWireEnd(startB, dirB, distB)};
			if (canIntersect(dirA, dirB))
			{
				const auto [horizontalWire, verticalWire] = sortWires(dirA, wireA, wireB);
				if (doIntersect(horizontalWire, verticalWire))
				{
					const Point intersection(verticalWire.first.x, horizontalWire.first.y);
					const int horizontalSteps = abs(intersection.x - horizontalWire.first.x);
					const int verticalSteps = abs(intersection.y - verticalWire.first.y);
					const int distance = stepsA + stepsB + horizontalSteps + verticalSteps;
					if (distance > 0 && distance < minDistance)
						minDistance = distance;
				}
			}
			startB = wireB.second;
			stepsB += distB;
		}
		startA = wireA.second;
		stepsA += distA;
	}

	std::cout << "Part2 answer: " << minDistance << std::endl;
}

int main()
{
	const std::string input = readFileToString(FILEPATH);
	
	part1(input);
	part2(input);

	wait();
	
	return 0;
}