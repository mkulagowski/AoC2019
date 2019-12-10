#pragma once
#include "Day9.hpp"
#include "InputManager.hpp"
#include <array>
#include <sstream>
#include <iostream>


OpValues::OpValues(std::vector<int64_t>&  memRef, int64_t& op, int64_t& arg1, int64_t& arg2, int64_t& arg3, int& relativeIdx)
	: mMemRef(memRef)
	, mSize(3)
	, mRelativeBase(relativeIdx)
{
	std::ostringstream ss;
	ss << std::setw(5) << std::setfill('0') << op;
	std::string numStr = ss.str();
	for (int i = 0; i < mModes.size(); ++i)
		mModes[i] = static_cast<ParamMode>(numStr[mModes.size() - i - 1] - '0');

	mOp = static_cast<OpCode>(std::stoi(numStr.substr(3)));

	if (mOp == OpCode::RETURN || mOp == OpCode::SAVE || mOp == OpCode::ADJUST_RB)
		mSize = 1;
	else if (mOp == OpCode::JUMPF || mOp == OpCode::JUMPT)
		mSize = 2;

	std::array<int64_t*, 3> args{ &arg1, &arg2, &arg3 };
	for (int i = 0; i < mSize; ++i)
	{
		if (mModes[i] == ParamMode::Position)
			mRef[i] = &mMemRef[*args[i]];
		else if (mModes[i] == ParamMode::Immediate)
			mRef[i] = &*args[i];
		else if (mModes[i] == ParamMode::Relative)
			mRef[i] = &mMemRef[mRelativeBase + *args[i]];
	}
	mSize++;
}

int64_t OpValues::getVal(int i)
{
	return *mRef[i];
}

void OpValues::setVal(int i, int64_t val)
{
	*mRef[i] = val;
}

OpCode OpValues::getOp()
{
	return mOp;
}

int IntCodeComputer::eval(OpValues vals, int idx)
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
	case OpCode::ADJUST_RB:
		mRelativeBase += vals.getVal(0);
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
	size = size + (4 - size % 4);
	mMemory.resize(1000 * size);
	mRelativeBase = 0;
}

void IntCodeComputer::setMemoryByte(const size_t index, const int64_t value)
{
	if (index < mMemory.size())
		mMemory[index] = value;
}

int IntCodeComputer::execute()
{
	bool isRunning = true;
	size_t idx = 0;
	std::vector<int64_t> memoryCopy(mMemory.cbegin(), mMemory.cend());

	while (true)
	{
		if (static_cast<OpCode>(memoryCopy[idx]) == OpCode::END)
			break;

		OpValues vals(memoryCopy,
			memoryCopy[idx],
			memoryCopy[idx + 1],
			memoryCopy[idx + 2],
			memoryCopy[idx + 3],
			mRelativeBase
		);

		int opSize = eval(vals, idx);
		idx += opSize;
	}

	return memoryCopy[0];
}

