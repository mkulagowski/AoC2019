#pragma once
#include <vector>
#include <string>
#include <array>
#include <cstdint>

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
	ADJUST_RB = 9,
	END			= 99,
	UNKNOWN		= 0,
};

enum class ParamMode
{
	Position = 0,
	Immediate = 1,
	Relative = 2,
};

class OpValues
{
public:
	std::array<int64_t*, 3> mRef;
	std::array<ParamMode, 3> mModes;
	std::vector<int64_t>& mMemRef;
	OpCode mOp;

	OpValues(std::vector<int64_t>& memRef, int64_t& op, int64_t& arg1, int64_t& arg2, int64_t& arg3, int& relativeIdx);

	int64_t getVal(int i);
	void setVal(int i, int64_t val);
	OpCode getOp();
	int mSize;
	int& mRelativeBase;
};

class IntCodeComputer
{
public:
	void intializeMemory(const std::string& code);
	void setMemoryByte(const size_t index, const int64_t value);
	int execute();

protected:
	int mRelativeBase;
	std::vector<int64_t> mMemory;
	int eval(OpValues vals, int idx);
};