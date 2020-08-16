#pragma warning(disable: 5050)
export module utils.fs;

import std.core;
import std.filesystem;

// WORKAROUND: using ifstream and filesystem in a single file crashes compiler
export const auto getFileSize(const std::string& pathstr)
{
	std::filesystem::path inpath(pathstr);
	return std::filesystem::file_size(inpath);
}