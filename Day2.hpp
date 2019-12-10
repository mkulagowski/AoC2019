#pragma once
#include <vector>
#include <string>

enum class OpCode : unsigned char
{
	ADD = 1,
	MULTIPLY = 2,
	END = 99,
	UNKNOWN = 0,
};

class IntCodeComputer
{
public:
	void intializeMemory(const std::string& code);
	void setMemoryByte(const size_t index, const int value);
	int execute();

private:
	std::vector<int> mMemory;

	bool eval(OpCode op, int& arg1, int& arg2, int& out);
};

