#include "shader.h"
#include <fstream>
#include <iostream>
#define DEBUG
#define COLOUR

static std::string LoadShader(const std::string& fileName);
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName) {
	myProgram = glCreateProgram();
	myShaders[0] = CreateShader(LoadShader(fileName + ".glvs"), GL_VERTEX_SHADER);
	myShaders[1] = CreateShader(LoadShader(fileName + ".glfs"), GL_FRAGMENT_SHADER);
	//myShadersEnum{ vertex = CreateShader(LoadShader(fileName + ".glvs"), GL_VERTEX_SHADER), fragment = CreateShader(LoadShader(fileName + ".glfs"), GL_FRAGMENT_SHADER) };

	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(myProgram, myShaders[i]);
	}

	glBindAttribLocation(myProgram, 0, "position"); // binds variables to inidces
#ifdef COLOUR
	glBindAttribLocation(myProgram, 1, "colour");
#endif
	glLinkProgram(myProgram);
	//CheckShaderError(myShaders[0], GL_VALIDATE_STATUS, false, "Error: vertex shader is shit.");
	//CheckShaderError(myShaders[1], GL_VALIDATE_STATUS, false, "Error: fragment shader is shit.");
	CheckShaderError(myProgram, GL_LINK_STATUS, true, "Error: program linking failed.");

	glValidateProgram(myProgram);
	CheckShaderError(myProgram, GL_VALIDATE_STATUS, true, "Error: program invalid after linking.");
}

void Shader::Bind() {//sets shader as currently used shader
	glUseProgram(myProgram);
}

Shader::~Shader(){
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(myProgram, myShaders[i]);
		glDeleteShader(myShaders[i]);
	}
	glDeleteProgram(myProgram);
}

static std::string LoadShader(const std::string& fileName) {//load textfile from harddrive
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {//if file didn't open
#ifdef DEBUG
		std::cerr << "Unable to load shader: " << fileName << std::endl;
#endif
	}
	return output;//return the loaded file;
}

static GLuint CreateShader(const std::string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0) {
#ifdef DEBUG
		std::cerr << "Error: Shader creation failed!" << std::endl;
#endif
		const GLchar* shaderSourceStrings[1];
		GLint shaderSourceStringLengths[1];
		shaderSourceStrings[0] = text.c_str();
		shaderSourceStringLengths[0] = text.length();

		glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
		glCompileShader(shader);
		CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shaser compilation failed.");

		return shader;
	}
}
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		sizeof(GLuint);
		std::cerr << errorMessage << ": '" << error << "' " << std::endl;
	}
}
