float4x4 matVP : ViewProjection;


//------------------------------------
struct vertexInput {
    float3 Position : POSITION;
    float2 UV       : TEXCOORD0;
    float4 r1       : TEXCOORD1;
    float4 r2       : TEXCOORD2;
    float4 r3       : TEXCOORD3; 
};

struct vertexOutput {
    float4 HPosition    : POSITION;
    float2 UV           : TEXCOORD0;
};


//----------------------------------------------


texture Diffuse;

sampler2D Diffuse_Sampler = sampler_state
{
    Texture = <Diffuse>;
    MinFilter = Linear;
    MagFilter = Linear;
    MipFilter = Linear;
};




//------------------------------------
vertexOutput Instance_VS(vertexInput IN) 
{
    vertexOutput OUT;
     
	float4 row1 = float4(IN.r1.x,IN.r2.x,IN.r3.x,0);
	float4 row2 = float4(IN.r1.y,IN.r2.y,IN.r3.y,0);
	float4 row3 = float4(IN.r1.z,IN.r2.z,IN.r3.z,0);
	float4 row4 = float4(IN.r1.w,IN.r2.w,IN.r3.w,1);
	
	float4x4 W = float4x4(row1,row2,row3,row4);	
    		
	float4 Po = float4(IN.Position.xyz,1.0);	
	float3 Pw = mul(Po,W).xyz;				
  
	OUT.HPosition = mul( float4(Pw.xyz, 1) , matVP);
	OUT.UV = IN.UV;
  
    
    return OUT;
}

//-----------------------------------

float4 Instance_PS(vertexOutput IN) : COLOR
{     
return tex2D(Diffuse_Sampler, IN.UV);
}

//-----------------------------------
technique Instance
{
    pass p0 
    {		
		VertexShader = compile vs_2_0 Instance_VS();
		PixelShader = compile ps_2_0 Instance_PS();
	
CullMode =CCW;
ZEnable = true;
ZWriteEnable = true;
AlphaBlendEnable =false;
         
   }
}
