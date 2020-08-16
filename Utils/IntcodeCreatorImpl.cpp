#pragma warning(disable: 5050)
module intcode.creator;

import std.core;
import intcode.comp;
import intcode.cmd;
import intcode.cmd.add;
import intcode.cmd.mult;

std::unique_ptr<Command> createCommand(const int64_t opCode, Intcode* comp)
{
	const OpCode op = static_cast<OpCode>(opCode);
	switch (op)
	{
	case OpCode::ADD:
		return std::make_unique<AddCommand>(comp);
	case OpCode::MULT:
		return std::make_unique<MultCommand>(comp);
	};

	return std::make_unique<Command>();
}