///////////////////////////////////////////////////////////
//  CSimpleXFile.h
//  Created on:      01-11-2009
//  Last modified:   04-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CSIMPLEXFILE_H
#define REGINA_CSIMPLEXFILE_H

#include <d3dx9.h>
#include <string>
#include <map>
#include <stdexcept>
#include <fstream>
#include <assert.h>
using namespace std;

#include <Exception_OutOfMemmory.h>
#include <MeshDefinitions.h>

namespace Regina
{

class CSimpleXFile
{
	string							name;
	LPDIRECT3DVERTEXDECLARATION9	vertexDeclaration;
	LPD3DXMESH						mesh;
	static const D3DVERTEXELEMENT9* vertexElement;		//Default Regina engine mesh VE - Regina::VE_POS_NORM_BINORM_TAN_UV, declared in MeshDefinitions.h;

public:
	virtual ~CSimpleXFile();

	CSimpleXFile(LPDIRECT3DDEVICE9 iDevice, const string& iName);
	
	LPD3DXMESH						Mesh();
	LPDIRECT3DVERTEXDECLARATION9	VertexDeclaration();
	string							Name()					const;
};

}

#endif 