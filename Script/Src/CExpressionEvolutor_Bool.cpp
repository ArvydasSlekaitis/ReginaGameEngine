/*
    CExpressionEvolutor_Bool.cpp - Contains class CExpressionEvolutor_Bool implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEvolutor_Bool.h>
using namespace Regina::Script;

//*****************************************************************************

void CExpressionEvolutor_Bool::Evolute(bool*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<bool*>& oTempVariable)
	{
	if(NumActions() == 0)
			return;

	#pragma warning( push )
	#pragma warning( disable : 4127 )
	while(true)
	#pragma warning( pop )
		{
		unsigned workingRange_begin(0);
		unsigned workingRange_end(0);

		if(NumActions() <= 1)
			break;

		if(FindWorkingRange(workingRange_begin, workingRange_end) == false)
			break;

		//Remove (
		if(expressionEntity[workingRange_begin]!=NULL)
			if(expressionEntity[workingRange_begin]->Type() == CExpressionEntity::eParenthesis)
				{
				delete expressionEntity[workingRange_begin];
				expressionEntity[workingRange_begin] = NULL;
				}

		//Remove )
		if(workingRange_end < expressionEntity.size())
		if(expressionEntity[workingRange_end]!=NULL)
			if(expressionEntity[workingRange_end]->Type() == CExpressionEntity::eParenthesis)
				{
				delete expressionEntity[workingRange_end];
				expressionEntity[workingRange_end] = NULL;
				}

		unsigned signPosition(0);

		while(FindFirst_Multiply(workingRange_begin, workingRange_end, signPosition) == true)
			{
			unsigned leftVariablePosition(0);
			unsigned rightVariablePosition(0);

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Bool::Evolute", "Missing left argument for boolean multiplication.");

			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Bool::Evolute", "Missing right argument for boolean multiplication.");

			bool* tmpVar = new bool;
			oScriptAction.push_back(new TScriptAction_Multiply<bool, bool, bool>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToBool(), expressionEntity[rightVariablePosition]->GetPointerToBool()));
			oTempVariable.push_back(tmpVar);

			delete expressionEntity[leftVariablePosition];
			expressionEntity[leftVariablePosition] = NULL;
			delete expressionEntity[rightVariablePosition];
			expressionEntity[rightVariablePosition] = NULL;

			delete expressionEntity[signPosition];
			expressionEntity[signPosition] = new CExpressionEntity(tmpVar);
			}
		}

	unsigned finalPointerPosition(0);
	if(GetRightArgumentPosition(0, expressionEntity.size()-1, 0, finalPointerPosition) == false)
		return;

	oFinalPointer = expressionEntity[finalPointerPosition]->GetPointerToBool();
	}

//*****************************************************************************