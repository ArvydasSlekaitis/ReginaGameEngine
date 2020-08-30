/*
    CGlobalScene.cpp - Contains class CGlobalScene implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CGlobalScene.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Destructor.
 */
CGlobalScene::~CGlobalScene()
	{
	created = false;
	}

//*****************************************************************************

/**
 * Returns pointer to ui render manager.
 */
CGlobalScene* CGlobalScene::Instance()
	{
	if(created == false)
		return NULL;

	static CGlobalScene manager;
	return &manager;
	}

//*****************************************************************************

bool CGlobalScene::created(true);

//*****************************************************************************