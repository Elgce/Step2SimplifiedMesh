#pragma once
#include "MovableGLM.h"
#include "mesh.h"
#include <list>

class __declspec(dllexport) Shape : public MovableGLM
{
	Mesh *mesh;
	bool isCopy;
public:
	enum{triangles,lines};
	Shape(const std::string& fileName, int simplifyFlag, double percent, const char* outPath);//@Edited Elgce

	Shape(const Shape& shape);
	Shape(const std::string& fileName, int simplifyFlag, double percent);																							//@Edited
	Shape(const std::string& fileName,const std::string& textureFileName, int simplifyFlag, double percent);														//@Edited
	Shape(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);										
	Shape(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, const std::string& textureFileName);
	void addMesh(Vertex* vertices, unsigned int numVertices,unsigned int* indices, unsigned int numIndices, const std::string& textureFileName);	
	void addMesh(Vertex* vertices, unsigned int numVertices,unsigned int* indices, unsigned int numIndices);
	void getPoints(std::list<glm::vec3> &pList);
	virtual ~Shape(void);
};