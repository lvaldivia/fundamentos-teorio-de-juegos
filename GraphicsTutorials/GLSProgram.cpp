#include "GLSProgram.h"

using namespace std;


GLSProgram::GLSProgram() : _programID(0), _vertexShaderID(0) , 
						_fragmentShaderID(0) ,
						_numAtributes(0)
{

}

void GLSProgram:use(){

}

void GLSProgram::unuse(){

}

void GLSProgram::compilaShader(const string& vertexShaderFilepath, 
						const string& fragmentShaderFilePath){

}

void GLSProgram:linkShaders(){

}

GLSProgram:~GLSProgram(){
	
}