/*
    CGlobalScene.h - Contains class CGlobalScene.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/

#ifndef REGINA_CGLOBALSCENE_H
#define REGINA_CGLOBALSCENE_H

#include <CScene.h>

namespace Regina
{

namespace Scene
{

/**
 * This is a global version of Scene class.
 */
class CGlobalScene : public CScene
{
private:
	/**
	 * Object lifecycle information.
	 */
	static bool created;

	/**
	 * Private constructor.
	 */
	CGlobalScene()
		{
		}
	/**
	 * Private copy constructor.
	 */
	CGlobalScene(const CGlobalScene& prm1)
		{
		}
	/**
	 * Private assignment operator.
	 */
	CGlobalScene& operator==(CGlobalScene& prm1)
		{
		return  *this;
		}

public:
	/**
	 * Destructor.
	 */
	~CGlobalScene();
	/**
	 * Returns pointer to ui render manager.
	 */
	static CGlobalScene* Instance();
	/**
	 * Initializes scene.
	 */
	void SetDevice(LPDIRECT3DDEVICE9 iDevice)
		{
		if(created == true) 
			CScene::SetDevice(iDevice); 
		}
};

}

}

#define GlobalScene CGlobalScene::Instance()

#endif 