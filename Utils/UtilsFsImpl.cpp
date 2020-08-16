#pragma warning(disable: 5050)
module utils.fs;

import std.core;
import std.filesystem;

// WORKAROUND: using ifstream and filesystem in a single file crashes compiler
const std::uintmax_t getFileSize(const std::string& pathstr)
{
	const std::filesystem::path inpath(pathstr);
	return std::filesystem::file_size(inpath);
}