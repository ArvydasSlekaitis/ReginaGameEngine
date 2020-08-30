/*
    CExpressionEvolutor_String.cpp - Contains class CExpressionEvolutor_String implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEvolutor_String.h>
using namespace Regina::Script;

//*****************************************************************************

void CExpressionEvolutor_String::Evolute(wstring*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<wstring*>& oTempVariable)
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

		while(FindFirst_Plus(workingRange_begin, workingRange_end, signPosition) == true)
			{
			unsigned leftVariablePosition(0);
			unsigned rightVariablePosition(0);

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_String::Evolute", "Missing left argument for string sum.");
			
			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_String::Evolute", "Missing right argument for string sum.");

			wstring* tmpVar = new wstring;

			//Bool Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eBool && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, bool, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToBool(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Bool Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eBool && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, bool, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToBool(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Bool Bool
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eBool && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eBool)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, bool, bool>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToBool(), expressionEntity[rightVariablePosition]->GetPointerToBool()));

			//Bool string
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eBool && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eString)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, bool, wstring>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToBool(), expressionEntity[rightVariablePosition]->GetPointerToString()));


			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Int Bool
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eBool)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, int, bool>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToBool()));

			//Int string
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eString)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, int, wstring>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToString()));


			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Bool
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eBool)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, float, bool>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToBool()));

			//Float string
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eString)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, float, wstring>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToString()));

			
			//String Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eString && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, wstring, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToString(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//String Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eString && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, wstring, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToString(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//String Bool
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eString && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eBool)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, wstring, bool>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToString(), expressionEntity[rightVariablePosition]->GetPointerToBool()));

			//String string
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eString && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eString)
				oScriptAction.push_back(new TScriptAction_Sum<wstring, wstring, wstring>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToString(), expressionEntity[rightVariablePosition]->GetPointerToString()));


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

	if(expressionEntity[finalPointerPosition]->SubType() == CExpressionEntity::eInt)
		{
		wstring* tmpVar = new wstring;
		oScriptAction.push_back(new TScriptAction_Set<wstring, int>(tmpVar, expressionEntity[finalPointerPosition]->GetPointerToInt()));
		oTempVariable.push_back(tmpVar);
		oFinalPointer = tmpVar;
		return;
		}
	else
	if(expressionEntity[finalPointerPosition]->SubType() == CExpressionEntity::eBool)
		{
		wstring* tmpVar = new wstring;
		oScriptAction.push_back(new TScriptAction_Set<wstring, bool>(tmpVar, expressionEntity[finalPointerPosition]->GetPointerToBool()));
		oTempVariable.push_back(tmpVar);
		oFinalPointer = tmpVar;
		return;
		}
	else
	if(expressionEntity[finalPointerPosition]->SubType() == CExpressionEntity::eFloat)
		{
		wstring* tmpVar = new wstring;
		oScriptAction.push_back(new TScriptAction_Set<wstring, float>(tmpVar, expressionEntity[finalPointerPosition]->GetPointerToFloat()));
		oTempVariable.push_back(tmpVar);
		oFinalPointer = tmpVar;
		return;
		}
	else
		oFinalPointer = expressionEntity[finalPointerPosition]->GetPointerToString();

	}

//*****************************************************************************