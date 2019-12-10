#pragma once
#include "Day2.hpp"
#include "InputManager.hpp"

class IntCodeComputer
{
private:
	std::vector<int> mMemory;

	bool eval(OpCode op, int& arg1, int& arg2, int& out)
	{
		switch (op)
		{
		case OpCode::ADD:
			out = arg1 + arg2;
			break;
		case OpCode::MULTIPLY:
			out = arg1 * arg2;
			break;
		case OpCode::END:
		default:
			return false;
		}

		return true;
	}

public:
	void intializeMemory(const std::string& code)
	{
		mMemory = InputManager::splitStringToInt<','>(code);
	}

	void setMemoryByte(const size_t index, const int value)
	{
		if (index < mMemory.size())
			mMemory[index] = value;
	}

	int execute()
	{
		bool isRunning = true;
		size_t idx = 0;
		std::vector<int> memoryCopy(mMemory.cbegin(), mMemory.cend());

		while (isRunning)
		{
			const OpCode op = static_cast<OpCode>(memoryCopy[idx]);
			if (op == OpCode::END)
				break;

			const int arg1Idx = memoryCopy[idx + 1];
			const int arg2Idx = memoryCopy[idx + 2];
			const int outIdx = memoryCopy[idx + 3];

			isRunning = eval(op, memoryCopy[arg1Idx], memoryCopy[arg2Idx], memoryCopy[outIdx]);
			idx += 4;
		}

		return memoryCopy[0];
	}
};

