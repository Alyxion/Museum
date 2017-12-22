!!VP1.0
# DOT3 Vertex Program
#
# This file is part of the Aphereon Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#

# position transform                                      
DP4 o[HPOS].x, c[0], v[OPOS];
DP4 o[HPOS].y, c[1], v[OPOS];
DP4 o[HPOS].z, c[2], v[OPOS];
DP4 o[HPOS].w, c[3], v[OPOS];

# normalize tangent vector
MOV R1, v[6];
DP3 R1.w, R1, R1;
RSQ R1.w, R1.w;
MUL R1.xyz, R1, R1.w;

# normalize binormal vector
MOV R2, v[7];
DP3 R2.w, R2, R2;
RSQ R2.w, R2.w;
MUL R2.xyz, R2, R2.w;

# calculate light vector displacement
DP3 o[TEX2].x, c[4], R1;
DP3 o[TEX2].y, c[4], R2;
DP3 o[TEX2].z, c[4], v[NRML];

# calculate half vector displacement
DP3 o[TEX3].x, c[5], R1;
DP3 o[TEX3].y, c[5], R2;
DP3 o[TEX3].z, c[5], v[NRML];

# set bump map texture coordinates to the UV coords of unit ! ONE !... if
# the bump map shall not have indepent coordinates use the vertex format
# flag vfUVShare01 so the coordinates of the base texture will be taken.
MOV o[TEX1], v[TEX1];
# texture unit 3... the BASE texture... uses the texture coordinates of unit
# ! ZERO !... so we don't need to change the vertex format if the material
# is created without bump map texture etc.
MOV o[TEX0], v[TEX0];

END
