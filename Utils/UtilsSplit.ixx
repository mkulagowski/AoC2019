#pragma warning(disable: 5050)
export module utils.split;

import std.core;

export std::vector<int64_t> splitStringToInt(const std::string& str, const char& delim);
export std::vector<std::string> splitString(const std::string& str, const char& delim);