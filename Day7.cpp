#pragma once
#include "Day7.hpp"
#include "InputManager.hpp"
#include <array>
#include <sstream>
#include <iostream>

int AmplifierCircuit::eval(OpValues vals, int idx)
{
	switch (vals.getOp())
	{
	case OpCode::ADD:
		vals.setVal(2, vals.getVal(0) + vals.getVal(1));
		break;;
	case OpCode::MULTIPLY:
		vals.setVal(2, vals.getVal(0) * vals.getVal(1));
		break;
	case OpCode::SAVE:
	{
		//std::cout << "INPUT: ";
		int input = mCustomInput[mInputIdx];
		mInputIdx++;
		//std::cout << input << std::endl;
		vals.setVal(0, input);
	}
		break;
	case OpCode::JUMPT:
		if (vals.getVal(0) != 0)
			vals.mSize = vals.getVal(1) - idx;
		break;
	case OpCode::JUMPF:
		if (vals.getVal(0) == 0)
			vals.mSize = vals.getVal(1) - idx;
		break;
	case OpCode::LT:
		if (vals.getVal(0) < vals.getVal(1))
			vals.setVal(2, 1);
		else
			vals.setVal(2, 0);
		break;
	case OpCode::EQ:
		if (vals.getVal(0) == vals.getVal(1))
			vals.setVal(2, 1);
		else
			vals.setVal(2, 0);
		break;
	case OpCode::RETURN:
		//std::cout << "RET VALUE: " << vals.getVal(0) << std::endl;
		mOutput = vals.getVal(0);
		mOutputReady = true;
		break;
	case OpCode::END:
	default:
		return 0;
	}
	return vals.mSize;
}

void AmplifierCircuit::setCustomInput(std::array<int, 2>& customInput)
{
	mCustomInput = customInput;
	mInputIdx = 0;
	mOutputReady = false;
}

void AmplifierCircuit::intializeMemory(const std::string& code)
{
	IntCodeComputer::intializeMemory(code);
	mIdx = 0;
}

int AmplifierCircuit::execute()
{
	// TODO: when OUTPUT is given, return it and suspend the program - make memory & index persistent
	mOutputReady = false;
	//size_t idx = 0;
	//std::vector<int> mMemory(mMemory.cbegin(), mMemory.cend());

	while (!mOutputReady)
	{
		if (static_cast<OpCode>(mMemory[mIdx]) == OpCode::END)
		{
			mOutput = -1;
			break;
		}

		OpValues vals(mMemory,
			mMemory[mIdx],
			mMemory[mIdx + 1],
			mMemory[mIdx + 2],
			mMemory[mIdx + 3]
		);

		int opSize = eval(vals, mIdx);
		mIdx += opSize;
	}

	return mOutput;
}

