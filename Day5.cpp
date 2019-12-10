#pragma once
#include "Day5.hpp"
#include "InputManager.hpp"
#include <array>
#include <sstream>
#include <iostream>


OpValues::OpValues(std::vector<int>&  memRef, int& op, int& arg1, int& arg2, int& arg3)
	: mMemRef(memRef)
	, mSize(3)
{
	std::ostringstream ss;
	ss << std::setw(5) << std::setfill('0') << op;
	std::string numStr = ss.str();
	for (int i = 0; i < mModes.size(); ++i)
		mModes[i] = static_cast<ParamMode>(numStr[mModes.size() - i - 1] == '1');

	mOp = static_cast<OpCode>(std::stoi(numStr.substr(3)));

	if (mOp == OpCode::RETURN || mOp == OpCode::SAVE)
		mSize = 1;
	else if (mOp == OpCode::JUMPF || mOp == OpCode::JUMPT)
		mSize = 2;

	std::array<int*, 3> args{ &arg1, &arg2, &arg3 };
	for (int i = 0; i < mSize; ++i)
	{
		if (mModes[i] == ParamMode::Position)
			mRef[i] = &mMemRef[*args[i]];
		else if (mModes[i] == ParamMode::Immediate)
			mVal[i] = *args[i];
	}
	mSize++;
}

int OpValues::getVal(int i)
{
	if (mModes[i] == ParamMode::Position)
		return *mRef[i];
	else if (mModes[i] == ParamMode::Immediate)
		return mVal[i];
	else
		return -1;
}

void OpValues::setVal(int i, int val)
{
	if (mModes[i] == ParamMode::Position)
		*mRef[i] = val;
	else if (mModes[i] == ParamMode::Immediate)
		mVal[i] = val;
}

OpCode OpValues::getOp()
{
	return mOp;
}

unsigned char IntCodeComputer::eval(OpValues vals, int idx)
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
		std::cout << "GIVE INPUT: ";
		int input;
		std::cin >> input;
		vals.setVal(0, input);
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
		std::cout << "RET VALUE: " << vals.getVal(0) << std::endl;
		break;
	case OpCode::END:
	default:
		return 0;
	}
	return vals.mSize;
}

void IntCodeComputer::intializeMemory(const std::string& code)
{
	mMemory = InputManager::splitStringToInt<','>(code);
	size_t size = mMemory.size();
	mMemory.resize(size + (4 - size % 4));
}

void IntCodeComputer::setMemoryByte(const size_t index, const int value)
{
	if (index < mMemory.size())
		mMemory[index] = value;
}

int IntCodeComputer::execute()
{
	bool isRunning = true;
	size_t idx = 0;
	std::vector<int> memoryCopy(mMemory.cbegin(), mMemory.cend());

	while (true)
	{
		if (static_cast<OpCode>(memoryCopy[idx]) == OpCode::END)
			break;

		OpValues vals(memoryCopy,
			memoryCopy[idx],
			memoryCopy[idx + 1],
			memoryCopy[idx + 2],
			memoryCopy[idx + 3]
		);

		int opSize = eval(vals, idx);
		idx += opSize;
	}

	return memoryCopy[0];
}

