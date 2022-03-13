#ifndef OBJ_LOADER_H_INCLUDED
#define OBJ_LOADER_H_INCLUDED

#include "MeshSimplification.h"

#include <glm/glm.hpp>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <unordered_map>

template<typename T>
inline void hash_combine(std::size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void hash_val(std::size_t& seed, const T& val)
{
    hash_combine(seed, val);
}

template<typename T, typename... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types&... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template<typename... Types>
inline std::size_t hash_val(const Types& ...args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}
class hash_point {
public:
    size_t operator()(const glm::vec3& p) const {
        return hash_val(p.x, p.y, p.z);
    }
};

struct IndexedModel
{
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
	std::vector<glm::vec3> colors;
    std::vector<unsigned int> indices;
};

class OBJModel{
public:
    std::list<OBJIndex> OBJIndices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
	std::vector<glm::vec3> colors;

    std::unordered_map<glm::vec3, int, hash_point>	m_hash_point;
	
	bool hasUVs;
	
    bool hasNormals;
    int maxNormal = 0;
    
	OBJModel(const std::string& fileName, int simplifyFlag, double percent);											//Edited
    OBJModel(const std::string& stlFileName, double percent);
    void readSTLASCII(const std::string& fileName);
    void readSTLBinary(const std::string& fileName);

    IndexedModel ToIndexedModel();
    int findVertexByPoint(glm::vec3 p);

private:
    unsigned int FindLastVertexIndex(const std::vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const IndexedModel& result);
    void CreateOBJFace(const std::string& line);
    glm::vec2 ParseOBJVec2(const std::string& line);
    glm::vec3 ParseOBJVec3(const std::string& line);
    OBJIndex ParseOBJIndex(const std::string& token, bool* hasUVs, bool* hasNormals);
	void CalcNormals();

};

#endif // OBJ_LOADER_H_INCLUDED
