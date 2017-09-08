#pragma once
#include <limits>
#include "env.hpp"
#include "Matrix.hpp"
#include "Vec.hpp"

class Camera {
	public:
		Vec3    pos;
		Vec3    dir;
		Vec3    right;
		Vec3    up;
		Matrix  proj;
		Matrix  view;
		int     width;
		int     height;
		float	mouseXpos;
		float	mouseYpos;
		bool  mouseMoved = false;

		Camera(Vec3 pos = Vec3(), int width = 0, int height = 0);
		void queryInput(const uint8_t *keyStates);
		void update();
	private:
		float horAngle;
		float verAngle;
		float speed = 0.3f;
		float deltaTime;
		float lastTime;
};
