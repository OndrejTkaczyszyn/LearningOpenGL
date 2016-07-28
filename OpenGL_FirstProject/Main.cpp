#include <iostream>
#include <string>
#include <GL\glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "vertexList.h"
#define COLOUR 

int main(int argc, char** argv) {
	//BEGIN vertexList debug
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0),glm::vec3(0.5,0.5,1.0)),
		Vertex(glm::vec3(0,0.5,0),glm::vec3(0.5,1.0,1.0)),
		Vertex(glm::vec3(0.5,-0.5,0),glm::vec3(1.0,1.0,1.0)), };
	std::cout << sizeof(vertices) << std::endl;

	vertexList myVertexList(vertices);

	std::cout << myVertexList.getLength() << std::endl;
	//myVertexList.Push();
	for (unsigned int i = 0; i < myVertexList.getLength(); i++) {
		std::cout << "x:" << myVertexList.verts[i].x << ", y:" << myVertexList.verts[i].y << ", z:" << myVertexList.verts[i].z << ", r:" << myVertexList.cols[i].r << ", g:" << myVertexList.cols[i].g << ", b:" << myVertexList.cols[i].b << std::endl;
	}
	//END vertexList debug

	/*const std::string& title = "Titulek okna";
	Display window(600, 400, title);
	Shader shader("./res/basicShader");
	unsigned int step = 0;



	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0),glm::vec3(0.5,0.5,1.0)),
						 Vertex(glm::vec3(0,0.5,0),glm::vec3(0.5,1.0,1.0)),
						 Vertex(glm::vec3(0.5,-0.5,0),glm::vec3(1.0,1.0,1.0)),};
Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while(!window.IsClosed()) {

			window.Clear(0.4f, 0.1f, 0.6f);
			shader.Bind();
			mesh.Draw();
			window.Update();
		}
		
*/
		return 0;
	}
