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

enum class AnimState {
	waiting,
	running,
	ending,
	finished
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
		void		markForEnd();	//Set the animation to stop at the end of this cycle
		AnimState	getState();
	private:
		Transform	_offsetTransform;
		uint32_t	_lastAnimUpdate;
		uint32_t	_frameCount;
		uint32_t	_nextIndex;				//Next index in keyFrame vector
		AnimState	_animationState;

		Transform interpolate(Transform currentTransform,
				Transform targetTransform, int step);
};
