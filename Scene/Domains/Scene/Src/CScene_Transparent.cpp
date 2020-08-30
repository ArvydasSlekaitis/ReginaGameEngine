/*
    CScene_Transparent.cpp - Contains class CScene_Transparent implementation.
	Copyright 2011 Arvydas Ðlekaitis. All Rights Reserved.
*/


#include <CScene_Transparent.h>
using namespace Regina::Scene;


//*****************************************************************************

/**
 * Constructor.
 */
CScene_Transparent::CScene_Transparent(LPDIRECT3DDEVICE9 iDevice) : device(NULL)
	{
	if(iDevice == NULL)
		throw CException_NullPointer("CScene_Transparent::CScene_Transparent(LPDIRECT3DDEVICE9 iDevice)", "iDevice");

	device = iDevice;
	device->AddRef();
	}

//*****************************************************************************

/**
 * Destructor.
 */
CScene_Transparent::~CScene_Transparent()
	{
	for(unsigned i=0; i<loadedInstance.size(); i++)
		if(loadedInstance[i].first!=NULL)
			{
			delete loadedInstance[i].first;
			loadedInstance[i].first = NULL;
			}
	loadedInstance.clear();

	renderList.clear();

	if(device!=NULL)
		device->Release();
	device = NULL;
	}

//*****************************************************************************

/**
 * Returns available instance.
 */
CRenderInstance_StaticMesh* CScene_Transparent::GetAvailableInstance(CRenderObject_StaticMesh* iRenderObject)
	{
	for(unsigned i=0; i<loadedInstance.size(); i++)
		if(loadedInstance[i].second == true) 
			if(loadedInstance[i].first->CanBeInserted(iRenderObject) == true)
				{
				loadedInstance[i].second = false;
				return loadedInstance[i].first;
				}

	CRenderInstance_StaticMesh* instance = new CRenderInstance_StaticMesh(device, iRenderObject->GetMaterial()->GetMaterialType(), iRenderObject->GetMesh(), iRenderObject->GetMaterial()->GetInstanceVertexElement(), iRenderObject->GetMaterial()->GetInstanceDataSize(), iRenderObject->GetMaterial()->GetEffectFilename());
	loadedInstance.push_back(make_pair(instance, false));
	return  instance;
	}

//*****************************************************************************

/**
 * Renders transparent objects in sorted order.
 */
void CScene_Transparent::Render(const D3DXVECTOR3& iCameraPosition, const D3DXVECTOR3& iCameraDirection, const float& iRenderDistance)
	{
	vector<CRenderObject_StaticMesh*> tempRenderList(renderList);
	
	//Sort render list
	vector<CRenderObject_StaticMesh*> renderList_Sorted;

	while(tempRenderList.size()>0)
		{
		const unsigned tempRenderListSize(tempRenderList.size());

		float farthesSq = 0;
		unsigned farthesI = tempRenderListSize+1;

		
		for(unsigned i=0; i<tempRenderListSize; i++)
			{
			const D3DXVECTOR3 direction = tempRenderList[i]->GetPosition() - iCameraPosition;
			float distanceSq = D3DXVec3LengthSq(&(direction)) + tempRenderList[i]->GetRadius()*tempRenderList[i]->GetRadius();

			if(distanceSq >= farthesSq)
				{
				farthesSq = distanceSq;
				farthesI = i;
				}
			}
		if(farthesI>=tempRenderListSize+1)
			break;

		renderList_Sorted.push_back(tempRenderList[farthesI]);
		tempRenderList[farthesI] = tempRenderList[tempRenderList.size()-1];
		tempRenderList.pop_back();
		}

	
	//Now lets create render instances
	vector<CRenderInstance_StaticMesh*> renderInstance;

	for(unsigned i=0; i<renderList_Sorted.size(); i++)
		{
		if(renderInstance.size() == 0)
			{
			//Create new render instance
			CRenderInstance_StaticMesh* instance = GetAvailableInstance(renderList_Sorted[i]);
			renderInstance.push_back(instance);
			}
		else
			if(renderInstance[renderInstance.size()-1]->CanBeInserted(renderList_Sorted[i]) == false)
				{
				//Create new render instance
				CRenderInstance_StaticMesh* instance = GetAvailableInstance(renderList_Sorted[i]);
				renderInstance.push_back(instance);
				}

		renderInstance[renderInstance.size()-1]->AddRenderObject(renderList_Sorted[i]);
		}


	//Render all instances
	for(unsigned i=0; i<renderInstance.size(); i++)
		{
		renderInstance[i]->Render();
		renderInstance[i]->Clear();
		}	

	//Reset loaded inctances
	for(unsigned i=0; i<loadedInstance.size(); i++)
		loadedInstance[i].second=true;
	}

//*****************************************************************************

/**
 * Clears all render objects.
 */
void CScene_Transparent::Clear()
	{
	renderList.clear();
	}

//*****************************************************************************

/**
 * Clears static render objects.
 */
void CScene_Transparent::ClearStatic()
	{
	renderList.clear();
	}

//*****************************************************************************

/**
 * Clears dynamic render objects.
 */
void CScene_Transparent::ClearDynamic()
	{
	renderList.clear();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper lost device state.
 */
void CScene_Transparent::OnLostDevice()
	{
	const unsigned numLoadedInstances(loadedInstance.size());

	for(unsigned i=0; i<numLoadedInstances; i++)
		loadedInstance[i].first->OnLostDevice();
	}

//*****************************************************************************

/**
 * Performs all actions to ensure proper reset device state.
 */
void CScene_Transparent::OnResetDevice()
	{
	const unsigned numLoadedInstances(loadedInstance.size());

	for(unsigned i=0; i<numLoadedInstances; i++)
		loadedInstance[i].first->OnResetDevice();
	}

//*****************************************************************************

/**
 * Adds render object.
 */
void CScene_Transparent::AddRenderObject(CRenderObject_StaticMesh* iRenderObject)
	{
	renderList.push_back(iRenderObject);
	}

//*****************************************************************************