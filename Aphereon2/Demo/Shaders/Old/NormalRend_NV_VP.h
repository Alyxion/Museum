!!VP1.0
# Renders the normals into a 2D texture
#
# This file is part of the Aphereon Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#
# For experimental use only.
#

# c4 = texture scaling vector
# c5 = constants 0 1 2 0.5

# position transform. we are using the UV coordinates as position
# get coordinates
MOV R1.x, v[TEX0].x;
MOV R1.y, v[TEX0].y;
# set z to 0 and w to 1
MOV o[HPOS].z, c[5].x;
MOV o[HPOS].w, c[5].y;
# scale by texture size in relation to screen size
MUL R1.xy, R1, c[4];
# move to lower left corner of the screen
ADD R1.xy, R1, -c[5].yyyy;
# output the result
MOV o[HPOS].x, R1.x;
MOV o[HPOS].y, R1.y;

# pass the normal as color
MUL R1, v[NRML], c[5].wwww;
ADD R1, R1, c[5].wwww;
MOV o[COL0], R1;

END
