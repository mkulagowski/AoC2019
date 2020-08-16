#pragma warning(disable: 5050)
export module intcode.creator;

import intcode.cmd;
import std.core;

export std::unique_ptr<Command> createCommand(const int64_t opCode, Intcode* com);