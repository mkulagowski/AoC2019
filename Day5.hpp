#pragma once
#include <vector>
#include <string>
#include <array>

enum class OpCode : unsigned char
{
	ADD = 1,
	MULTIPLY = 2,
	SAVE = 3,
	RETURN = 4,
	JUMPT = 5,
	JUMPF = 6,
	LT = 7,
	EQ = 8,
	END			= 99,
	UNKNOWN		= 0,
};

enum class ParamMode
{
	Position = 0,
	Immediate = 1,
};

class OpValues
{
public:
	std::array<int*, 3> mRef;
	std::array<int, 3>  mVal;
	std::array<ParamMode, 3> mModes;
	std::vector<int>& mMemRef;
	OpCode mOp;

	OpValues(std::vector<int>& memRef, int& op, int& arg1, int& arg2, int& arg3);

	int getVal(int i);
	void setVal(int i, int val);
	OpCode getOp();
	int mSize;
};

class IntCodeComputer
{
public:
	void intializeMemory(const std::string& code);
	void setMemoryByte(const size_t index, const int value);
	int execute();

protected:
	std::vector<int> mMemory;
	unsigned char eval(OpValues vals, int idx);
};