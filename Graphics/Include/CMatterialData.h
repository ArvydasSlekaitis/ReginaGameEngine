///////////////////////////////////////////////////////////
//  CMatterialData.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CMATTERIALDATA_H
#define REGINA_CMATTERIALDATA_H

#include <d3dx9.h>

#include <string>
using namespace std;

#include <EMatterialTypeEnumaration.h>
#include <ERenderInstanceTypeEnumaration.h>

namespace Regina
{

class CMatterialData
{	
	const eMatterialType		matterialType;
	const eRenderInstanceType	renderInstanceType;
	unsigned	matterialID;
	bool		transparencyEnabled;

protected:
	void EnableTransparency();
	void DisableTransparency();
	void SetMatterialID(const unsigned& iMatterialID) { matterialID = iMatterialID; }

public:
	virtual ~CMatterialData();
	CMatterialData(const eMatterialType& iMatterialType, const eRenderInstanceType&	iRenderInstanceType);

	bool				TransparencyEnabled()	const	{ return transparencyEnabled; }
	eMatterialType		MatterialType()			const	{ return matterialType; }
	unsigned			MatterialID()			const	{ return matterialID; }
	eRenderInstanceType RenderInstanceType()	const	{ return renderInstanceType; }
	
	virtual	void	GetProperty(const string&, float&)  { throw invalid_argument("CMatterialData::GetProperty - trying to get property which does not exist"); }
	virtual void	GetProperty(const string&, string&) { throw invalid_argument("CMatterialData::GetProperty - trying to get property which does not exist"); }
	virtual void	GetProperty(const string&, D3DXVECTOR2&)  { throw invalid_argument("CMatterialData::GetProperty - trying to get property which does not exist"); }
	virtual void	GetProperty(const string&, D3DXVECTOR3&)  { throw invalid_argument("CMatterialData::GetProperty - trying to get property which does not exist"); }
	virtual void	GetProperty(const string&, D3DXVECTOR4&)  { throw invalid_argument("CMatterialData::GetProperty - trying to get property which does not exist"); }

	virtual void	SetProperty(const string&, const string&)		{ throw invalid_argument("CMatterialData::SetProperty - trying to set property which does not exist"); }
	virtual void	SetProperty(const string& , const float&)		{ throw invalid_argument("CMatterialData::SetProperty - trying to set property which does not exist"); }
	virtual void	SetProperty(const string&, const D3DXVECTOR2&)	{ throw invalid_argument("CMatterialData::SetProperty - trying to set property which does not exist"); }
	virtual void	SetProperty(const string&, const D3DXVECTOR3&)	{ throw invalid_argument("CMatterialData::SetProperty - trying to set property which does not exist"); }
	virtual void	SetProperty(const string&, const D3DXVECTOR4&)	{ throw invalid_argument("CMatterialData::SetProperty - trying to set property which does not exist"); }
};

}

#endif 