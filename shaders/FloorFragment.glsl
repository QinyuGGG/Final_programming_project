#version 330 core
in vec4 normal;
in vec4 light_direction;
in vec4 world_position;
out vec4 fragment_color;

void main()
{
 
	vec4 white = vec4(1.0, 1.0, 1.0, 1.0);
	float x = floor(world_position.x / 2.5);
	float z  = floor(world_position.z / 2.5);
	vec4 color = mod(x + z, 2) * white;
	float dot_nl = dot(normalize(light_direction), normalize(normal));
	dot_nl = clamp(dot_nl, 0.0, 1.0);
	fragment_color = clamp(dot_nl * color, 0.0, 1.0);
}