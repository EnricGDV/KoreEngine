#include "Globals.h"
#include <iostream>

#include "Libraries/MathGeoLib/include/Geometry/AABB.h"
#include "Libraries/MathGeoLib/include/Math/float4x4.h"

class myTexture
{
public:
	myTexture();
	~myTexture();

	uint id;
	const void* data;
	uint width;
	uint height;

	const char* path;
};

class myMesh
{
public:
	myMesh();
	~myMesh();
	
	uint id_index = 0;
	uint num_indices = 0;

	uint id_vertex = 0;
	uint num_vertices = 0;
	uint id_normal = 0;
	uint id_texcoord = 0;

	uint* indices = nullptr;
	float* vertices = nullptr;
	float* textureCoords = nullptr;
	float* normals = nullptr;

	uint* materialIndices = nullptr;
	uint materialid;
	const char* materialpath;
	//myTexture* material;

	void CreateAABB()
	{
		aabb.SetNegativeInfinity();
		aabb.Enclose((float3*)vertices, num_vertices);
	}

	math::AABB aabb;
};



namespace Importer
{
	void Debug();
	void CleanDebug();

	std::vector<myMesh> LoadMeshes(const char* file_path);
	myTexture LoadTexture(const char* file_path);

	uint64 SaveTexture(const myTexture* tex , char** fileBuffer);
	void LoadTexture(const char* fileBuffer, myTexture* tex);
}