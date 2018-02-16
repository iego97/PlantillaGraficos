#pragma once

#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
#include <fstream>

using namespace std;

class Shader {
	public:
		GLuint getId(); //Obtener el ID del shader
		Shader(const char * rutaVertex, const char * rutaFragment);
			void enlazarShader();
		void desenlazarShader();
	private:
		GLuint shaderID;
		void verificarCompilacion(GLuint id);
		void verificarVinculacion(GLuint id);

};