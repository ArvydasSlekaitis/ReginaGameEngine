#include <DirectionalLighting.fx>

float4x4 ViewProjectionXf : ViewProjection < string UIWidget="None"; >;


float4 pv;
float4 Kd; 
float4 Ks;
float  m;


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
//------------Directional Lighting-----------------------------------------------------------
//-------------------------------------------------------------------------------------------

struct vertexInput_DirectionalLighting 
{
    float3 Position : POSITION;
	float3 Normal   : NORMAL;
    float4 r1       : TEXCOORD1;
    float4 r2       : TEXCOORD2;
    float4 r3       : TEXCOORD3; 
    float4 r4       : TEXCOORD4;//Inverse Transpose
    float4 r5       : TEXCOORD5;
    float4 r6       : TEXCOORD6; 
    float4 r7       : TEXCOORD7; 	
};

//===========================================

struct vertexOutput_DirectionalLighting 
{
    float4 HPosition    : POSITION;
    float3 wNormal      : TEXCOORD0;
	float3 wPosition    : TEXCOORD1;  
	float4 Shadow_0     : TEXCOORD2;
};

//===========================================

vertexOutput_DirectionalLighting  VS_DirectionalLighting (vertexInput_DirectionalLighting  IN) 
{
    vertexOutput_DirectionalLighting  OUT;
     
	float4 row1 = float4(IN.r1.x,IN.r2.x,IN.r3.x,0);
	float4 row2 = float4(IN.r1.y,IN.r2.y,IN.r3.y,0);
	float4 row3 = float4(IN.r1.z,IN.r2.z,IN.r3.z,0);
	float4 row4 = float4(IN.r1.w,IN.r2.w,IN.r3.w,1);
	
	float4x4 W = float4x4(row1,row2,row3,row4);//World
	float4x4 WIT = float4x4(IN.r4,IN.r5,IN.r6,IN.r7);//World Inverse Transpose
    		
	float4 Po = float4(IN.Position.xyz,1.0);	
	float3 Pw = mul(Po,W).xyz;		
	
	OUT.wPosition = Pw; 
  	OUT.HPosition = mul( float4(Pw.xyz, 1) , ViewProjectionXf);

 	OUT.wNormal   = mul(float4(IN.Normal, 1), WIT).xyz;
	
	
	 OUT.Shadow_0 = mul(Po, mul(W, directional_ShadowTransform[0]));
	 //OUT.Shadow_0 = mul(Pw, directional_ShadowTransform[0]);
	    
    return OUT;
}

//===========================================

float4 PS_DirectionalLighting (vertexOutput_DirectionalLighting IN) : COLOR
{     
							
float3 Lo = CalculateDirectionalLighting(IN.wPosition, normalize(IN.wNormal), pv, Kd, Ks, m, IN.Shadow_0);
return float4(Lo, 1); 
}

//===========================================



//-------------------------------------------------------------------------------------------
//------------Techniques---------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

technique Instance_NoLighting 
{
    pass p0 
    {		
	VertexShader = compile vs_3_0 VS_NoLighting();
	PixelShader = compile ps_3_0 PS_NoLighting();
	
CullMode = none;
	//CullMode =CCW;
	ZEnable = true;
	ZWriteEnable = true;
	AlphaBlendEnable =false;    
ColorWriteEnable = true;     
   }
}

//===========================================

technique Instance_DirectionalLighting 
{
    pass p0 
    {		
	VertexShader = compile vs_3_0 VS_DirectionalLighting();
	PixelShader = compile ps_3_0 PS_DirectionalLighting();
	
	//CullMode =CCW;
CullMode = none;
	ZEnable = true;
	ZWriteEnable = true;
	AlphaBlendEnable =false;         
	//ZFunc = LessEqual;
   }
}

//===========================================

technique Instance_Shadow
{
    pass p0 
    {		
	VertexShader = compile vs_3_0 VS_NoLighting();
	PixelShader = compile ps_3_0 PS_NoLighting();
	
ZEnable = True;
AlphaBlendEnable = False;
Lighting = False;
//CullMode = CCW;		
ColorWriteEnable = 0;

   }
}

//===========================================
