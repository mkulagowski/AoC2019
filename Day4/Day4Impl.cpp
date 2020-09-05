#pragma warning(disable: 5050)
module day4;

import std.core;

const bool isValid(const int password)
{
	const std::string numStr = std::to_string(password);
	bool hasDouble = false;
	char lastDig = 0;
	char lastCount = 0;

	for (const char& c : numStr)
	{
		if (c == lastDig)
		{
			lastCount++;
		}
		else
		{
			if (c < lastDig)
				return false;

			lastDig = c;
			if (lastCount == 2)
				hasDouble = true;
			lastCount = 1;
		}
	}

	if (lastCount == 2)
		hasDouble = true;

	return hasDouble;
}

const bool isValidSimple(const int password)
{
	const std::string numStr = std::to_string(password);
	bool hasRepeated = false;

	for (int i = 0; i < numStr.size() - 1; ++i)
	{
		const char digit1 = numStr[i];
		const char digit2 = numStr[i + 1];
		if (digit2 < digit1)
			return false;
		if (digit1 == digit2)
			hasRepeated = true;
	}

	return hasRepeated;
}