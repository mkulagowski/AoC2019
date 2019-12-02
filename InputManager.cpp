#include "InputManager.hpp"
#include <fstream>

namespace InputManager
{
	std::string readFileToString(std::filesystem::path path)
	{
		// Open the stream to 'lock' the file.
		std::ifstream f{ path };

		// Obtain the size of the file.
		const auto sz = std::filesystem::file_size(path);

		// Create a buffer.
		std::string result(sz, 0);

		// Read the whole file into the buffer.
		f.read(result.data(), sz);

		return std::move(result);
	}

	std::vector<char> readFileToCharBuffer(std::filesystem::path path)
	{
		// Open the stream to 'lock' the file.
		std::ifstream f{ path };

		// Obtain the size of the file.
		const auto sz = std::filesystem::file_size(path);

		// Create a buffer.
		std::vector<char> result;
		result.reserve(sz);

		// Read the whole file into the buffer.
		f.read(result.data(), sz);

		return std::move(result);
	}


} //InputManager