#pragma warning(disable: 5050)
export module utils;

export import utils.io;
export import utils.split;

import std.core;

export void inline wait() { int n; std::cin >> n; }