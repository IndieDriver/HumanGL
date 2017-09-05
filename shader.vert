#version 410 core
layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec3 vertex_color;
layout(location = 3) in float vertex_uv;

uniform mat4 MVP;

out vec3 color;
void main () {
	color = vertex_color;
	gl_Position = MVP * vec4(vertex_pos, 1.0);
}
