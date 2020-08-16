#pragma warning(disable: 5050)
module intcode.comp;

import std.core;
import utils.split;
import intcode.cmd;
import intcode.creator;

void Intcode::initializeMemory(const std::string& memory)
{
	mMemory = splitStringToInt(memory, ',');
	mPos = 0;
}

const int64_t Intcode::getVal(const std::size_t src) const
{
	if (src < mMemory.size())
		return mMemory[src];

	return -1;
}

void Intcode::setVal(const std::size_t dst, const int64_t val)
{
	if (dst < mMemory.size())
		mMemory[dst] = val;
}

void Intcode::execute()
{
	bool isRunning = true;
	while (isRunning)
	{
		const int64_t currVal = mMemory[mPos++];
		std::unique_ptr<Command> cmd = createCommand(currVal, this);
		cmd->init(mPos);
		isRunning = cmd->execute();
		mPos += cmd->getSize();
	}
}