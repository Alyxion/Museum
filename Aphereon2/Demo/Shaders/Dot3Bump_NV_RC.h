!!RC1.0
# DOT3 Texture Combiner
# 
# This file is part of the Aphereon X Engine
# Copyright (c) 2004 by Michael Ikemann / Alyx@Gmx.net
#
# Texture unit 0 contains the base texture
# Texture unit 1 contains the normal map
# Texture unit 2 is reserved for dot3-bump step 1
# Texture unit 3 contains the diffuse light intensity in the color channel and
#                the specular intensity in the alpha channel.
#
# const0 contains LightDiffuse*MaterialDiffuse
# const1 contains LightSpecular+MaterialSpecular
{
  rgb {
    spare0 = tex3 * const0;
    spare1 = tex3.a * const1;
  }
}
# Scale specular by diffuse (else flickering occurs in darkness)
{
  rgb {
    spare1  = spare0*spare1;
  }
}
# Add ambient intensity
{
   rgb {
     discard = spare0;
     discard = const0.a;
     spare0 = sum();
   }
}
# Scale specular by shininess
{
   rgb {
     spare1  = spare1*const1.a;
   }
}
# Output the pixel
out.rgb = spare0*tex0+spare1;
# We use the base texture's alpha channel as result alpha
out.a = tex0.a;
