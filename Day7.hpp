#pragma once
#include "Day5.hpp"

class AmplifierCircuit : public IntCodeComputer
{
public:
	void setCustomInput(std::array<int, 2>& customInput);
	int execute();
	void intializeMemory(const std::string& code);

protected:
	std::array<int, 2> mCustomInput;
	unsigned char mInputIdx;
	size_t mIdx = 0;
	int mOutput;
	bool mOutputReady;
	int eval(OpValues vals, int idx);
};