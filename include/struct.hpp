
#pragma once
#include "Vec.hpp"

struct Vertex {
	Vec3 position;
	Vec3 normal;
	Vec3 color;
	float	boneIndex;
};

struct Transform{
	Vec3 position;
	Vec3 rotation;
	Vec3 scale;
};