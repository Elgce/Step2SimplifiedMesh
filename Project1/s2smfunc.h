#pragma once
#include "step2spedstl.h"
extern "C" void __declspec(dllexport) step2simplifiedmesh(const std::string & fileName, int simplifyFlag, double percent, const char* tmpPath, const char* outPath);