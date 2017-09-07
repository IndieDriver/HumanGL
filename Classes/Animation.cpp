#include "Animation.hpp"

Animation::Animation(std::string animName) {
    this->name = animName;
    _lastAnimUpdate = 0;
    _frameCount = 0;
    _nextIndex = 0;
    _offsetTransform = {{0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f}};
}

Animation::Animation(Animation const & src) {
    *this = src;
}

Animation::~Animation(void) {

}

Animation &	Animation::operator=(Animation const & rhs) {
    if (this != &rhs){
	this->name = rhs.name;
	this->keyFrames = rhs.keyFrames;
	this->_lastAnimUpdate = rhs._lastAnimUpdate;
	this->_frameCount = rhs._frameCount;
	this->_nextIndex = rhs._nextIndex;
    }
    return (*this);
}

Transform	Animation::updateTransform(Transform transform) {
    if (this->_lastAnimUpdate == 0)
	this->_lastAnimUpdate = SDL_GetTicks();
    uint32_t current_time = SDL_GetTicks();
    uint32_t elapsed_time = current_time - this->_lastAnimUpdate;
    if (elapsed_time > (1000 / 60)) {
	this->_lastAnimUpdate = current_time;
	transform = interpolate(transform, keyFrames[this->_nextIndex].transform,
		keyFrames[this->_nextIndex].frame - _frameCount);
	if (keyFrames[this->_nextIndex].frame == this->_frameCount) {
	    if (_nextIndex + 1 < keyFrames.size()) {
		_nextIndex++;
	    } else {
		_nextIndex = 0;
		_frameCount = -1;
		this->_offsetTransform = {{0.0f, 0.0f, 0.0f},
					{0.0f, 0.0f, 0.0f},
					{0.0f, 0.0f, 0.0f}};
	    }
	}
	_frameCount++;
    }
    return (transform);
}

Transform	Animation::interpolate(Transform currentTransform, Transform targetTransform, int step) {
    if (step == 0)
	return (currentTransform);
    float t = 1.0f / (float)step;
    Transform oldOffset = _offsetTransform;

    _offsetTransform.position = (1.0f - t) * _offsetTransform.position
	+ t * targetTransform.position;
    currentTransform.position += (_offsetTransform.position - oldOffset.position);

    _offsetTransform.rotation = (1.0f - t) * _offsetTransform.rotation
	+ t * targetTransform.rotation;
    currentTransform.rotation += (_offsetTransform.rotation - oldOffset.rotation);

    _offsetTransform.scale = (1.0f - t) * _offsetTransform.scale
	+ t * targetTransform.scale;
    currentTransform.scale += (_offsetTransform.scale - oldOffset.scale);
    return (currentTransform);
}

/*
void		Animation::init() {
    this->_offsetTransfrom = {{0.0f, 0.0f, 0.0f},
			    {0.0f, 0.0f, 0.0f},
			    {0.0f, 0.0f, 0.0f}};
} */

void		Animation::reset() {
    this->_lastAnimUpdate = 0;
    this->_frameCount = 0;
    this->_nextIndex = 0;
    this->_offsetTransform = {{0.0f, 0.0f, 0.0f},
			    {0.0f, 0.0f, 0.0f},
			    {0.0f, 0.0f, 0.0f}};
}
