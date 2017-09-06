
#pragma once
#include "Vec.hpp"

struct Vertex {
	Vec3 position;
	Vec3 normal;
};

struct Transform{
	Vec3 position;
	Vec3 rotation;
	Vec3 scale = {1.0f, 1.0f, 1.0f};
};
