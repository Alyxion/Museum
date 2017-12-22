!!RC1.0
# Absolute DOT3 Normal Map Combiner
# 
# This file is part of the Aphereon Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#
# Texture 0 contains the base texture
# Texture 1 contains the ADN Map
# Color   0 contains the untransformed normal vector at this pixel
# Const   0 contains the light vector in object space
# Const   1 contains the half angle vector in object space
#
# Calculate the "transformed" normal for this pixel by simply adding
# texture normal and the smoothed normal passed from the vertex shader
{
  rgb {
    discard = expand(tex1);
    discard = expand(col0);
    spare1=sum();
  }
}
# Calculate diffuse and specular intensity
{
  rgb {
    spare0 = spare1 . expand(const0);
    spare1 = spare1 . expand(const1);
  }
}
# Scale specular by shininess
{
  rgb {
    spare1 = spare1 * const0.a;
  }
}
# Power specular by 2
{
  rgb {
    spare1 = spare1 * spare1;
  }
}
# Otuput the result
out.rgb = spare0*tex0+spare1;
# We use base texture's alpha as result alpha
out.a = tex0.a;
