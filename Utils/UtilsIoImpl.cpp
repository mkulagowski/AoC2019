#pragma warning(disable: 5050)
module utils.io;

import std.core;
import utils.fs;

std::string readFileToString(const std::string& pathstr)
{
	// Open the stream to 'lock' the file.
	std::ifstream f(pathstr);

	// Obtain the size of the file.
	const auto sz = getFileSize(pathstr);

	// Create a buffer.
	std::string result(sz, 0);

	// Read the whole file into the buffer.
	f.read(result.data(), sz);

	return std::move(result);
}

std::vector<char> readFileToCharBuffer(const std::string& pathstr)
{
	// Open the stream to 'lock' the file.
	std::ifstream f(pathstr);

	// Obtain the size of the file.
	const auto sz = getFileSize(pathstr);

	// Create a buffer.
	std::vector<char> result;
	result.reserve(sz);

	// Read the whole file into the buffer.
	f.read(result.data(), sz);

	return std::move(result);
}