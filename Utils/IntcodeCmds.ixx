#pragma warning(disable: 5050)
export module intcode.cmdlist;

import intcode.cmd;
import std.core;

export class AddCommand : public ICommand
{
public:
	AddCommand() = default;
	const CommandResult execute(const std::size_t memPos, Intcode* comp) const override
	{
		const int64_t val1 = comp->getVal(memPos);
		const int64_t val2 = comp->getVal(memPos + 1);
		const size_t dst = comp->getVal(memPos + 2);

		comp->setVal(dst, comp->getVal(val1) + comp->getVal(val2));
		return {true, 3};
	}
};

export class MultCommand : public ICommand
{
public:
	MultCommand() = default;
	const CommandResult execute(const std::size_t memPos, Intcode* comp) const override
	{
		const int64_t val1 = comp->getVal(memPos);
		const int64_t val2 = comp->getVal(memPos + 1);
		const size_t dst = comp->getVal(memPos + 2);

		comp->setVal(dst, comp->getVal(val1) * comp->getVal(val2));
		return {true, 3};
	}
};

export class EndCommand : public ICommand
{
public:
	EndCommand() = default;
	const CommandResult execute(const std::size_t memPos, Intcode* comp) const override
	{
		return {false, 1};
	}
};
