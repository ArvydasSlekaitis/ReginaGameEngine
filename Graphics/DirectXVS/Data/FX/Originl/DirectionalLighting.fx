#include <ShadowMap.fx>

//Directional Lighting
#define MAXDIRECTINALLIGTHS 1
uint  	directional_NumDirectional;
float3  directional_l[MAXDIRECTINALLIGTHS];
float3 	directional_El[MAXDIRECTINALLIGTHS];
float4x4 directional_ShadowTransform[MAXDIRECTINALLIGTHS];

Texture directional_ShadowMap_0;
sampler2D directional_ShadowMapSampler_0 = 
sampler_state
{ 
	Texture = <directional_ShadowMap_0>;
	MinFilter = Point;
	MagFilter = Point;
	MipFilter = none;
	AddressU = Clamp;
	AddressV = Clamp;
};


float3 CalculateDirectionalLighting(float3 position,
									float3 normal,
									uniform float3 pv,
									uniform float3 Kd, 
									uniform float3 Ks,
									uniform float  m,
									float4 Shadow_0)
									
{
//float3 ShadowValue_0 = tex2Dproj(directional_ShadowMapSampler_0, Shadow_0).rgb;
float3 Shadow = ShadowPCFHighQuality(directional_ShadowMapSampler_0, Shadow_0);
//return Shadow; 

	float3 v = normalize(pv-position);
	float3 Lo = float3(0, 0, 0);
	
	for(uint i=0; i<directional_NumDirectional; i++)
		{
			float3 h = normalize(v+directional_l[i]);
			float  cosTh = saturate(dot(normal, h));
			float  cosTi = saturate(dot(normal, directional_l[i]));
			Lo += (Kd + Ks * pow(cosTh, m)) * directional_El[i] * cosTi;
		}
		
return Lo * Shadow;
}
									