#pragma warning(disable: 5050)
export module intcode.comp;

import std.core;

export class Intcode
{
private:
	std::vector<int64_t> mMemory;
	std::size_t mPos;

public:
	Intcode() {};

	void initializeMemory(const std::string& memory);
	const int64_t getVal(const std::size_t src) const;
	void setVal(const std::size_t dst, const int64_t val);

	void execute();
};