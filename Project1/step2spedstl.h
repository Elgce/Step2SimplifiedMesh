#pragma once
#include <iostream>
#include <cstdio>
#include "step2mesh.h"
#include "Shape.h"
#include <string>

#pragma comment(lib,"engine3D.lib")
#pragma comment(lib,"step2mesh.dll.lib")
_declspec(dllimport) class Shape;

using namespace step2mesh;

class  Step2SimplifiedSTL {
public:
	Step2SimplifiedSTL(const std::string& fileName, int simplifyFlag, double percent, const char* tmpPath ,const char* outPath);
	~Step2SimplifiedSTL();
private:
	bool ends_with(const std::string& str, const std::string& suffix);
};