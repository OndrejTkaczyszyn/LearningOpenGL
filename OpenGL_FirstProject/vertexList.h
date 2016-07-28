#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "mesh.h"

//TODO: Dynamic memory allocation

class vertexList
{
public:
	vertexList(glm::vec3 points[], glm::vec3 colours[]);
	vertexList();
	vertexList(Vertex *vertices);
	//TODO - implement
	void Push(Vertex vert);
	void Push(glm::vec3 point, glm::vec3 colour);
	void Pop();
	void SetBatchSize(unsigned int newBatchSize);
	~vertexList();
	unsigned int getLength();

	glm::vec3* verts;
	glm::vec3* cols;
private:
	void createSpace();
	void removeSpace();
	unsigned int batch_size = 6;
	unsigned int length;
	unsigned int usedLength = 0;


};

