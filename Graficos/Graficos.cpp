// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
#include "vertice.h"
#include "Shader.h"

using namespace std;

GLfloat red, green, blue;
vector <Vertice> triangulo;
GLuint posicionID;
GLuint vertexArrayID;

Shader *shader;

void actualizar()
{

}

void dibujar()
{


}



int main()
{

	//Declaración de venta
	GLFWwindow *window;
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW

	if (!glfwInit())
	{
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//INICIALIZAR VENTANA

	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);


	//verificar si se creó la ventana
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

	//verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGl: " << version << endl;

	red = green = blue = 0.0f;

	//Inicializar triangulo
	Vertice v1 = { vec3(-1.0f,-0.5f,0.0f), vec4(1.0f, 1.0f, 1.0f) };
	Vertice v2 = { vec3(0.0f,0.5f,0.0f), vec4(1.0f, 1.0f, 1.0f) };
	Vertice v3 = { vec3(1.0f,-0.5f,0.0f), vec4(1.0f, 1.0f, 1.0f) };

	
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);

	//Crear instancia del shader

	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window))
	{
			//ESTABLECER AREA DE RENDER
		glViewport(0, 0, ancho, alto);
		//ESTABLECER EL COLOR CON EL QUE SE VA A LIMPIAR LA PANTALLA



			glClearColor(red, green, blue, 1);
		


		//LIMPIAR PANTALLA
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		


		//rutina de dibujo
		actualizar();
		dibujar();

		//intercambio de buffers
		glfwSwapBuffers(window);

		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

