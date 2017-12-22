!!TS1.0
# DOT3 Texture Shader
#
# This file is part of the Aphereon Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#
texture_2d();  // base texture
texture_2d();  // normal map
dot_product_2d_1of2(expand(tex1)); // (light vector dot normal)
dot_product_2d_2of2(expand(tex1)); // (half vector dot normal)
