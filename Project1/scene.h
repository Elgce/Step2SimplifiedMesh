#pragma once
#include "shape.h"
#include <vector>

class Scene : public MovableGLM
{
	std::vector<Shape*> shapes;

	Shape *axisMesh;

protected:
	int pickedShape;

public:
	enum axis{xAxis,yAxis,zAxis};
	enum transformations{xLocalTranslate,yLocalTranslate,zLocalTranslate,xGlobalTranslate,yGlobalTranslate,zGlobalTranslate,
		xLocalRotate,yLocalRotate,zLocalRotate,xGlobalRotate,yGlobalRotate,zGlobalRotate,xScale,yScale,zScale,xCameraTranslate,yCameraTranslate,zCameraTranslate};
	Scene();
	Scene(glm::vec3 position,float angle,float hwRelation,float near, float far);
	void addShape(int type);
	void addShape(const std::string& fileName, glm::vec3 position, int simplifyFlag);															//@Edited
	void addShape(const std::string& fileName,const std::string& textureFileName, int simplifyFlag);						//@Edited
	void addShape(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices,const std::string& textureFileName);

	glm::mat4 GetViewProjection(int indx) const;
	glm::mat4 GetShapeTransformation() const;
	void shapeTransformation(int type,float amt);
	void inline setPicked(int pickID){pickedShape = pickID;}
	virtual ~Scene(void);
};

