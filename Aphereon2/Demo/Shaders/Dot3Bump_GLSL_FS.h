//##############################################################################
//#                                                                            #
//#  This file is part of the Aphereon X Engine                                #
//#  Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net                      #
//#                                                                            #
//##############################################################################
/**
@file Dot3Bump_GLSL_FS.h
@brief DOT3 Bump Mapping GL Shading Language Fragment Shader
*/
uniform sampler2D BaseTex;   // base texture
uniform sampler2D NormalMap; // normal map
uniform sampler2D Lookup;    // lookup map

uniform vec4 Diffuse;  // diffuse intensity in rgb, ambient intensity in a
uniform vec4 Specular; // specular color in rgb, shininess in a

varying vec2 UV; // UV coordinate of fragment
varying vec3 LV; // LightVector * Mat3(Tangent,Binormal,Normal)
varying vec3 HA; // HalfAngle * Mat3(Tangent,Binormal,Normal)

void main()
{
    // fetch normal from normal map, expand to the -1..+1 range and normalize
    vec3 normal = 2.0 * (texture2D(NormalMap, UV).rgb - 0.5);

    // fetch diffuse and specular intensity from luminance alpha lookup map
    // r contains diffuse intensity, g contains specular intensity
    vec2 limu=texture2D(Lookup,
                        vec2(
                              dot(LV, normal),
                              dot(HA, normal)
                             )
                        ).ra;

    // get base map color
    vec4 BaseFrag    = texture2D(BaseTex,UV);
    // diffuse = ( lookup-map-diffuse * material/light-diffuse + ambient ) *
    //           basemap-pixel
    vec3 OutDiffuse  = (limu.r*Diffuse.rgb+Diffuse.aaa)*BaseFrag.rgb;
    // specular = lookup-map-specular * shininess * specular color
    vec3 OutSpecular = limu.g*Specular.a*Specular.rgb;

    // output final color
    gl_FragColor = vec4( OutDiffuse+OutSpecular, // RGB
                         BaseFrag.a);          // Alpha
}
