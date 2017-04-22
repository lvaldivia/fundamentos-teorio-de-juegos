#pragma once

#include <string>

using namespace std;

class GLSProgram{

public:
	GLSProgram();
	~GLSProgram();

	void compilaShader(const string& vertexShaderFilepath, 
						const string& fragmentShaderFilePath);

	void linkShaders();

	void addAtribute(const string atribute);

	void use();

	void unuse();

private:
	unsigned int _programID;
	unsigned int _vertexShaderID;
	unsigned int _fragmentShaderID;
	int _numAtributes;
}