#pragma warning(disable: 5050)
export module intcode.cmd;

import intcode.comp;
import std.core;

export enum class OpCode : int64_t
{
	ADD  = 1,
	MULT = 2,
	END  = 99
};

export class ICommand
{
public:
	using CommandResult = std::pair<bool, uint8_t>;
	virtual const CommandResult execute(const std::size_t memPos, Intcode* comp) const = 0;
};