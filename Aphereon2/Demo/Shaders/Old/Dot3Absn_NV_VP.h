!!VP1.0
# ADNM Vertex Program
#
# This file is part of the Aphereon Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#
# This file is just needed for experimental use. You can
# as well simply pass the normal as color and will get
# the same result.
#
# Constant 4 contains 0 0.5 1.0 2.0

# position transform
DP4 o[HPOS].x, c[0], v[OPOS];
DP4 o[HPOS].y, c[1], v[OPOS];
DP4 o[HPOS].z, c[2], v[OPOS];
DP4 o[HPOS].w, c[3], v[OPOS];

# simply pass tex coords:
MOV o[TEX1], v[TEX0];
MOV o[TEX0], v[TEX0];

# pass unexpanded normal
# add 1.0
ADD R1, v[NRML], c[4].z;
# divide by 2 (*0.5)
MUL R1, R1, c[4].y;
# pass the normal as color
MOV o[COL0], R1;

END
