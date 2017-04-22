#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class IOManager{
public:
	static bool readFileToBuffer(string filepath, 
								vector<char>& buffer);
};