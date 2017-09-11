#include "Camera.hpp"

Camera::Camera(Vec3 position, int w, int h)
{
    pos = position;

    width = w;
    height = h;

    mouseXpos = ((float)w / 2.0f);
    mouseYpos = ((float)h / 2.0f);

    verAngle = 0.0f;
    horAngle = 180.0f * (M_PI / 180.0f);
    proj = projMatrix(50, w / h);
    update();
}

void Camera::update(){
    double currentTime = SDL_GetTicks();
    deltaTime = (float)currentTime - (float)lastTime;
    lastTime = (float)currentTime;
    if (mouseMoved) {
	horAngle += 0.00005f * deltaTime * mouseXpos;
	verAngle += 0.00005f * deltaTime * mouseYpos;
	mouseMoved = false;
    }
    dir = Vec3(cos(verAngle) * sin(horAngle),
	    sin(verAngle),
	    cos(verAngle) * cos(horAngle));
    dir.normalize();
    right = Vec3(sin(horAngle - 3.14f/2.0f),
	    0,
	    cos(horAngle - 3.14f/2.0f));
    right.normalize();
    up = right.cross(dir);
    up.normalize();
    view = viewMatrix(pos,
	    dir + pos,
	    up);
}

void Camera::queryInput(const uint8_t *keyStates) {
    if (keyStates[SDL_SCANCODE_LSHIFT]) {
	speed = 0.09f;
    } else {
	speed = 0.03f;
    }
    if (keyStates[SDL_SCANCODE_W] || keyStates[SDL_SCANCODE_UP]) {
	Vec3 tmp = dir * speed * deltaTime;
	pos = pos + tmp;
    }
    if (keyStates[SDL_SCANCODE_S] || keyStates[SDL_SCANCODE_DOWN]) {
	Vec3 tmp = dir * speed * deltaTime;
	pos = pos - tmp;
    }
    if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_LEFT]) {
	Vec3 right = up.cross(dir);
	Vec3 tmp = right * speed * deltaTime;
	pos = pos - tmp;
    }
    if (keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_RIGHT]) {
	Vec3 right = up.cross(dir);
	Vec3 tmp = right * speed * deltaTime;
	pos = pos + tmp;
    }
    if (keyStates[SDL_SCANCODE_Q]) {
	Vec3 tmp = up * speed * deltaTime;
	pos = pos + tmp;
    }
    if (keyStates[SDL_SCANCODE_E]) {
	Vec3 tmp = up * speed * deltaTime;
	pos = pos - tmp;
    }
}
