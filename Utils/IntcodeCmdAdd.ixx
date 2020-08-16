#pragma warning(disable: 5050)
export module intcode.cmd.add;

import intcode.cmd;
import std.core;

export class AddCommand : public Command
{
private:
	int64_t mVal1, mVal2, mDst;

public:
	AddCommand(Intcode* comp)
		: mVal1(0)
		, mVal2(0)
		, mDst(0)
	{
		mComputer = comp;
	}

	void init(const std::size_t memPos) override
	{
		const int64_t idx1 = mComputer->getVal(memPos);
		const int64_t idx2 = mComputer->getVal(memPos + 1);
		mVal1 = mComputer->getVal(idx1);
		mVal2 = mComputer->getVal(idx2);
		mDst = mComputer->getVal(memPos + 2);
	}

	const uint8_t getSize() const override
	{
		return 3;
	}

	bool execute() const override
	{
		mComputer->setVal(mDst, mVal1 + mVal2);
		return true;
	}
};
