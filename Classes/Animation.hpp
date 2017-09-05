#pragma once
#include <vector>
#include "Vec.hpp"
#include "env.hpp"
#include "struct.hpp"

struct KeyFrame {
	int			frame;
	Transform	transform;
};

class Animation {
	public:
		Animation(void);
		Animation(Animation const & src);
		virtual ~Animation(void);
		Animation & operator=(Animation const & rhs);
		std::vector<KeyFrame>	keyFrames;
		Transform	updateTransform(Transform transform);
	private:
		uint32_t	_lastAnimUpdate;
		uint32_t	_frameCount;
		uint32_t	_nextIndex;				//Next index in keyFrame vector
		uint32_t	_stepBeforeNextFrame; 	//Remaining step before next frame

		Transform interpolate(Transform currentTransform, Transform targetTransform, int step);
};
