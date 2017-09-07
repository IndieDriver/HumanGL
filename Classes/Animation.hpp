#pragma once
#include <vector>
#include <string>
#include "Vec.hpp"
#include "env.hpp"
#include "struct.hpp"

struct KeyFrame {
	int			frame;
	Transform	transform;
};

class Animation {
	public:
		Animation(std::string animName);
		Animation(Animation const & src);
		virtual ~Animation(void);
		Animation & operator=(Animation const & rhs);
		std::string				name;
		std::vector<KeyFrame>	keyFrames;
		Transform	updateTransform(Transform transform);

		void		reset();
	private:
		uint32_t	_lastAnimUpdate;
		uint32_t	_frameCount;
		uint32_t	_nextIndex;				//Next index in keyFrame vector

		Transform interpolate(Transform currentTransform,
				Transform targetTransform, int step);
};
