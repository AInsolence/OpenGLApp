#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

class Shader
{
public:
	Shader(const char* VertexShaderPath,
			const char* FragmentShaderPath);
	~Shader();

	void CreateFromFile(const char* VertexShaderPath,
						const char* FragmentShaderPath);

	GLint GetProjectionLocation() const;
	GLint GetModelLocation() const;

	void Use();
	void Clear();

private:
	GLuint Id;
	GLint UniformProjection, UniformModel;

	void CompileShaders(const char* VertexShaderCode,
						const char* FragmentShaderCode);

	/*  1) Created shader from shader source code
		2) Compile it and check compilation status
		3) Attach it to shader program				*/
	void AddShader(GLuint ShaderProgramId, const char* ShaderCode, GLenum ShaderType);

	std::string ReadFile(const char* FilePath);
};

