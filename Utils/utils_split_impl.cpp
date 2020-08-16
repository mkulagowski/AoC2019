#pragma warning(disable: 5050)
module utils.split;

import std.core;

std::vector<int64_t> splitStringToInt(const std::string& str, const char& delim)
{
	std::vector<int64_t> results;
	results.reserve(str.size());
	size_t idx = 0;
	while (auto n = str.find(delim, idx))
	{
		if (n == std::string::npos)
		{
			results.push_back(std::stoi(str.substr(idx)));
			break;
		}

		results.push_back(std::stoll(str.substr(idx, n - idx)));
		idx = n + 1;
	}
	return std::move(results);
}

std::vector<std::string> splitString(const std::string& str, const char& delim)
{
	std::vector<std::string> results;
	results.reserve(str.size());
	size_t idx = 0;
	while (auto n = str.find(delim, idx))
	{
		if (n == std::string::npos)
		{
			results.push_back(str.substr(idx));
			break;
		}

		results.push_back(str.substr(idx, n - idx));
		idx = n + 1;
	}
	return std::move(results);
}