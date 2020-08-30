///////////////////////////////////////////////////////////
//  Threads.h
//  Created on:      22-05-2009
//  Last modified:   22-05-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef MISC_THREADS_H
#define MISC_THREADS_H

#include <windows.h>
#include <Group.h>

namespace Regina
{


//No return value, no arguments
template<class T1>
void WINAPI Thread_Pair(pair<T1*, void (T1::*)()>* iAdditionalInformation)
{
	((iAdditionalInformation->first)->*iAdditionalInformation->second)();
	delete iAdditionalInformation;
}

//No return value, no arguments
template<class T1>
HANDLE CreateThread(T1* iClass, void (T1::* iPointerToMember)() )
{
	return ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_Pair<T1>, new  pair<T1*, void (T1::*)()>(iClass, iPointerToMember), 0, 0);
}



//No return value, 1 argument
template<class T1, class T2>
void WINAPI Thread_Group_3(group_3<T1*, void (T1::*)(T2), T2>* iAdditionalInformation)
{
	((iAdditionalInformation->first)->*iAdditionalInformation->second)(iAdditionalInformation->third);
	delete iAdditionalInformation;
}


//No return value, 1 argument
template<class T1, class T2>
HANDLE CreateThread(T1* iClass, void (T1::* iPointerToMember)(T2), T2 iFirstArgument )
{
return ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_Group_3<T1, T2>, new  group_3<T1*, void (T1::*)(T2), T2>(iClass, iPointerToMember, iFirstArgument), 0, 0);
}

//No return value, 2 argument
template<class T1, class T2, class T3>
void WINAPI Thread_Group_4(group_4<T1*, void (T1::*)(T2, T3), T2, T3>* iAdditionalInformation)
{
	((iAdditionalInformation->first)->*iAdditionalInformation->second)(iAdditionalInformation->third, iAdditionalInformation->fourth);
	delete iAdditionalInformation;
}

//No return value, 2 argument
template<class T1, class T2, class T3>
HANDLE CreateThread(T1* iClass, void (T1::* iPointerToMember)(T2, T3), T2 iFirstArgument, T3 iSecondArgument )
{
	return ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread_Group_4<T1, T2, T3>, new  group_4<T1*, void (T1::*)(T2, T3), T2, T3>(iClass, iPointerToMember, iFirstArgument, iSecondArgument), 0, 0);
}




}


#endif