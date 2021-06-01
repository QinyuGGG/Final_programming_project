#version 330 core
layout (location=0)in vec3 inVert;
layout (location=2)in vec2 inUV;
uniform mat4 MVP;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 light_position;
out vec4 face_normal;
out vec4 world_position;
out vec4 light_direction;
out vec4 vs_light_direction;
out vec4 normal;

void main()
{
	world_position = MVP*vec4(inVert, 1.0);;
	light_direction = view * (light_position - world_position);
	gl_Position = world_position;
	vs_light_direction = -gl_Position + view * light_position;

}