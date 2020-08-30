/*
    CExpressionEvolutor_Int.cpp - Contains class CExpressionEvolutor_Int implementation.
	Copyright 2004-2010 Arvydas Šlekaitis. All Rights Reserved.
*/


#include <CExpressionEvolutor_Int.h>
using namespace Regina::Script;

//*****************************************************************************

void CExpressionEvolutor_Int::Evolute(int*& oFinalPointer, vector<CScriptAction*>& oScriptAction, vector<int*>& oTempVariable)
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
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing left argument for int multiplication.");
			
			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing right argument for int multiplication.");

			int* tmpVar = new int;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Multiply<int, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Multiply<int, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Multiply<int, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Multiply<int, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


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
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing left argument for int division.");
			
			if(GetRightArgumentPosition(workingRange_begin, workingRange_end, signPosition, rightVariablePosition) == false)
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing right argument for int division.");

			int* tmpVar = new int;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Divide<int, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Divide<int, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Divide<int, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Divide<int, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


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
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing right argument for int sum.");

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				{
				delete expressionEntity[signPosition];
				expressionEntity[signPosition] = NULL;
				continue;
				}

			int* tmpVar = new int;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<int, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<int, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Sum<int, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Sum<int, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


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
				throw CException_ScriptError_SyntaxError("CExpressionEvolutor_Int::Evolute", "Missing right argument for int minus.");

			if(GetLeftArgumentPosition(workingRange_begin, workingRange_end, signPosition, leftVariablePosition) == false)
				{
				int* tmpVar = new int;
				int* tmpVar2 = new int(-1);

				if(expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
					oScriptAction.push_back(new TScriptAction_Multiply<int, int, int>(tmpVar, expressionEntity[rightVariablePosition]->GetPointerToInt(), tmpVar2));

				if(expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
					oScriptAction.push_back(new TScriptAction_Multiply<int, float, int>(tmpVar, expressionEntity[rightVariablePosition]->GetPointerToFloat(), tmpVar2));

				oTempVariable.push_back(tmpVar);
				oTempVariable.push_back(tmpVar2);

				delete expressionEntity[rightVariablePosition];
				expressionEntity[rightVariablePosition] = NULL;

				delete expressionEntity[signPosition];
				expressionEntity[signPosition] = new CExpressionEntity(tmpVar);

				continue;
				}	

			int* tmpVar = new int;
	
			//Int Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Minus<int, int, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Int Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eInt && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Minus<int, int, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToInt(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));

			//Float Int
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eInt)
				oScriptAction.push_back(new TScriptAction_Minus<int, float, int>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToInt()));

			//Float Float
			if(expressionEntity[leftVariablePosition]->SubType() == CExpressionEntity::eFloat && expressionEntity[rightVariablePosition]->SubType() == CExpressionEntity::eFloat)
				oScriptAction.push_back(new TScriptAction_Minus<int, float, float>(tmpVar, expressionEntity[leftVariablePosition]->GetPointerToFloat(), expressionEntity[rightVariablePosition]->GetPointerToFloat()));


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

	if(expressionEntity[finalPointerPosition]->SubType() == CExpressionEntity::eFloat)
		{
		int* tmpVar = new int;
		oScriptAction.push_back(new TScriptAction_Set<int, float>(tmpVar, expressionEntity[finalPointerPosition]->GetPointerToFloat()));
		oTempVariable.push_back(tmpVar);
		oFinalPointer = tmpVar;
		}
	else
		oFinalPointer = expressionEntity[finalPointerPosition]->GetPointerToInt();
	}

//*****************************************************************************