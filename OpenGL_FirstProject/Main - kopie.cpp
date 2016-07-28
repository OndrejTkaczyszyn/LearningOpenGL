#include <iostream>
#include <string>
#include <GL\glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#define COLOUR 

int main(int argc, char** argv) {

	const std::string& title = "Titulek okna";
	Display window(600, 400, title);
	Shader shader("./res/basicShader");
	unsigned int step = 0;


#ifdef COLOUR
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0),glm::vec4(0.5,0.5,1,1)),
						 Vertex(glm::vec3(0,0.5,0),glm::vec4(0.5,1,1,1)),
						 Vertex(glm::vec3(0.5,-0.5,0),glm::vec4(1,1,1,1)),};
#else
Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
Vertex(glm::vec3(0,0.5,0)),
Vertex(glm::vec3(0.5,-0.5,0)),
};
#endif
Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while(!window.IsClosed()) {

			window.Clear(0.4f, 0.1f, 0.6f);
			shader.Bind();
			mesh.Draw();
			window.Update();
		}
		

		return 0;
	}
