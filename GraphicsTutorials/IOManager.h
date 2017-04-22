#pragma once
#include <vector>

class IOManager{
public:
	static bool readFileToBuffer(string filepath, 
								vector<char>& buffer);
};