///////////////////////////////////////////////////////////
//  CRenderInstance.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDERINSTANCE_H
#define REGINA_CRENDERINSTANCE_H

#include <d3dx9.h>

#include <string>
using namespace std;

#include <EMatterialTypeEnumaration.h>
#include <ERenderInstanceTypeEnumaration.h>
#include <ERenderTypeEnumaration.h>

namespace Regina
{

class CRenderInstance
{
	const eMatterialType		matterialType;
	const eRenderInstanceType	renderInstanceType;
	unsigned	matterialID;
	bool		modified;

	CRenderInstance(const CRenderInstance&) : matterialType(MatterialType_NONE), renderInstanceType(RenderInstanceType_NONE) {}

protected:
	LPDIRECT3DDEVICE9 device;
	void SetMatterialID(const unsigned& iMatterialID) { matterialID = iMatterialID; }
	void SetModified(const bool& iModified) { modified = iModified; }
	
	eMatterialType		MatterialType()		const { return matterialType; }
	eRenderInstanceType	RenderInstanceType()const { return renderInstanceType; }
	unsigned			MatterialID()		const { return matterialID; }
	bool				Modified()			const { return modified; }

public:
	virtual ~CRenderInstance();

	CRenderInstance(LPDIRECT3DDEVICE9 iDevice, const eMatterialType& iMatterialType, const eRenderInstanceType&	iRenderInstanceType);

	virtual void Render(const eRenderType& iRenderType, const D3DXMATRIX& iCameraView, const D3DXMATRIX& iCameraProj, const D3DXVECTOR3& iCameraPosition) =0;
	virtual void Clear() =0;
	virtual void OnLostDevice() = 0;
	virtual void OnResetDevice() = 0;
};

}

#endif 