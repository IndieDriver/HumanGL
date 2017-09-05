#version 410 core
layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec3 vertex_color;
layout(location = 3) in float boneIndex;

uniform mat4 MVP;
uniform mat4[5] bones;

out vec3 color;
void main () {
	color = vertex_color;
	gl_Position = MVP * bones[ int(boneIndex) ] * vec4(vertex_pos, 1.0);
}
