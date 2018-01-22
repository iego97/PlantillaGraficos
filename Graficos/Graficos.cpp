// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>

using namespace std;

void actualizar()
{

}

void dibujar()
{

}



int main()
{

	//Declaraci�n de venta
	GLFWwindow *window;
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicializaci�n de GLFW

	if (!glfwInit())
	{
		//Si no se inici� bien, terminar la ejecuci�n
		exit(EXIT_FAILURE);
	}

	//INICIALIZAR VENTANA

	window = glfwCreateWindow(ancho, alto, "Gr�ficos", NULL, NULL);


	//verificar si se cre� la ventana
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);


	//se trae las funciones de OpenGL Moderno
	glewExperimental = true;

	//INICIALIZAR GLEW

	GLenum glewError = glewInit();

	//verificar que GLEW se inicializ� bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGl: " << version << endl;

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window))
	{
			//ESTABLECER AREA DE RENDER
		glViewport(0, 0, ancho, alto);
		//ESTABLECER EL COLOR CON EL QUE SE VA A LIMPIAR LA PANTALLA
		glClearColor(1, 0.8, 0, 1);
		//LIMPIAR PANTALLA
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//intercambio de buffers
		glfwSwapBuffers(window);

		//Buscar se�ales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

