#include "IOManager.h"
#include <fstream>

using namespace std;


bool IOManager::readFileToBuffer(string filepath, 
								vector<char>& buffer){
	ifstream file(filepath, ios::binary);

	if(file.fail())	{
		perror(filepath.c_str());
		return false;
	}

	file.seekg(0,ios::end);
	int filesize = file.tellg();

	file.seekg(0,ios::beg);

	filesize -=  file.tellg();

	buffer.resize(filesize);

	file.seekg(0, ios::beg);
	file.read((char *)&buffer,filesize);
	file.close();

	return true;




}