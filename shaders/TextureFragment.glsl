#version 330 core


uniform float uAd = 0.09;
uniform float uBd = 0.15;
uniform float uTol= 1.05;
uniform float uNoiseFreq= .5005;;
uniform float uNoiseAmp= 0.5002195;;
uniform float uAlpha= 1;
uniform sampler3D Noise3;

uniform float uBodyGreen = 0.93;
uniform float uBodyBlue = 0.93;
uniform float uBodyRed = 0.93;

uniform float uDotBlue = 0.001;
uniform float uDotGreen = 0.65;
uniform float uDotRed = 0.85;

in vec2 vST;
in float vLightIntensity;
in vec3 vMCposition;

vec3 dotColor = vec3(uDotRed,uDotGreen,uDotBlue);
vec3 bodyColor = vec3(uBodyRed, uBodyGreen, uBodyBlue);

void main( )
{
  if(uAlpha == 0) discard;
  
  vec4 nv = texture3D(Noise3, uNoiseFreq * vMCposition);
  // give the noise a range of [-1.,+1.]:
  float n = nv.r + nv.g + nv.b + nv.a;
  n -= 2.;
  n *= uNoiseAmp;

  float Ar = uAd/2.;
  float Br = uBd/2.;
  int numins = int( vST.s / uAd );
  int numint = int( vST.t / uBd );
  float sc = float(numins) * uAd + Ar;
  float ds = vST.s - sc;	// wrt ellipse center
  float tc = float(numint) * uBd + Br;
  
  float dt = vST.t - tc; // wrt ellipse center

  float oldDist = sqrt( ds*ds + dt*dt );
  float newDist = oldDist + n;
  float scale = newDist / oldDist;// this could be < 1., = 1., or > 1.

  ds = ds * scale;
  ds = ds / Ar;
  dt = dt * scale;
  dt = dt / Br;

  float d = pow(abs(ds), 2) + pow(abs(dt), 2);

  float t = smoothstep( 1. - uTol, 1. + uTol, d );

  vec3 mixColor = vLightIntensity * mix(dotColor, bodyColor, t );

  if(d > 1){
    
    gl_FragColor = vec4(mixColor, uAlpha);
  }else{
    gl_FragColor = vec4(mixColor, 1.);
  }
}