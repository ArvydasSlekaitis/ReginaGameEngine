/*
    CExpressionEvolutor_Float.cpp - Contains class CExpressionEvolutor_Float implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEvolutor_Float.h>
using namespace Regina::Script;

//*****************************************************************************

void CExpressionEvolutor_Float::Evolute(float*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<float*>& oTempVariable)
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
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing left argument for float multiplication.");
			
			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing right argument for float multiplication.");


			float* tmpVar = new float;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Multiply<float, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Multiply<float, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Multiply<float, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Multiply<float, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


			oTempVariable.push_back(tmpVar);

			delete expressionEntity[leftVariablePosition];
			expressionEntity[leftVariablePosition] = NULL;
			delete expressionEntity[rightVariablePosition];
			expressionEntity[rightVariablePosition] = NULL;

			delete expressionEntity[signPosition];
			expressionEntity[signPosition] = new CExpressionEntity(tmpVar);
			}


		while(FindFirst_Divide(workingRange_begin, workingRange_end, signPosition) == true)
			{
			unsigned leftVariablePosition(0);
			unsigned rightVariablePosition(0);

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing left argument for float division.");
			
			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing right argument for float division.");
			
			float* tmpVar = new float;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Divide<float, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Divide<float, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Divide<float, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Divide<float, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


			oTempVariable.push_back(tmpVar);

			delete expressionEntity[leftVariablePosition];
			expressionEntity[leftVariablePosition] = NULL;
			delete expressionEntity[rightVariablePosition];
			expressionEntity[rightVariablePosition] = NULL;

			delete expressionEntity[signPosition];
			expressionEntity[signPosition] = new CExpressionEntity(tmpVar);
			}


		while(FindFirst_Plus(workingRange_begin, workingRange_end, signPosition) == true)
			{
			unsigned leftVariablePosition(0);
			unsigned rightVariablePosition(0);

			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing right argument for float sum.");

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				{
				delete expressionEntity[signPosition];
				expressionEntity[signPosition] = NULL;
				continue;
				}
			
			float* tmpVar = new float;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<float, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<float, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<float, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<float, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


			oTempVariable.push_back(tmpVar);

			delete expressionEntity[leftVariablePosition];
			expressionEntity[leftVariablePosition] = NULL;
			delete expressionEntity[rightVariablePosition];
			expressionEntity[rightVariablePosition] = NULL;

			delete expressionEntity[signPosition];
			expressionEntity[signPosition] = new CExpressionEntity(tmpVar);
			}

		while(FindFirst_Minus(workingRange_begin, workingRange_end, signPosition) == true)
			{
			unsigned leftVariablePosition(0);
			unsigned rightVariablePosition(0);

			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Float::Evolute", "Missing right argument for float minus.");

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				{
				float* tmpVar = new float;
				float* tmpVar2 = new float(-1);

				if(expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
					oScriptAction.push_back(new TScriptAction_Multiply<float, int, float>(tmpVar, expressionEntity[rightVariablePosition]->GetPointerToInt(), tmpVar2));

				if(expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
					oScriptAction.push_back(new TScriptAction_Multiply<float, float, float>(tmpVar, expressionEntity[rightVariablePosition]->GetPointerToFloat(), tmpVar2));


				oTempVariable.push_back(tmpVar);
				oTempVariable.push_back(tmpVar2);

				delete expressionEntity[rightVariablePosition];
				expressionEntity[rightVariablePosition] = NULL;

				delete expressionEntity[signPosition];
				expressionEntity[signPosition] = new CExpressionEntity(tmpVar);

				continue;
				}	
	
			float* tmpVar = new float;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Minus<float, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Minus<float, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Minus<float, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Minus<float, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


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
		float* tmpVar = new float;
		oScriptAction.push_back(new TScriptAction_Set<float, int>(tmpVar, expressionEntity[finalPointerPosition]->GetPointerToInt()));
		oTempVariable.push_back(tmpVar);
		oFinalPointer = tmpVar;
		}
	else
		oFinalPointer = expressionEntity[finalPointerPosition]->GetPointerToFloat();
	}

//*****************************************************************************