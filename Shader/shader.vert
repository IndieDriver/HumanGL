#version 410 core
layout(location = 0) in vec3 vertex_pos;
layout(location = 1) in vec3 vertex_normal;

uniform mat4 MVP;
uniform mat4[64] bones;
uniform vec4[64] colors;

out vec4 color;
void main () {
	color = colors[gl_InstanceID];
	gl_Position = MVP * bones[ gl_InstanceID ] * vec4(vertex_pos, 1.0);
}
