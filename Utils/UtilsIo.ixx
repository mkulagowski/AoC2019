#pragma warning(disable: 5050)
export module utils.io;

import std.core;

export std::string readFileToString(const std::string& pathstr);
export std::vector<char> readFileToCharBuffer(const std::string& pathstr);