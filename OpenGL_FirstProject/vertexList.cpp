#include "vertexList.h"
#include <iostream>
vertexList::vertexList(glm::vec3 points[], glm::vec3 colours[])
{
	length = sizeof(points) / sizeof(glm::vec3);
	verts = new glm::vec3[length];
	cols = new  glm::vec3[length];
	for (unsigned int i = 0; i < length; i++) {
		//if(points[i] && colours[i]) arevalid
		//{
		verts[i] = points[i];
		cols[i] = colours[i];
		usedLength++;
		//}
	}
}

vertexList::vertexList() {
	length = 0;
}

vertexList::vertexList(Vertex *vertices)
{

	length = sizeof(vertices);// / sizeof(glm::vec3);
	std::cout << "Creating vertex list of length " << length << std::endl;
	for (unsigned int i = 0; i < length; i++) {
		//if(points[i] && colours[i]) arevalid
		//{
		verts[i] = vertices[i].pos;
		cols[i] = vertices[i].col;
		usedLength++;
		//}
	}
}


vertexList::~vertexList()
{
		//delete [] verts;
		//delete [] cols;
}

unsigned int vertexList::getLength() {
	return this->usedLength;
}

void  vertexList::Push(Vertex vert) {
	//if(vert.pos && vert.col arevalid){
	if (usedLength < length) {//if there is enough space in the list, just add it to the next item and swagger on
		verts[usedLength - 1] = vert.pos;
		cols[usedLength - 1] = vert.col;
		//TODO: also push full-on vertices
	}
	else {//otherwise first create space
		createSpace();
		//and then push
		verts[usedLength - 1] = vert.pos;
		cols[usedLength - 1] = vert.col;
	}

	//}
}

void vertexList::SetBatchSize(unsigned int newBatchSize) {
	batch_size = newBatchSize;
}

void vertexList::Pop(){
	verts[usedLength--] = glm::vec3(-1.0,-1.0,-1.0);
	cols[usedLength] = glm::vec3(-1.0, -1.0, -1.0);
	if ((length - usedLength) == batch_size) {
		removeSpace();
	}
}

void vertexList::Push(glm::vec3 point, glm::vec3 colour) {
	//if(point && colour arevalid){
	if (usedLength < length) {//if there is enough space in the list, just add it to the next item and swagger on
		verts[usedLength - 1] = point;
		cols[usedLength - 1] = colour;
		//TODO: also push full-on vertices
	}
	else {//otherwise first create space
		createSpace();
		//and then push
		verts[usedLength - 1] = point;
		cols[usedLength - 1] = colour;
	}

	//}
}



void vertexList::createSpace() {
	// create temp arrays

	glm::vec3* vertsTemp = new glm::vec3[length];
	glm::vec3* colsTemp = new  glm::vec3[length];

	// and copy originals into them

	memcpy(vertsTemp, verts, length * sizeof(glm::vec3));
	memcpy(colsTemp, cols, length * sizeof(glm::vec3));

	//then, pump up the size of the original arrays
	length += batch_size;

	verts = new glm::vec3[length];
	cols = new glm::vec3[length];
	//copy temps back over
	memcpy(verts, vertsTemp, length * sizeof(glm::vec3));
	memcpy(cols, colsTemp, length * sizeof(glm::vec3));

	//and destroy the temp arrays

	delete[] vertsTemp;
	delete[] colsTemp;
}

void vertexList::removeSpace() {
	// create temp arrays a batch smaller -decrease length
	length -= batch_size;
	glm::vec3* vertsTemp = new glm::vec3[length];
	glm::vec3* colsTemp = new  glm::vec3[length];

	// and copy originals into them

	memcpy(vertsTemp, verts, length * sizeof(glm::vec3));
	memcpy(colsTemp, cols, length * sizeof(glm::vec3));

	//then, pump up the size of the original arrays


	verts = new glm::vec3[length];
	cols = new glm::vec3[length];
	//copy temps back over
	memcpy(verts, vertsTemp, length * sizeof(glm::vec3));
	memcpy(cols, colsTemp, length * sizeof(glm::vec3));

	//and destroy the temp arrays

	delete[] vertsTemp;
	delete[] colsTemp;
}
