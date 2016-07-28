#pragma once
#include <string>
#include <GL\glew.h>

#ifndef SHADERS_IMPLEMENTED
#define SHADERS_IMPLEMENTED 

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	virtual ~Shader();
protected:
private:
	static const unsigned int NUM_SHADERS = 2; //can be enum - says which shader refers to which
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	GLuint myProgram; //program handle - unsigned int - used to refer to
	GLuint myShaders[NUM_SHADERS];//array of all shaders used in program
	//enum myShadersEnum : GLuint {vertex,fragment};
};
#endif

