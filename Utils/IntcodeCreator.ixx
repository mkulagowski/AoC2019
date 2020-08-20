#pragma warning(disable: 5050)
export module intcode.creator;

import intcode.cmd;
import std.core;

export std::unique_ptr<ICommand> createCommand(const int64_t opCode);