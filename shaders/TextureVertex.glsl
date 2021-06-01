#version 330 core
layout (location=0)in vec3 inVert;
layout (location=2)in vec2 inUV;

out float vLightIntensity;
out vec3 vMCposition;
const vec3 LIGHTPOS = vec3( -2., 0., 10. );
out vec2 vST;
uniform mat4 MVP;
void main( )
{
  vec3 tnorm = normalize( gl_NormalMatrix * gl_Normal );
  vec3 ECposition = ( gl_ModelViewMatrix * vec4(inVert, 1.0) ).xyz;
  vLightIntensity = abs( dot( normalize(LIGHTPOS - ECposition), tnorm ) );


  vST = inUV.st;
  vMCposition = inVert.xyz;

  //gl_Position = gl_ModelViewProjectionMatrix * inVert;
  gl_Position = MVP*vec4(inVert, 1.0);
}
