/*
    Functions_UI.h - Contains variuos UI functions.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/

#ifndef REGINA_UI_FUNCTIONS_UI_H
#define REGINA_UI_FUNCTIONS_UI_H

#include <d3dx9.h>

namespace Regina
{

namespace UI
{

static D3DXVECTOR2 TransformToUIScreenSpace(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution, const D3DXVECTOR2& iPosition) 
	{
	D3DXVECTOR2 ret(0, 0);
	ret.x=iPosition.x/iOriginalScreenResolution.x*iScreenResolution.x;
	ret.y=iPosition.y/iOriginalScreenResolution.y*iScreenResolution.y;
	return ret;
	}

//******************************************************************************

static float TransformToUIScreenSpace(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution, const float& iPosition) 
	{
	D3DXVECTOR2 ret(0, 0);
	ret.x=iPosition/iOriginalScreenResolution.x*iScreenResolution.x;
	ret.y=iPosition/iOriginalScreenResolution.y*iScreenResolution.y;
	return min(ret.x, ret.y);
	}

//******************************************************************************

static D3DXVECTOR2 TransformToUIScreenSpaceInverse(const D3DXVECTOR2& iOriginalScreenResolution, const D3DXVECTOR2& iScreenResolution, const D3DXVECTOR2& iPosition) 
	{
	D3DXVECTOR2 ret(0, 0);
	ret.x=iOriginalScreenResolution.x*iPosition.x/iScreenResolution.x;
	ret.y=iOriginalScreenResolution.y*iPosition.y/iScreenResolution.y;
	return ret;
	}

//******************************************************************************

static D3DXVECTOR2 Cursor_Position(HWND iHWnd)
	{
	D3DXVECTOR2 cursorPos;
	POINT ptCursor;
	GetCursorPos(&ptCursor);
	ScreenToClient(iHWnd, &ptCursor); 
	cursorPos.x=ptCursor.x;
	cursorPos.y = ptCursor.y;

	return cursorPos;
	}

//******************************************************************************

static D3DXMATRIX UIImageTransformation(const D3DXVECTOR2& iObjectPosition, const D3DXVECTOR2& iObjectScale, const float& iObjectRotation, const D3DXVECTOR2& iScreenScale)
	{
	D3DXMATRIX transformation;
	D3DXMATRIX tTransform1;
		
	D3DXMatrixScaling(&transformation, iObjectScale.x, iObjectScale.y, 1);
	D3DXMatrixRotationZ(&tTransform1, iObjectRotation);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	D3DXMatrixScaling(&tTransform1, iScreenScale.x, iScreenScale.y, 1);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	D3DXMatrixTranslation(&tTransform1, iObjectPosition.x, iObjectPosition.y, 0);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	return transformation;
	}

//******************************************************************************

static D3DXMATRIX UIImageTransformationInverse(const D3DXVECTOR2& iObjectPosition, const D3DXVECTOR2& iObjectScale, const float& iObjectRotation, const D3DXVECTOR2& iScreenScale)
	{
	D3DXMATRIX transformation;
	D3DXMATRIX tTransform1;
		
	D3DXMatrixScaling(&transformation, iObjectScale.x, iObjectScale.y, 1);
	D3DXMatrixRotationZ(&tTransform1, iObjectRotation);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	D3DXMatrixScaling(&tTransform1, iScreenScale.x, iScreenScale.y, 1);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	D3DXMatrixTranslation(&tTransform1, iObjectPosition.x, iObjectPosition.y, 0);
	D3DXMatrixMultiply(&transformation, &transformation, &tTransform1);

	D3DXMatrixInverse(&transformation, NULL, &transformation);

	return transformation;
	}

//******************************************************************************

static float UIScaleFont(const float& iFontSize, const D3DXVECTOR2& iScale) 
	{
	const D3DXVECTOR2 scaledFont = iScale * iFontSize;
	return max(min(scaledFont.x, scaledFont.y), 2);
	}

//******************************************************************************

}

}

#endif