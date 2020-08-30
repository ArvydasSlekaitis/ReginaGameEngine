//#include <DirectionalLighting.fx>

float4x4 ViewProjectionXf : ViewProjection < string UIWidget="None"; >;

//Camera 
float4 pv;  // Camera position

//Matterial
float4 Kd;  // Diffuse color / Pi
float4 Ks;  // ((surfaceSmoothness + 8) / (8*D3DX_PI))*specularColor; 
float  m;   // surfaceSmoothness
float4 Ka;  // Ambient color

//Lighting
float4 ambientColor; // Global ambient color


//-------------------------------------------------------------------------------------------
//------------No Lighting--------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

struct vertexInput_NoLighting 
{
    float3 Position : POSITION;
    float4 r1       : TEXCOORD1;
    float4 r2       : TEXCOORD2;
    float4 r3       : TEXCOORD3; 

};

//===========================================

struct vertexOutput_NoLighting 
{
    float4 HPosition    : POSITION;
};

//===========================================

vertexOutput_NoLighting  VS_NoLighting (vertexInput_NoLighting  IN) 
{
    vertexOutput_NoLighting  OUT;
     
	float4 row1 = float4(IN.r1.x,IN.r2.x,IN.r3.x,0);
	float4 row2 = float4(IN.r1.y,IN.r2.y,IN.r3.y,0);
	float4 row3 = float4(IN.r1.z,IN.r2.z,IN.r3.z,0);
	float4 row4 = float4(IN.r1.w,IN.r2.w,IN.r3.w,1);
	
	float4x4 W = float4x4(row1,row2,row3,row4);	
    		
	float4 Po = float4(IN.Position.xyz,1.0);	
	float3 Pw = mul(Po,W).xyz;				
  
	OUT.HPosition = mul( float4(Pw.xyz, 1) , ViewProjectionXf);
 
    
    return OUT;
}

//===========================================

float4 PS_NoLighting (vertexOutput_NoLighting IN) : COLOR
{     
return float4(0, 0, 0, 1);
}

//===========================================


//-------------------------------------------------------------------------------------------
//------------Ambient only-------------------------------------------------------------------
//-------------------------------------------------------------------------------------------


float4 PS_AmbientOnly (vertexOutput_NoLighting IN) : COLOR
{     
return float4(Ka*ambientColor.xyz, 1); 
}

//===========================================


//-------------------------------------------------------------------------------------------
//------------Techniques---------------------------------------------------------------------
//-------------------------------------------------------------------------------------------


//===========================================

technique Instance_AmbientOnly 
{
    pass p0 
    {		
	VertexShader = compile vs_2_0 VS_NoLighting();
	PixelShader = compile ps_2_0 PS_AmbientOnly(); 
	
	CullMode =CCW;
	ZEnable = true;
	ZWriteEnable = true;
	AlphaBlendEnable =false;
SrcBlend = ONE;
DestBlend = ZERO;

   }
}

