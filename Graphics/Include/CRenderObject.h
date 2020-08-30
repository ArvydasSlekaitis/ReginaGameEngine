///////////////////////////////////////////////////////////
//  CRenderObject.h
//  Created on:      01-11-2009
//  Last modified:   01-11-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////

#ifndef REGINA_CRENDEROBJECT_H
#define REGINA_CRENDEROBJECT_H

#include <CMatterial.h>

namespace Regina
{


class CRenderObject
{
public:
	enum eType{type_Static, type_Dynamic};

private:
	CMatterial	matterial;
	bool		castShadows;
	bool		receiveShadows;
	eType		type;

public:
	virtual ~CRenderObject();

	CRenderObject(const eType& iType, const CMatterial& iMatterial, const bool& iCastShadows, const bool& iReceiveShadows);
	CRenderObject& operator=(const CRenderObject& iRenderObject);

	CMatterial			Matterial()				const	{ return matterial; }
	bool				CastShadows()			const	{ return castShadows; }
	bool				ReceiveShadows()		const	{ return receiveShadows; }
	bool				TransparencyEnabled()	const;
	eMatterialType		MatterialType()			const	{ return matterial.MatterialType(); }
	unsigned			MatterialID()			const	{ return matterial.MatterialID(); }
	eRenderInstanceType RenderInstanceType()	const	{ return matterial.RenderInstanceType(); }
	eType				Type()					const	{ return type; }

	
};

}

#endif 