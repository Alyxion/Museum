//##############################################################################
//#                                                                            #
//#  This file is part of the Aphereon X Engine                                #
//#  Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net                      #
//#                                                                            #
//##############################################################################
/**
@file Dot3Bump_GLSL_VS.h
@brief DOT3 Bump Mapping GL Shading Language Vertex Shader
*/
attribute vec3 Tangent;
attribute vec3 Binormal;

uniform vec3 LightVec;
uniform vec3 HalfAngle;

varying vec2 UV;
varying vec3 LV;
varying vec3 HA;

void main()
{
   // output vertex position
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

   // output texture coordinates for decal and normal maps
   UV = vec2(gl_MultiTexCoord0);

   // light vector
   LV.x=dot(LightVec, Tangent);
   LV.y=dot(LightVec, Binormal);
   LV.z=dot(LightVec, gl_Normal);

   // half angle vector
   HA.x=dot(HalfAngle, Tangent);
   HA.y=dot(HalfAngle, Binormal);
   HA.z=dot(HalfAngle, gl_Normal);
}
