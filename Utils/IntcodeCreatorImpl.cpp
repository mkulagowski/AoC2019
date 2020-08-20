#pragma warning(disable: 5050)
module intcode.creator;

import std.core;
import intcode.comp;
import intcode.cmd;
import intcode.cmdlist;

std::unique_ptr<ICommand> createCommand(const int64_t opCode)
{
	const OpCode op = static_cast<OpCode>(opCode);
	switch (op)
	{
	case OpCode::ADD:
		return std::make_unique<AddCommand>();
	case OpCode::MULT:
		return std::make_unique<MultCommand>();
	case OpCode::END:
		return std::make_unique<EndCommand>();
	};

	return std::make_unique<EndCommand>();
}