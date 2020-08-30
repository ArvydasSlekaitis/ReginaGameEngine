///////////////////////////////////////////////////////////
//  CMatterial.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CMATTERIAL_H
#define REGINA_CMATTERIAL_H

#include <d3dx9.h>

#include <CMatterialData.h>

namespace Regina
{


class CMatterial
{
	CMatterialData* data;
public:
	virtual ~CMatterial();

	CMatterial(CMatterialData* iMatterialData);
	CMatterial(const CMatterial& iMatterial);

	bool				TransparencyEnabled()	const;

	eMatterialType		MatterialType()			const;
	unsigned			MatterialID()			const;
	eRenderInstanceType	RenderInstanceType()	const;

	void	GetProperty(const string& iPropertyName, float& oPropertyValue)				const;
	void	GetProperty(const string& iPropertyName, string& oPropertyValue)			const;
	void	GetProperty(const string& iPropertyName, D3DXVECTOR2& oPropertyValue)		const;
	void	GetProperty(const string& iPropertyName, D3DXVECTOR3& oPropertyValue)		const;
	void	GetProperty(const string& iPropertyName, D3DXVECTOR4& oPropertyValue)		const;

	void	SetProperty(const string& iPropertyName, const string& iPropertyValue);
	void	SetProperty(const string& iPropertyName, const float& iPropertyValue);
	void	SetProperty(const string& iPropertyName, const D3DXVECTOR2& iPropertyValue);
	void	SetProperty(const string& iPropertyName, const D3DXVECTOR3& iPropertyValue);
	void	SetProperty(const string& iPropertyName, const D3DXVECTOR4& iPropertyValue);

};

}

#endif 