#pragma once
#ifndef MESH_IMPLEMENTED
#define MESH_IMPLEMENTED

#include <glm\glm.hpp>
#include <GL\glew.h>

struct Vertex {

public:
	Vertex(const glm::vec3& pos, const glm::vec3& col) {
		this->pos = pos;
		this->col = col;
	}
	Vertex(const glm::vec3& pos) {
		this->pos = pos;
		this->col = glm::vec3(1.0,1.0,1.0);
	}
	glm::vec3 pos;
	glm::vec3 col;
protected:
private:

};
class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVerts);
	~Mesh();
	void Draw();
protected:
private:
	Mesh(const Mesh& other) {};
	void operator=(const Mesh& other) {};
	enum {
		POSITION_VB,

		NUM_BUFFERS
	};
	GLuint myVertexArrayObject;//current vertex
	GLuint myVertexArrayBuffers[NUM_BUFFERS];//array of vertices
	GLuint myColourArrayBuffers[NUM_BUFFERS];//array of vertices
	GLuint myColourArrayObject;//array of vertices
	unsigned int myDrawCount; //how much to draw

};
#endif MESH_IMPLEMENTED

