#include "Animation.hpp"

Animation::Animation(void) {
	_lastAnimUpdate = 0;
	_frameCount = 0;
	_nextIndex = 0;
}

Animation::Animation(Animation const & src) {
	*this = src;
}

Animation::~Animation(void) {

}

Animation &	Animation::operator=(Animation const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

Transform	Animation::updateTransform(Transform transform) {
	if (this->_lastAnimUpdate == 0)
		this->_lastAnimUpdate = SDL_GetTicks();
    uint32_t current_time = SDL_GetTicks();
    uint32_t elapsed_time = current_time - this->_lastAnimUpdate;
	if (elapsed_time > (1000 / 24)) {
		this->_lastAnimUpdate = current_time;
		transform = interpolate(transform, keyFrames[this->_nextIndex].transform,
				keyFrames[this->_nextIndex].frame - _frameCount);
		std::cout << keyFrames[this->_nextIndex].frame << " | " << this->_frameCount << std::endl;
		if (keyFrames[this->_nextIndex].frame == this->_frameCount) {
			if (_nextIndex + 1 < keyFrames.size()) {
				_nextIndex++;
			} else {
				_nextIndex = 0;
				_frameCount = -1;
			}
		}
		_frameCount++;
	}
	return (transform);
}

Transform	Animation::interpolate(Transform currentTransform, Transform targetTransform, int step) {
	if (step == 0)
		return (currentTransform);
	Transform newTransform = currentTransform;
	//(1 - t) * v0 + t * v1; lerp
	newTransform.position = (1.0f - (1.0f / (float)step)) * currentTransform.position
		+ (1.0f / (float)step) * targetTransform.position;
	/*
	newTransform.position = (currentTransform.position + (1.0f / (float)step))
		* (targetTransform.position - currentTransform.position); */
	newTransform.position.print();
	return (newTransform);
}
