#pragma once
#include <filesystem>
#include <string>

namespace InputManager
{
std::string readFileToString(std::filesystem::path path);
std::vector<char> readFileToCharBuffer(std::filesystem::path path);
template<char delim>
std::vector<int> splitStringToInt(const std::string& str)
{
	std::vector<int> results;
	results.reserve(str.size());
	size_t idx = 0;
	while (auto n = str.find(delim, idx))
	{
		if (n == std::string::npos)
			break;

		results.push_back(std::stoi(str.substr(idx, n - idx)));
		idx = n + 1;
	}
	return std::move(results);
}
} //InputManager