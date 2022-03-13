#include "step2spedstl.h"
#include <iostream>
#include <cstdio>
//#include "step2mesh.h"

#pragma comment(lib,"engine3D.lib")
#pragma comment(lib,"step2mesh.dll.lib")
#pragma comment(lib,"Step2Obj.lib")
using namespace std;

_declspec(dllimport) void step2simplifiedmesh(const std::string& fileName, int simplifyFlag, double percent, const char* tmpPath, const char* outPath);

int main() {
	step2simplifiedmesh("../file/231.step", 1, 0.999, "../res/tmp.obj", "../res/outer.stl");
	return 0;
}