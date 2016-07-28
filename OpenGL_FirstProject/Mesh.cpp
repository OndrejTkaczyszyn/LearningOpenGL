#include "Mesh.h"

#include "vertexList.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVerts)
{
	myDrawCount = numVerts;
	vertexList* myList = new vertexList(vertices);//create vertex list from arr of vertices
	glGenVertexArrays(1, &myVertexArrayObject);
	glBindVertexArray(myVertexArrayObject);//bind it - any operation on vertices will affect this one
	glGenBuffers(NUM_BUFFERS, myVertexArrayBuffers); //get buffers to write to
	glBindBuffer(GL_ARRAY_BUFFER, myVertexArrayBuffers[POSITION_VB]);//bind buffer, first argument tells OpenGL to treat buffer as an array
	glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(glm::vec3), myList->cols, GL_STATIC_DRAW); // put data in buffer 	glBufferData(target, size, pointerdata, usage); usage - where to store in memory (static - not going to change => place easy read from, not necessarily to write to)


	glGenBuffers(NUM_BUFFERS, myVertexArrayBuffers); //get buffers to write to
	glBindBuffer(GL_ARRAY_BUFFER, myVertexArrayBuffers[POSITION_VB]);//bind buffer, first argument tells OpenGL to treat buffer as an array
	glBufferData(GL_ARRAY_BUFFER, myList->getLength() * sizeof(glm::vec3), myList->verts, GL_STATIC_DRAW); // POSSIBLE ERROR at myList->verts,->getLength put data in buffer 	glBufferData(target, size, pointerdata, usage); usage - where to store in memory (static - not going to change => place easy read from, not necessarily to write to)
	glBindVertexArray(0);//unbind

	glEnableVertexAttribArray(0); // attribute 0 - position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 1, 0);//tell OpenGL how to read array / (starting pos, size, datatype, normalize, stride - how many to skip, last one - where to start to find first attribute of this type)

	glGenBuffers(NUM_BUFFERS, myColourArrayBuffers); //get buffers to write to
	glBindBuffer(GL_ARRAY_BUFFER, myColourArrayBuffers[POSITION_VB]);//bind buffer, first argument tells OpenGL to treat buffer as an array
	glBufferData(GL_ARRAY_BUFFER, myList->getLength() * sizeof(glm::vec3), myList->cols, GL_STATIC_DRAW); // put data in buffer 	glBufferData(target, size, pointerdata, usage); usage - where to store in memory (static - not going to change => place easy read from, not necessarily to write to)
	
	glEnableVertexAttribArray(1); // attribute 1 - colour
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 1, 0);//tell OpenGL how to read array / (starting pos, size, datatype, normalize, stride - how many to skip, last one - where to start to find first attribute of this type)

	glBindVertexArray(0);//unbind
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &myVertexArrayObject);
}

void Mesh::Draw() {
	glBindVertexArray(myVertexArrayObject);//bind
	glDrawArrays(GL_TRIANGLES, 0, myDrawCount);

	glBindVertexArray(0);//unbind
}