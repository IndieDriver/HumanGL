#pragma once
#include <string>
#include <fstream>
#include <cstdio>
#include "Model.hpp"
#include "struct.hpp"
#include "Vec.hpp"

struct MemberElement {
	Vec3 ori;
	Transform transform;
	Vec3 col;
};

class Skeleton {
	public:
		Skeleton(void);
		Skeleton(Skeleton const & src);
		virtual ~Skeleton(void);
		Skeleton & operator=(Skeleton const & rhs);
		void	loadSkeleton(std::string filename, Model *model);
};
