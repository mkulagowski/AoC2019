#pragma warning(disable: 5050)
export module intcode.cmd;

import intcode.comp;
import std.core;

export enum class OpCode : int64_t
{
	ADD = 1,
	MULT = 2,
};

export class Command
{
protected:
	Intcode* mComputer;

public:
	Command() {};

	virtual void init(const std::size_t memPtr) {};
	virtual const uint8_t getSize() const { return 1; };
	virtual bool execute() const { return false; };
};