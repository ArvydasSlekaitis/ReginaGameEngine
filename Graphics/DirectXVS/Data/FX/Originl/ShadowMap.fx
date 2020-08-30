//Lookup
float Shadow_offset_lookpup(sampler2D Map, float4 Loc, float2 Offset : texcoord)
{
return tex2Dproj(Map, float4(Loc.xy + Offset*Loc.w, Loc.z, Loc.w));
}

//PCF
float ShadowPCFHighQuality(sampler2D Map, float4 Loc)
{
float sum = 0;
float x, y;


/*for(y = -1.5; y <= 1.5; y+=1.0)
for(x = -1.5; x <= 1.5; x+=1.0)
sum+= Shadow_offset_lookpup(Map, Loc, float2(x/4096, y/4096));

sum/=16;*/

for(y = -1; y <= 1; y+=1.0)
for(x = -1; x <= 1; x+=1.0)
sum+= Shadow_offset_lookpup(Map, Loc, float2(x/4096, y/4096));

sum/=9;

return sum.xxx;
}					