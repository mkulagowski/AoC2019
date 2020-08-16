#pragma warning(disable: 5050)
module day1;

import std.core;

const int64_t calcFuel(const int64_t mass)
{
	return (mass / 3) - 2;
}